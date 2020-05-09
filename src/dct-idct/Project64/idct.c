#include "dct3.h"

void IDCT(double * input, unsigned char * output)
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

						for (v = 0; v < N; v++) {
							if (v == 0)
								c_v = 1 / sqrt(2);
							else
								c_v = 1;
							sum += (c_u * c_v) / ((sqrt(N*N)) / 2)*
								cos((2 * i + 1) * u * pi / (N * 2)) * cos((2 * j + 1) * v * pi / (N * 2)) *
								(*(input + (By * N) + (Bx * N * HEIGHT) + u + v * HEIGHT));
								//(*(input + u + v * HEIGHT));

							/*
							for (int m = 0; m < N; m++) {
								b_vector = (c_v / 2)*(cos(2 * m + 1)*v*pi) / (2 * N);
								sum += b_vector; */
						}
					}
					//*(output + j) = *(input + j)*sum;
					sum = (unsigned char)sum;
					*(output + (By * N) + (Bx * N * HEIGHT) + i + j * HEIGHT) = sum;
				}
			}
		}
}
