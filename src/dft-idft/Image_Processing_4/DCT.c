#include "buffer.h"

void DCT(Img_Buf *img)
{
	FILE   *fp;
	Int    Blk_Row, Blk_COl;
	Int    i, j, k, l;
	Double Temp, Spec;
	Double *SpecTmp;
	UChar  *SpecTmpFinal;
	Int NNBlk = NNBlk_SIZE;

	fopen_s(&fp, "DCT_Spectrum_lena_512x512.raw", "wb");

	SpecTmp = (Double*)calloc(NNBlk*NNBlk, sizeof(Double));
	SpecTmpFinal = (UChar*)calloc(NNBlk*NNBlk, sizeof(UChar));

	for (Blk_COl = 0; Blk_COl < img->info.height / NNBlk; Blk_COl++)
	{
		for (Blk_Row = 0; Blk_Row < img->info.width / NNBlk; Blk_Row++)
		{
			memset(img->CurBlk, 0, sizeof(UChar)*NNBlk*NNBlk);

			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{
					img->CurBlk[i * NNBlk +j] = img->Ori_pix[(Blk_Row*NNBlk) + (Blk_COl*NNBlk * WIDTH) + i * WIDTH + j];
				}
			}

			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{
					Temp = 0;
					for (k = 0; k < NNBlk; k++)
					{
						for (l = 0; l < NNBlk; l++)
						{
							Temp += (double)img->CurBlk[k * NNBlk + l]
								* (double)(cos((2 * k + 1) * i * PI / 2 / NNBlk) * cos((2 * l + 1) * j * PI / 2 / NNBlk));
						}

					}
					// i=0이면 c(i)=1/sqrt(2), j=0이면 c(j)=1/sqrt(2)이므로 c(i)c(j)=1/2
					// 2/sqrt(NN) * 1/2 = 1/sqrt(NN) = 1/N
					if (i == 0 && j == 0)
						Spec = Temp / NNBlk; 
					else if (i == 0 || j == 0)
						Spec = (Temp * (1.0 / sqrt(2.0))) / (NNBlk / 2);
					else
						Spec = Temp / (NNBlk / 2);

					SpecTmp[i * NNBlk + j] = Spec;

				}
			}

			if (img->info.width == NNBlk && img->info.height == NNBlk) {
				for (i = 0; i < NNBlk; i++)
				{
					for (j = 0; j < NNBlk; j++)
					{
						img->Spectrum[(Blk_Row*NNBlk) + (Blk_COl*NNBlk * WIDTH) + i * WIDTH + j] = SpecTmp[i * NNBlk + j];
						SpecTmp[i * NNBlk + j] = SpecTmp[i * NNBlk + j] < 0 ? 0 : SpecTmp[i * NNBlk + j] > 255 ? 255 : SpecTmp[i * NNBlk + j];
						SpecTmpFinal[i * NNBlk + j] = (UChar)SpecTmp[i * NNBlk + j];
					}
				}
			}
			else { // 빼고싶으면 빼라한게 여긴가
				for (i = 0; i < NNBlk; i++)
				{
					for (j = 0; j < NNBlk; j++)
					{
						img->Spectrum[(Blk_Row*NNBlk) + (Blk_COl*NNBlk * WIDTH) + i * WIDTH + j] = SpecTmp[i * NNBlk + j];
					}
				}
			}

		}
	}

	fwrite(SpecTmpFinal, sizeof(UChar), NNBlk*NNBlk, fp);

	free(SpecTmp);
	free(SpecTmpFinal);

	fclose(fp);
}

void IDCT(Img_Buf *img)
{
	FILE   *fp;
	Int    Blk_Row, Blk_COl;
	Int    i, j, k, l;
	Double Temp, Recon;
	Double *OutTmp;
	Int NNBlk = NNBlk_SIZE;

	fopen_s(&fp, "DCT_ReconImg_lena_512x512.raw", "wb");

	OutTmp = (Double*)calloc(NNBlk*NNBlk, sizeof(Double));

	for (Blk_Row = 0; Blk_Row < (img->info.width + (img->info.width%NNBlk)) / NNBlk; Blk_Row++)
	{
		for (Blk_COl = 0; Blk_COl < (img->info.height + (img->info.height%NNBlk)) / NNBlk; Blk_COl++)
		{
			memset(img->Re_CurBlk, 0, sizeof(Double)*NNBlk*NNBlk);

			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{
					img->Re_CurBlk[i*NNBlk + j] = img->Spectrum[(Blk_Row*NNBlk) + (Blk_COl*NNBlk * WIDTH) + i * WIDTH + j];
				}
			}

			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{
					Recon = 0;
					for (k = 0; k < NNBlk; k++)
					{
						for (l = 0; l < NNBlk; l++)
						{
							Temp = img->Re_CurBlk[k*NNBlk + l]
								* (double)(cos((2 * i + 1)*k*PI / 2 / NNBlk)*cos((2 * j + 1)*l*PI / 2 / NNBlk));
							if (k == 0 && l == 0)
								Recon += Temp / NNBlk;
							else if (k == 0 || l == 0)
								Recon += (Temp * (1.0 / sqrt(2.0))) / (NNBlk / 2);
							else
								Recon += Temp / (NNBlk / 2);
						}
					}

					if (Recon < 0)
						Recon = (int)(Recon - 0.5);
					else
						Recon = (int)(Recon + 0.5);

					OutTmp[i * NNBlk + j] = Recon;
				}
			}

			for (i = 0; i < NNBlk; i++)
			{
				for (j = 0; j < NNBlk; j++)
				{
					img->Re_pix[(Blk_Row*NNBlk) + (Blk_COl*NNBlk * WIDTH) + i * WIDTH + j] = (UChar)OutTmp[i * NNBlk + j];
				}
			}
		}
	}

	fwrite(img->Re_pix, sizeof(UChar), img->info.width*img->info.height, fp);

	free(OutTmp);

	fclose(fp);
}
