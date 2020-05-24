#include"Bspline.h"

void spline(unsigned char * input, unsigned char * output)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	double tx, ty, dx, dy;
	double p1, p2, p3, p4;
	double v1, v2, v3, v4, v;

	double org_size = 512;
	double new_size = 1000;
	double ratio = new_size / org_size;
	double delta = org_size / new_size;

	unsigned char * temp;
	temp = (unsigned char*)malloc(sizeof(unsigned char)*UPSIZE*UPSIZE);


	for (int i = 0; i < UPSIZE; i++) {
		for (int j = 0; j < UPSIZE; j++) {
			//*(temp + i * UPSIZE + j) = *(input + i * WIDTH + j);
			
			//dy = i * delta;
			dx = j * delta;

			x2 = (int)(dx);		

			if (x2 == 0)
				x1 = 0;
			else
				x1 = x2 - 1;
			if (x2 == WIDTH - 1) {
				x3 = WIDTH - 1;
				x4 = WIDTH - 1;
			}
			else {
				x3 = x2 + 1;
				x4 = x2 + 2;
			}
			tx = dx - x2;

			p1 = *(input + i * WIDTH + x1);
			p2 = *(input + i * WIDTH + x2);
			p3 = *(input + i * WIDTH + x3);
			p4 = *(input + i * WIDTH + x4);

			v= findPoint(p1, p2, p3, p4, tx);

			*(output + i * UPSIZE + j) = (unsigned char)(v + 0.5);

		}
	}


}