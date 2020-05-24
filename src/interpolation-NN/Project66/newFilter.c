#include "snh.h"

void newfilter(unsigned char * input, unsigned char * output)
{
	int i, j, m, n;

	double *temp_in, *temp_out;
	double sum = 0;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
	temp_out = (double*)malloc(sizeof(double)*HEIGHT*WIDTH);

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
		}
	}
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			for (n = 0; n < 3; n++)
				for (m = 0; m < 3; m++)
					sum += *(temp_in + i * WIDTH + n + j + m);
			*(output + i * WIDTH + j) = (unsigned char)(sum / 9);
			sum = 0;
		}
	}
}
