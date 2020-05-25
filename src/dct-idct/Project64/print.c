#include "dct.h"

void print(double *input, unsigned char *output)
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			*(output + WIDTH * i + j) = (unsigned char)((abs(*(input + i * WIDTH + j))*10)) ;
		}
	}
}

void yprint(double * input, unsigned char * output)
{
	for (int i = 0; i < HEIGHT; i++) {
		*(output + i) = (unsigned char)(abs(*(input + i +WIDTH)) * 10);
	}
}