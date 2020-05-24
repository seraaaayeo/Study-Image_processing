#include "bilinear.h"

void print(double *input, unsigned char *output)
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			*(output + WIDTH * i + j) = (unsigned char)((round(*(input + i * WIDTH + j)) * 10));
		}
	}
}