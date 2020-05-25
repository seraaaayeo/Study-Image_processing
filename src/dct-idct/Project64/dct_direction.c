#include "dct.h"

void YDCT(unsigned char *input, double * output)
{
	int i, j, u, v;
	int Bx, By;
	double c_v, c_u, sum;

	for (By = 0; By < N; By++)
		for (Bx = 0; Bx < WIDTH / N; Bx++) {
			for (u = 0; u < N; u++) {
				if (u == 0)
					c_u = (1 / sqrt(2));
				else
					c_u = 1;
				for (v = 0; v < N; v++) {
					if (v == 0)
						c_v = (1 / sqrt(2));
					else
						c_v = 1;
					sum = 0;
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							sum +=
								cos((2 * i + 1) * u * pi / (2 * N)) * cos((2 * j + 1) * v * pi / (2 * N))*
								(*(input + (Bx * N) + (By * N * WIDTH) + i * WIDTH + j));
						}
					}
					*(output + (Bx * N) + (By * N * WIDTH) + u * WIDTH + v) = (c_u * c_v) / (sqrt(N * N) / 2) * sum;
				}
			}
		}
}
void XDCT(unsigned char *input, double * output)
{
	int i, j, u, v;
	int Bx, By;
	double c_v, c_u, sum;

	for (Bx = 0; Bx < N; Bx++) {
		for (By = 0; By < HEIGHT / N; By++)
		{
			for (u = 0; u < N; u++) {
				if (u == 0)
					c_u = (1 / sqrt(2));
				else
					c_u = 1;
				for (v = 0; v < N; v++) {
					if (v == 0)
						c_v = (1 / sqrt(2));
					else
						c_v = 1;
					sum = 0;
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							sum +=
								cos((2 * i + 1) * u * pi / (2 * N)) * cos((2 * j + 1) * v * pi / (2 * N))*
								(*(input + (Bx * N) + (By * N * WIDTH) + i * WIDTH + j));
						}
					}
					*(output + (Bx * N) + (By * N * WIDTH) + u * WIDTH + v) = (c_u * c_v) / (sqrt(N * N) / 2) * sum;
				}
			}
		}
	}
}

