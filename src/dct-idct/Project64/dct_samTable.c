#include "dct.h"

void sampleDCT(double * sample, double * result)
{
	int i, j, Bx, By;

	double arrSam[8][8] = {
		{162, 162, 162, 161, 162, 156, 163, 160},
	{162, 162, 162, 161, 162, 156, 163, 160},
	{162, 162, 162, 161, 162, 156, 163, 160},
	{162, 162, 162, 161, 162, 156, 163, 160},
	{162, 162, 162, 161, 162, 156, 163, 160},
	{164, 164, 157, 155, 161, 159, 158, 159},
	{160, 160, 163, 158, 160, 161, 159, 155},
	{158, 158, 155, 155, 158, 158, 156, 157}
	};

	for (By = 0; By < HEIGHT / N; By++)
		for (Bx = 0; Bx < WIDTH / N; Bx++) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					*(result + (Bx * N) + (By * N * WIDTH) + i * WIDTH + j) =
						(round((*(sample + (Bx * N) + (By * N * WIDTH) + i * WIDTH + j)) / arrSam[i][j])) * arrSam[i][j];

	/*
	double *arrSam = (double*)malloc(sizeof(double) * 8 * 8);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			*(arrSam + 8 * i + j) = arrSam[i][j];
		}
	}
	*//*
	for (By = 0; By < N / N; By++)
		for (Bx = 0; Bx < N / N; Bx++) {
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
					*(output + u * WIDTH + v) = (c_u * c_v) / (sqrt(N * N) / 2) * sum;	
					*/
				}
			}
		}
}

		

