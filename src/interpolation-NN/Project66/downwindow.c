#include "snh.h"

void downwindow(unsigned char * input, unsigned char * output)
{
	int i, j, new_x, new_y, xtemp, ytemp;		//y방향 = i 방향, x방향 = j 방향 !!!!!
	double x, y;

	double org_size = 512;
	double new_size = 400;
	double delta = org_size / new_size;
	double ratio = new_size / org_size;
	printf("delta : %lf\n", delta);
	printf("scale rate : %lf\n", ratio);

	unsigned char * temp;
	temp = (unsigned char*)malloc(sizeof(unsigned char)*DOWN_SIZE*DOWN_SIZE);


	for (new_y = 0; new_y < DOWN_SIZE; new_y++) {
		for (new_x = 0; new_x < DOWN_SIZE; new_x++) {
			ytemp = (int)(floor(new_y / ratio));
			xtemp = (int)(floor(new_x / ratio));

/*			if (xtemp < 0 || xtemp>255 || ytemp < 0 || ytemp>255)
				*(temp + new_y * DOWN_SIZE + new_x) = 0;
			else*/
				*(temp + new_y * DOWN_SIZE + new_x) = *(input + ytemp * WIDTH + xtemp);
		}
	}
	for (i = 0; i < DOWN_SIZE; i++) {
		for (j = 0; j < DOWN_SIZE; j++) {
			*(output + i * WIDTH + j) = *(temp + i * DOWN_SIZE + j);		//윈도우 크기 고정
//			*(output + i * (DOWN_SIZE) + j) = *(temp + i * DOWN_SIZE + j);

		}
	}
}
	
	



