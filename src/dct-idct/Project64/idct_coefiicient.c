#include "dct3.h"

void coeIDCT(double * input, unsigned char * output, int m)
{
	int i, j, u, v;
	int Bx, By;
	double c_u, c_v, sum, b_vector;
	int coeffi = (N / pow(2.0, m));

	for (Bx = 0; Bx < WIDTH / N; Bx++)
		for (By = 0; By < HEIGHT / N; By++) {
			for (j = 0; j < N; j++) {
				for (i = 0; i < N; i++) {
					sum = 0;
					for (u = 0; u < N; u++)
					//for (u = 0; u < (N / pow(2.0, coeffi)) - u; u++)
					{
						if (u == 0)
							c_u = 1 / sqrt(2);
						else
							c_u = 1;

						for (v = 0; v < coeffi-u-1; v++) {
							if (v == 0)
								c_v = 1 / sqrt(2);
							else
								c_v = 1;
							sum += (c_u * c_v) / ((sqrt(N*N)) / 2)*
								cos((2 * i + 1) * u * pi / (N * 2)) * cos((2 * j + 1) * v * pi / (N * 2)) *
								//cos((2 * ((N / pow(2.0, coeffi)) - i) + 1) * u * pi / (N * 2)) * cos((2 * j + 1) * v * pi / (N * 2)) *
								(*(input + (By * N) + (Bx * N * HEIGHT) + u + v * HEIGHT));
						}
					}
					sum = (unsigned char)sum;
					*(output + (By * N) + (Bx * N * HEIGHT) + i + j * HEIGHT) = sum;
				}
			}
		}
}
void dcIDCT(double * input, unsigned char * output)
{
	int i, j, u, v;
	int Bx, By;
	double c_u, c_v, sum, b_vector;

	for (Bx = 0; Bx < WIDTH / N; Bx++)
		for (By = 0; By < HEIGHT / N; By++) {
			for (j = 0; j < N; j++) {
				for (i = 0; i < N; i++) {
					sum = 0;
					for (u = 0; u < N; u++)
					{
						if (u == 0)
							c_u = 1 / sqrt(2);
						else
							c_u = 1;

						for (v = 0; v < N-(N-1)-u; v++) {
							if (v == 0)
								c_v = 1 / sqrt(2);
							else
								c_v = 1;
							sum += (c_u * c_v) / ((sqrt(N*N)) / 2)*
								cos((2 * i + 1) * u * pi / (N * 2)) * cos((2 * j + 1) * v * pi / (N * 2)) *
								(*(input + (By * N) + (Bx * N * HEIGHT) + u + v * HEIGHT));
						}
					}
					sum = (unsigned char)sum;
					*(output + (By * N) + (Bx * N * HEIGHT) + i + j * HEIGHT) = sum;
				}
			}
		}
 }