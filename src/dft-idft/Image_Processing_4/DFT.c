#include "buffer.h"

void DFT(Img_Buf *img)
{
	FILE   *fp;
	Int    Blk_Row, Blk_COl;
	Int    i, j, k, l;
	Double C, Temp, Spec;
	Double *SpecTmp;
	UChar  *Shuffling;
	
	Char   FilterFlag;

	Int NNBlk = NNBlk_SIZE;

	SpecTmp = (Double*)calloc(NNBlk*NNBlk, sizeof(Double));
	Shuffling = (UChar*)calloc(NNBlk*NNBlk, sizeof(UChar));

	if (NNBlk == img->info.width && NNBlk == img->info.height)
	{
		printf("LPF를 적용 하시겠습니까?(y or n)");
		scanf_s(" %c", &FilterFlag);
		system("cls");
	}

	// 8x8 block을 떼오는 과정
	for (Blk_COl = 0; Blk_COl < img->info.height / NNBlk; Blk_COl++)
	{
		for (Blk_Row = 0; Blk_Row < img->info.width  / NNBlk; Blk_Row++)
		{
			memset(img->CurBlk, 0, sizeof(UChar)*NNBlk*NNBlk);

			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{	
					img->CurBlk[i*NNBlk + j] = img->Ori_pix[(Blk_Row*NNBlk) + (Blk_COl*NNBlk * WIDTH) + i * WIDTH + j];
				}
			}

			for (i = 0; i < NNBlk; i++) // 변환된 세로
			{
				for (j = 0; j < NNBlk; j++) // 변환된 가로
				{
					for (k = 0; k < NNBlk; k++) // 원래 세로
					{
						for (l = 0; l < NNBlk; l++) // 원래 가로
						{
							// 해당되는 위치 , 해당되는 코사인 사인 수식
							//img->DFT_Real[j] += img->CurBlk[j]* cos(2 * PI * k * j / NNBlk); // 가로방향 DFT
							//img->DFT_Real[i] += img->CurBlk[i] * cos(2 * PI * l * i / NNBlk); // 세로방향 DFT
							img->DFT_Real[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i*img->info.width + j]
								+= img->CurBlk[k*NNBlk + l] * cos((2 * PI * l * j / NNBlk) + (2 * PI * k * i / NNBlk));
								//* (cos(2 * PI * l * i / NNBlk)* cos(2 * PI * k * j / NNBlk)); // 가로세로 DFT
							
							img->DFT_Imag[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i*img->info.width + j]
								-= img->CurBlk[k*NNBlk + l] * sin((2 * PI * l * j / NNBlk) + (2 * PI * k * i / NNBlk));
						}
					}
					// 블록의 크기로 나누기
					img->DFT_Real[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j] 
						= img->DFT_Real[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j] / (NNBlk*NNBlk);
					img->DFT_Imag[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j] 
						= img->DFT_Imag[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j] / (NNBlk*NNBlk);
				}
			}

			if (NNBlk == img->info.width && NNBlk == img->info.height && FilterFlag == 'y')
				LPF(img, Blk_Row, Blk_COl);

			// 얜 뭐야
			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{
					// 
					img->Magnitude[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j] 
						= sqrt(pow(img->DFT_Real[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j], 2) + pow(img->DFT_Imag[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j], 2));
					img->Phase[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j] 
						= atan2(img->DFT_Imag[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j], img->DFT_Real[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j]);
				}
			}

			// 주파수 스펙트럼
			if (NNBlk == img->info.width && NNBlk == img->info.height)
			{
				// C : 빗변 길이(hypot : 직각삼각형 빗변 길이 함수)
				C = hypot(img->DFT_Real[(Blk_Row*NNBlk) + (Blk_COl*(img->info.width + (img->info.width%NNBlk))*NNBlk)], img->DFT_Imag[(Blk_Row*NNBlk) + (Blk_COl*(img->info.width + (img->info.width%NNBlk))*NNBlk)]);
				for (i = 0; i < NNBlk; i++)
				{
					Spec = 0;
					for (j = 0; j < NNBlk; j++)
					{
						Temp = hypot(img->DFT_Real[(Blk_Row*NNBlk) + (Blk_COl*(img->info.width + (img->info.width%NNBlk))*NNBlk) + ((img->info.width + (img->info.width%NNBlk))*i) + j], img->DFT_Imag[(Blk_Row*NNBlk) + (Blk_COl*(img->info.width + (img->info.width%NNBlk))*NNBlk) + ((img->info.width + (img->info.width%NNBlk))*i) + j]);
						Spec = (C * log(1.0 + abs(Temp))) < 0.0 ? 0.0 : (C * log(1.0 + abs(Temp))) > 255.0 ? 255.0 : (C * log(1.0 + abs(Temp)));
						SpecTmp[i * NNBlk + j] = Spec;
					}
				}

				// 셔플링
				for (i = 0; i < NNBlk; i += (NNBlk / 2))
				{
					for (j = 0; j < NNBlk; j += (NNBlk / 2))
					{
						for (k = 0; k < (NNBlk / 2); k++)
						{
							for (l = 0; l < (NNBlk / 2); l++)
							{
								Shuffling[img->info.width*(k + i) + (l + j)] = (UChar)SpecTmp[img->info.width*(255 - k + i) + (255 - l + j)];
							}
						}
					}
				}
			}


		}
	}

	fopen_s(&fp, "DFT_Spectrum_lena_512x512.raw", "wb");
	if (NNBlk == img->info.width && NNBlk == img->info.height)
		fwrite(Shuffling, sizeof(UChar), NNBlk*NNBlk, fp);

	free(SpecTmp);
	free(Shuffling);

	fclose(fp);
}

