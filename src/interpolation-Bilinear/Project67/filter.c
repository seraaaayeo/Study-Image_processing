#include "bilinear.h"

void filter(unsigned char * input, unsigned char * output)
{
	int i, j, m, n;

	double *temp_in, *temp_out;
	double sum = 0;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
//	temp_in = (double*)malloc(sizeof(double)*HEIGHT*WIDTH);
	
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
//			*(temp_in + i * WIDTH + j) = *(input + i * WIDTH + j);
			*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
		}
	}
	
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {

			for (n = 0; n < 3; n++)
				for (m = 0; m < 3; m++)
					sum += *(temp_in + i * WIDTH + n + j + m);
			*(output + i * WIDTH + j) = (unsigned char)(sum/9);
			sum = 0;
		}
	}
}

/*
void filter(unsigned char * input, unsigned char * output)
{
	int sum;
	int maskSize = 3;
//	int mask[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	int mask[3][3] = { {1, 1, 1}, {1, 10, 1}, {1, 1, 1} };
//	int mask[3][3] = { {1, 2, 1}, {2, 4, 2}, {1, 2, 1} };

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			sum = 0;
			for (int i = -1 * maskSize / 2; i <= maskSize / 2; i++) {
				for (int j = -1 * maskSize / 2; j <= maskSize / 2; j++) {

					//////	영상 범위를 벗어난 경우 사용할 엣지값 만들기(테두리 값을 mirroring)
					int edge_y = y + i;
					int edge_x = x + j;

					if (edge_y < 0)
						edge_y = 0;
					else if (edge_y > HEIGHT - 1)
						edge_y = HEIGHT - 1;

					if (edge_x < 0)
						edge_x = 0;
					else if (edge_x > WIDTH - 1)
						edge_x = WIDTH - 1;

					sum += *(input + edge_y * WIDTH + edge_x)*mask[(maskSize / 2) + i][(maskSize / 2) + j]/18;
				}
				//sum /= 2;
				//sum = sum / (maskSize*maskSize);

				/////clipping
				if (sum > 255)
					sum = 255;
				else if (sum < 0)
					sum = 0;

				*(output + WIDTH * y + x) = (unsigned char)(sum);
			}
		}
	}
}
*/

/*
void filter(unsigned char * input, unsigned char * output)
{
	int sum;
	int maskSize = 3;
	int mask[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			sum = 0;
			for (int i = -1 * (maskSize / 2 +1); i <= maskSize / 2 +1; i++) {
				for (int j = -1 * (maskSize / 2 +1); j <= maskSize / 2+ 1; j++) {

					//////	영상 범위를 벗어난 경우 사용할 엣지값 만들기(테두리 값을 mirroring)
					int edge_y = y + i;
					int edge_x = x + j;

					if (edge_y < 0)
						edge_y = 0;
					else if (edge_y > HEIGHT - 1)
						edge_y = HEIGHT - 1;

					if (edge_x < 0)
						edge_x = 0;
					else if (edge_x > WIDTH - 1)
						edge_x = WIDTH - 1;

					/// 컨볼루션 계산
					//sum += *(temp)*mask[maskSize / 2 + i][maskSize / 2 + j];
					sum += *(input + edge_y * WIDTH + edge_x)*mask[(maskSize / 2) + i][(maskSize / 2) + j];
				}
				sum = sum/9;
				//sum = sum / (maskSize*maskSize);

				/////clipping
				if (sum > 255)
					sum = 255;
				else if (sum < 0)
					sum = 0;

				*(output + WIDTH * y + x) = (unsigned char)(sum);
			}
		}
	}
}	
*/
/*
void filter(unsigned char * input, unsigned char * output)
{
	
	int mask[7][7] = {
	{0.00007569, 0, -0.00219066, -0.00447006, -0.00219066, 0, 0.00007569},
	{0, 0, 0, 0, 0, 0, 0},
	{-0.00219066, 0, 0.06340324, 0.12937484, 0.06340324, 0, -0.00219066},
	{-0.00447006, 0, 0.21937484, 0.26399044, 0.21937484, 0, -0.00447006},
	{-0.00219066, 0, 0.06340324, 0.12937484, 0.06340324, 0, -0.00219066},
	{0, 0, 0, 0, 0, 0, 0},
	{0.00007569, 0, -0.00219066, -0.00447006, -0.00219066, 0, 0.00007569}
	};
	
	
	int mask[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	//int mask[3][3] = { {1, 1, 1}, {1, 10, 1}, {1, 1, 1} };
	//int mask[3][3] = { {1, 2, 1}, {2, 4, 2}, {1, 2, 1} };
	
	int i, j, m, n, sum;
	for (i = 1; i < HEIGHT - 1; i++) {
		for (j = 1; j < WIDTH - 1; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (*(input + i * WIDTH - 1 + m + j - 1 + n)*mask[m][n]);

				}
			}
			*(output + i * WIDTH + j) = (unsigned char)(sum/9);
		}

	}
}
*/
/*
void filter(unsigned char * input, unsigned char * output)
{
	int mask[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	//int mask[3][3] = { {1, 1, 1}, {1, 10, 1}, {1, 1, 1} };
	//int mask[3][3] = { {1, 2, 1}, {2, 4, 2}, {1, 2, 1} };

	int i, j, m, n, sum;
	for (i = 1; i < HEIGHT - 1; i++) {
		for (j = 1; j < WIDTH - 1; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (*(input + i * WIDTH - 1 + m + j - 1 + n)*mask[m][n]);

				}
			}
			*(output + i * WIDTH + j) = (unsigned char)(sum / 9);
		}

	}
}
*/
