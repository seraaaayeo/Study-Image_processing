#include "dct.h"

void psnr(unsigned char * input, unsigned char * output)
{
	/*	PSNR(X,Y)=10log((X_max)^2 / MSE(X,Y)
		X ���� ���� Y ó���� ���� X_max �ִ� ���� �ȼ� ��(�ִ��ȼ���-�ּ��ȼ���)
		MSE(Mean Square Error) ��� ���� ���� = (�����)ǥ������
		MSE = 1/N (i=0 ~ i=n-1)sum(Xi-Yi)^2						*/

	double PSNR;
	double sum=0, MSE=0;
	
	for (int m = 0; m < HEIGHT; m++) {
		for (int n = 0; n < WIDTH; n++) {
			sum += (*(input + m * WIDTH + n) - *(output + m * WIDTH + n))*(*(input + m * WIDTH + n) - *(output + m * WIDTH + n));
		}
	}
	MSE = sum / (HEIGHT*WIDTH);
	PSNR = 10 * log10(255 * 255 / MSE);		////unsigned char�� ���� 0~255�̹Ƿ� (255-0)*(255-0)
	printf("error rate: %lf\n", MSE);
	printf("PSNR : %lf\n", PSNR);
}
