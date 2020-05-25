#include "dct.h"

void psnr(unsigned char * input, unsigned char * output)
{
	/*	PSNR(X,Y)=10log((X_max)^2 / MSE(X,Y)
		X 원본 영상 Y 처리된 영상 X_max 최대 가능 픽셀 수(최대픽셀값-최소픽셀값)
		MSE(Mean Square Error) 평균 제곱 오차 = (통계학)표준편차
		MSE = 1/N (i=0 ~ i=n-1)sum(Xi-Yi)^2						*/

	double PSNR;
	double sum=0, MSE=0;
	
	for (int m = 0; m < HEIGHT; m++) {
		for (int n = 0; n < WIDTH; n++) {
			sum += (*(input + m * WIDTH + n) - *(output + m * WIDTH + n))*(*(input + m * WIDTH + n) - *(output + m * WIDTH + n));
		}
	}
	MSE = sum / (HEIGHT*WIDTH);
	PSNR = 10 * log10(255 * 255 / MSE);		////unsigned char의 범위 0~255이므로 (255-0)*(255-0)
	printf("error rate: %lf\n", MSE);
	printf("PSNR : %lf\n", PSNR);
}
