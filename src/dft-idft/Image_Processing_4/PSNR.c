#include "buffer.h"

void PSNR(Img_Buf *img)
{
	Int i, j;
	Double mse = 0, psnr = 0, max = 0, sum=0;
	UChar Img1 = 0, Img2 = 0;

	for (i = 0; i < img->info.height; i++)
	{
		for (j = 0; j < img->info.width; j++)
		{
			Img1 = img->Ori_pix[i * img->info.width + j];
			Img2 = img->Re_pix [i * img->info.width + j];
			
			sum += pow(abs(Img1 - Img2), 2);

			if (max < Img1)
				max = Img1;
		}
	}

	mse = sum / (HEIGHT*WIDTH);
	printf("MSE : %lf\n", mse);

	psnr = 10 * log10(max * max / mse);
	//psnr = 10 * log10(255 * 255 / mse);
	printf("PSNR : %lf\n", psnr);

	if (mse == 0)
		printf("\n영상 일치\n");
	else
		printf("\n영상 불일치\n");
}