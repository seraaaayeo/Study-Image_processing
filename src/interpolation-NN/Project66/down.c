#include "snh.h"

void down(unsigned char * input, unsigned char * output)
{
	int i, j, new_x, new_y, xtemp, ytemp;		//y방향 = i 방향, x방향 = j 방향 !!!!!
	double x, y;

	double org_size = 512;
	double new_size = 298;
	double delta = org_size / new_size;
	double ratio = new_size / org_size;
	printf("delta : %lf\n", delta);
	printf("scale rate : %lf\n", ratio);

	//	새 이미지의 가로세로 크기
	int new_xMax = (int)(new_size * ratio);
	int new_yMax = (int)(new_size * ratio);

	unsigned char * temp;
	temp = (unsigned char*)malloc(sizeof(unsigned char)*new_xMax*new_yMax);

	for (new_y = 0; new_y < new_yMax; new_y++) {
		for (new_x = 0; new_x < new_xMax; new_x++) {
			ytemp = (int)(floor(new_y / ratio));
			xtemp = (int)(floor(new_x / ratio));

			*(temp + new_y * new_xMax + new_x) = *(input + ytemp * WIDTH + xtemp);
		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(output + i * WIDTH + j) = *(temp + i * new_xMax + j);
		}
	}
}


