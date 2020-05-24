#include "snh.h"

void upwindow(unsigned char * input, unsigned char * output)
{
	int i, j, new_x, new_y, xtemp, ytemp;		//y방향 = i 방향, x방향 = j 방향 !!!!!
	double x, y;

	double org_size = 400;
	double new_size = 512;
	double delta = org_size / new_size;
	double ratio = new_size / org_size;
	printf("delta : %lf\n", delta);
	printf("scale rate : %lf\n", ratio);
	
	unsigned char * temp;
	temp = (unsigned char*)malloc(sizeof(unsigned char)*UP_SIZE*UP_SIZE);

	////	출력화면 키우기 시도중
	for (new_y = 0; new_y < UP_SIZE; new_y++) {
		for (new_x = 0; new_x < UP_SIZE; new_x++) {
			ytemp = (int)(floor(new_y / ratio));
			xtemp = (int)(floor(new_x / ratio));

			*(output + new_y * UP_SIZE + new_x) = *(input + ytemp * WIDTH + xtemp);
		}
	}
}
