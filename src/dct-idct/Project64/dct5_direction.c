#include "dct3.h"

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
	/*
	for (u = 0; u < WIDTH; u++) {
		if (u == 0)
			c_u = (1 / sqrt(2));
		else
			c_u = 1;
		sum = 0;
		for (i = 0; i < WIDTH; i++) {
			sum +=
				cos((2 * i + 1) * u * pi / (2 * N)) *
				(*(input + i));
		}
	}
	*(output + u) = (c_u) / (sqrt(N) / 2) * sum;
}

void XDCT(unsigned char *input, double * output)		///���ι��� dct
{
	int j, v;
	double c_v, sum;
	for (v = 0; v < HEIGHT; v++) {
		if (v == 0)
			c_v = (1 / sqrt(2));
		else
			c_v = 1;
		sum = 0;
		for (j = 0; j< HEIGHT; j++) {
			sum +=
				cos((2 * j + 1) * v * pi / (2 * N)) *
				(*(input + j));
		}
	}
	*(output + v) = (c_v) / (sqrt(N) / 2) * sum;
}
*/
/*
void YDCT(unsigned char *input, double * output)
{
	int i, u;
	int j, v;
	int By;
	int Bx;
	double sum;
	double c_u;
	double c_v;
			
	for (By = 0; By < HEIGHT / N; By++)
		for (Bx = 0; Bx < WIDTH / N; Bx++) 			
			for (u = 0; u < N; u++) {
				if (u == 0)
					c_u = (1 / sqrt(2));
				else
					c_u = 1;
				sum = 0;
				for (i = 0; i < WIDTH; i++) {
					sum += cos((2 * i + 1) * u * pi / (2 * N)) *
						(*(input + i * WIDTH + HEIGHT));
		
	*/

	/* ��ü �ȼ��� �����ϱ�
	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			MSE += (*(input + i * WIDTH + HEIGHT) - *(output + i * WIDTH + HEIGHT))* (*(input + i * WIDTH + HEIGHT) - *(output + i * WIDTH + HEIGHT));
	*/
	/*
	for (By = 0; By < HEIGHT / N; By++)
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
					for (i = 0; i < WIDTH; i++) {
						for (j = 0; j < HEIGHT; j++) {
							sum += cos((2 * i + 1) * u * pi / (2 * N)) * cos((2 * j + 1) * v * pi / (2 * N))*
								(*(input + (Bx * N) + (By * N * WIDTH) + i * WIDTH + HEIGHT));
						}
					}
					*(output + (Bx * N) + (By * N * WIDTH) + u * WIDTH + HEIGHT) = (c_u) / (sqrt(N * N) / 2) * sum;
				}
			}
		}*/
//}


	/*
	//for (By = 0; By < HEIGHT / N; By++)
		for (u = 0; u < HEIGHT; u++) {
			if (u == 0)
				c_u = (1 / sqrt(2));
			else
				c_u = 1;

			sum = 0;
			for (i = 0; i < HEIGHT; i++) {
				sum += cos((2 * i + 1) * u * pi / (2 * 1)) * (*(input + i + WIDTH ));
			}
			*(output + u +WIDTH ) = c_u / (sqrt(1) / 2) * sum;
		}
		*/

	



