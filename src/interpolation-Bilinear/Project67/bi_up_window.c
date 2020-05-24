#include "bilinear.h"

void upscaling(unsigned char * input, unsigned char * output)
{
	int x, y;

	double org_size = 400;
	double new_size = 512;
	double ratio = new_size / org_size;

	//	새 이미지의 가로세로 크기
	int new_xMax = (int)(new_size * ratio);
	int new_yMax = (int)(new_size * ratio);

	for (y = 0; y < UP_SIZE; y++)
		for (x = 0; x < UP_SIZE; x++) {
			int new_x = (int)(x / ratio);
			int new_y = (int)(y / ratio);

			double x1pixel = (double)x / (double)ratio - (double)new_x;
			double x2pixel = 1 - x1pixel;
			double y1pixel = (double)y / (double)ratio - (double)new_y;
			double y2pixel = 1 - y1pixel;

			double w1 = x2pixel * y2pixel;
			double w2 = x1pixel * y2pixel;
			double w3 = x2pixel * y1pixel;
			double w4 = x1pixel * y1pixel;

			unsigned char p1 = *(input + new_y * WIDTH + new_x);
			unsigned char p2 = *(input + new_y * WIDTH + new_x + 1);
			unsigned char p3 = *(input + new_y * WIDTH + 1 + new_x);
			unsigned char p4 = *(input + new_y * WIDTH + 1 + new_x + 1);

			*(output + y * UP_SIZE + x) = (unsigned char)(w1 * p1 + w2 * p2 + w3 * p3 + w4 * p4);

		}
}