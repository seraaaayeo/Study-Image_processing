#include "Bspline.h"

void preEmphasis(unsigned char * input, unsigned char * output)
{
	int i, j, m, n;

	double mask[3][3] = {
		{0.21521996, -0.80335930, 0.21521996},
	{-0.80335930, 2.99872826, -0.80335930},
	{0.21521996, -0.80335930, 0.21521996} };
	
	double fmask[13][13] = {
	{0.0000004098, -0.0000015298, 0.0000057104, -0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153, 0.0000057104, -0.0000015298, 0.0000004098},
	{-0.0000015298, 0.0000057104, -0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.004138097, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153, 0.0000057104, -0.0000015298},
	{0.0000057104, -0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153, 0.0000057104},
	{-0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0576574262, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153},
	{0.0000795644, -0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0576574261, 0.2152199558, -0.0576574261, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929, 0.0000795644},
	{-0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0576574261, 0.2152199557, -0.8033592973, 0.2152199557, -0.0576574261, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929},
	{0.0011085962, -0.004138097, 0.0154464245, -0.0576574262, 0.2152199558, -0.8033592973, 2.9987282471, -0.8033592973, 0.2152199558, -0.0576574262, 0.0154464245, -0.004138097, 0.0011085962},
	{-0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0576574261, 0.2152199557, -0.8033592973, 0.2152199557, -0.0576574261, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929},
	{0.0000795644, -0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0576574261, 0.2152199558, -0.0576574261, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929, 0.0000795644},
	{-0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0576574262, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153},
	{0.0000057104, -0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.0041380971, 0.0154464245, -0.0041380971, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153, 0.0000057104},
	{-0.0000015298, 0.0000057104, -0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.004138097, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153, 0.0000057104, -0.0000015298},
	{0.0000004098, -0.0000015298, 0.0000057104, -0.0000213153, 0.0000795644, -0.0002969929, 0.0011085962, -0.0002969929, 0.0000795644, -0.0000213153, 0.0000057104, -0.0000015298, 0.0000004098},

	};
	



	double *temp_in;
	double sum = 0;
	unsigned char * temp_out;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 12)*(WIDTH + 12));

	//temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
	temp_out = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 6 + j + 6) = *(input + i * WIDTH + j);
			//*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);

		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {

			for (n = 0; n < 13; n++)
				for (m = 0; m < 13; m++)
					sum += (*(temp_in + i * WIDTH + n + j + m)*fmask[m][n]);
					//sum += (*(temp_in + i * WIDTH + n + j + m)*mask[m][n]);
			*(temp_out + i * WIDTH + j) = (unsigned char)(sum/800);
			//*(output + i * WIDTH + j) = (unsigned char)(sum / 7.0730453);
			*(output + i * WIDTH + j) = *(temp_out + i * WIDTH + j)+ (*(input + i * WIDTH + j));

			sum = 0;
		}
	}
}

void LPF(unsigned char * input, unsigned char * output)
{
	int i, j, m, n;
//	int mask[3][3] = { {1, 4, 1}, {4, 8000, 4}, {1, 4, 1} };	//8020
//	double mask[3][3] = { {0.00039601, 0.01910997, 0.00039601}, {0.01910997, 0.92217609, 0.01910997}, {0.00039601, 0.01910997, 0.00039601} };	//1.00020001
//	double mask[3][3] = { {0.00299209, 0.04872129, 0.00299209}, {0.04872129, 0.79334649, 0.04872129}, {0.00299209, 0.02872129, 0.00299209} }; //cutoff : (400/512)/4
	
	double mask[5][5] = {	// 5ÅÇ LPF °è¼ö
	{0.00016384, -0.00015232, -0.01026304, -0.00015232, 0.00016384},
	{-0.00015232, 0.00014161, 0.00954142, 0.00014161, -0.00015232},
	{-0.01026304, 0.00954142, 0.64288324, 0.00954142, -0.01026304},
	{-0.00015232, 0.00014161, 0.00954142, 0.00014161, -0.00015232},
	{0.00016384, -0.00015232, -0.01026304, -0.00015232, 0.00016384}
	};	

	double *temp_in;
	double sum = 0;

	//temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 4)*(WIDTH + 4));

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			//*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
			*(temp_in + i * WIDTH + 2 + j + 2) = *(input + i * WIDTH + j);

		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {

			for (n = 0; n < 5; n++)
				for (m = 0; m < 5; m++)
					sum += (*(temp_in + i * WIDTH + n + j + m)*mask[m][n]);
			*(output + i * WIDTH + j) = (unsigned char)(sum / 0.64 + 0.5);

			sum = 0;
		}
	}
}

void Highboost(unsigned char * input, unsigned char * output)
{
	int i, j, m, n;
	
	double mask[3][3] = {
		{-1, -1, -1},
	{-1, 8, -1},
	{-1, -1, -1} };

	double mask2[7][7] = {
		{-1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, 8, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1},

	};
	

	double *temp_in;
	double sum = 0;
	unsigned char * temp_out;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 6)*(WIDTH + 6));
//	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
	temp_out = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 3 + j + 3) = *(input + i * WIDTH + j);
			//*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {

			for (n = 0; n < 7; n++)
				for (m = 0; m < 7; m++)
					sum += (*(temp_in + i * WIDTH + n + j + m)*mask2[m][n]);
//			*(temp_out + i * WIDTH + j) = (unsigned char)(sum/16);
			*(temp_out + i * WIDTH + j) = (unsigned char)(sum / 56);

			//*(output + i * WIDTH + j) = (unsigned char)(sum / 7.0730453);
			*(output + i * WIDTH + j) = *(temp_out + i * WIDTH + j) + (*(input + i * WIDTH + j));

			sum = 0;
		}
	}
}

void High(unsigned char * input, unsigned char * output)
{
	/*
	int i, j, m, n;

	double *temp_in;
	double sum = 0;
	unsigned char * temp_out;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
	temp_out = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			sum += (4+1.33)*(*(temp_in + i * WIDTH + j)) 
				- *(temp_in + i * WIDTH - 1 + j) - *(temp_in + i * WIDTH + j - 1) - *(temp_in + i * WIDTH + 1 + j) - *(temp_in + i * WIDTH + j + 1);			
			*(output + i * WIDTH + j) = (unsigned char)(sum+0.5);

			//*(temp_out + i * WIDTH + j) = (unsigned char)(sum+0.5);
			//*(output + i * WIDTH + j) = *(temp_out + i * WIDTH + j) +(*(input + i * WIDTH + j));

			sum = 0;
		}
	}
	*/

	int i, j;
	double *temp_in;
	double sum = 0;
	unsigned char * temp_out;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
	temp_out = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			sum = (*(temp_in + i * WIDTH + j)*(0.46391805));
			if (sum > 255)
				sum = 255;
			else if(sum<0)
				sum=0;
			*(temp_out + i * WIDTH + j) = (unsigned char)(sum);
			*(output + i * WIDTH + j) = *(temp_out + i * WIDTH + j) + (*(input + i * WIDTH + j));
		}

	}

}
