#include "bilinear.h"

void psnr(unsigned char * input, unsigned char * output)
{
	double PSNR=0;
	double sum = 0, MSE = 0;

	for (int m = 0; m < HEIGHT; m++) {
		for (int n = 0; n < WIDTH; n++) {
			sum += (*(input + m * WIDTH + n) - *(output + m * WIDTH + n))*(*(input + m * WIDTH + n) - *(output + m * WIDTH + n));
		}
	}
	MSE = sum / (HEIGHT*WIDTH);
	PSNR = 10 * log10(255 * 255 / MSE);		////unsigned char의 범위 0~255이므로 (255-0)*(255-0)
	printf("deviation : %lf\n", MSE);
	printf("PSNR : %lf\n", PSNR);
}

