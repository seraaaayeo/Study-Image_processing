#include"cc.h"
/*
void filter(unsigned char * input, unsigned char * output)
{
	int i, j, m, n;

	double *temp_in;
	double sum = 0;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));

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
*/
/*
void filter(unsigned char * input, unsigned char * output)
{
	int mask[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	//int mask[3][3] = { {1, 1, 1}, {1, 10, 1}, {1, 1, 1} };
	//int mask[3][3] = { {1, 2, 1}, {2, 4, 2}, {1, 2, 1} };
	
	int i, j, m, n, sum;
	double * temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
		}
	}
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (*(input + i * WIDTH + m + j + n)*mask[m][n]/9);

				}
			}
			*(output + i * WIDTH + j) = (unsigned char)(sum);
		}

	}
}
*/
/*
void filter(unsigned char * input, unsigned char * output)
{
	//int mask[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	//int mask[3][3] = { {1, 1, 1}, {1, 10, 1}, {1, 1, 1} };
	int mask[3][3] = { {1, 2, 1}, {2, 4, 2}, {1, 2, 1} };

	int i, j, m, n, sum;
	for (i = 1; i < HEIGHT - 1; i++) {
		for (j = 1; j < WIDTH - 1; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (*(input + i * WIDTH - 1 + m + j - 1 + n)*mask[m][n]);

				}
			}
			*(output + i * WIDTH + j) = (unsigned char)(sum/16+0.5);
		}

	}
}
*/

void filter(unsigned char * input, unsigned char * output)
{
	int i, j, m, n;

	double mask[5][5] = {	// 5ÅÇ LPF °è¼ö
	{0.00016384, -0.00015232, -0.01026304, -0.00015232, 0.00016384},
	{-0.00015232, 0.00014161, 0.00954142, 0.00014161, -0.00015232},
	{-0.01026304, 0.00954142, 0.64288324, 0.00954142, -0.01026304},
	{-0.00015232, 0.00014161, 0.00954142, 0.00014161, -0.00015232},
	{0.00016384, -0.00015232, -0.01026304, -0.00015232, 0.00016384}
	};


//	int mask[3][3] = { {1, 4, 1}, {4, 8000, 4}, {1, 4, 1} };	//8020

	double *temp_in;
	double sum = 0;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 4)*(WIDTH + 4));

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 2 + j + 2) = *(input + i * WIDTH + j);
		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH ; j++) {

			for (n = 0; n < 5; n++)
				for (m = 0; m < 5; m++)
					sum += (*(temp_in + i * WIDTH + n + j + m)*mask[m][n]);
			*(output + i * WIDTH + j) = (unsigned char)(sum / 0.64 + 0.5);

			sum = 0;
		}
	}
}

/*
int compare(const void * a, const void * b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return 1;
	else if (num1 < num2)
		return -1;
	else
		return 0;

}

void filter(unsigned char * input, unsigned char * output)
{
	int i, j;
	unsigned char m[9];

	double *temp_in;
	double sum = 0;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);

		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH ; j++) {
			m[0] = *(temp_in + i * WIDTH - 1 + j - 1);
			m[1] = *(temp_in + i * WIDTH + j - 1);
			m[2] = *(temp_in + i * WIDTH + 1 + j - 1);

			m[3] = *(temp_in + i * WIDTH - 1 + j);
			m[4] = *(temp_in + i * WIDTH + j);
			m[5] = *(temp_in + i * WIDTH + 1 + j);

			m[6] = *(temp_in + i * WIDTH - 1 + j + 1);
			m[7] = *(temp_in + i * WIDTH + j + 1);
			m[8] = *(temp_in + i * WIDTH + 1 + j + 1);

			qsort(m, sizeof(m)/sizeof(unsigned char), sizeof(unsigned char), compare);



			*(output + i * WIDTH -1 + j-1) = m[4];
		}
	}
}
*/
/*
#define lambda 0.25
#define k 4
#define iter 20

void filter(unsigned char * input, unsigned char * output)
{

}
*/