void IDFT(Img_Buf *img)
{
	Int    Blk_Row, Blk_COl;
	Int    i, j, k, l;
	Double Recon_R;
	Int NNBlk = NNBlk_SIZE;

	for (Blk_COl = 0; Blk_COl < img->info.height / NNBlk; Blk_COl++)
	{
		for (Blk_Row = 0; Blk_Row < img->info.width / NNBlk; Blk_Row++)
		{
			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{
					// 8x8 block을 떼오는 과정?
					// 이건 뭘까 X(k) = a+ib = |X|[cos + isin] = magnitude[cos(phase) + isin(phase)] 이부분인가
					// a=mag*cos(phase), b=mag*sin(phase) -> a=IDFT_R, b=IDFT_I
					img->IDFT_Real[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j]
						= (img->Magnitude[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j]
							* cos(img->Phase[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j]));
					img->IDFT_Imag[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j]
						= (img->Magnitude[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j]
							* sin(img->Phase[(Blk_Row*NNBlk) + (Blk_COl * NNBlk * img->info.width) + i * img->info.width + j]));
				}
			}

			for (i = 0; i < NNBlk; i++) // 세로
			{
				for (j = 0; j < NNBlk; j++) // 가로
				{
					Recon_R = 0;
					for (k = 0; k < NNBlk; k++) // 세로
					{
						for (l = 0; l < NNBlk; l++) // 가로
						{
							// X(a,b)의 실수부 = IDFT_R(a,b), X(a,b)의 허수부 = IDFT_I
							//Recon_R += img->IDFT_Real[(Blk_Row*NNBlk)+(Blk_COl*NNBlk*WIDTH) + k*WIDTH + l] * cos((2*PI*k/ NNBlk) * i) 
								//- img->IDFT_Imag[(Blk_Row*NNBlk) + (Blk_COl*NNBlk*WIDTH) + k*WIDTH + l] * sin((2 * PI *l / NNBlk)* j);
							Recon_R += img->IDFT_Real[(Blk_Row*NNBlk) + (Blk_COl*NNBlk*WIDTH) + k * WIDTH + l] * cos((2 * PI*(l*j + k*i)/ NNBlk))
								- img->IDFT_Imag[(Blk_Row*NNBlk) + (Blk_COl*NNBlk*WIDTH) + k * WIDTH + l] * sin((2 * PI *(l*j + k * i) / NNBlk));
						}

					}

					if (Recon_R < 0) 
						Recon_R = (int)(Recon_R - 0.5);

					else 
						Recon_R = (int)(Recon_R + 0.5);

					img->Re_pix[(Blk_Row*NNBlk) + (Blk_COl*NNBlk * WIDTH) + i * WIDTH + j] = Recon_R < 0 ? 0 : Recon_R > 255 ? 255 : Recon_R;
				}
			}
		}
	}

	FILE   *fp;
	fopen_s(&fp, "DFT_ReconImg_lena_512x512.raw", "wb");
	fwrite(img->Re_pix, sizeof(UChar), img->info.width*img->info.height, fp);

	fclose(fp);
}
