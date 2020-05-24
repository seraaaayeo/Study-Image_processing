#include "snh.h"
/*
void filter(unsigned char * input, double * output)
{

}
*/
/*
void filter(unsigned char * input, double * output)
{
	double mask[3] = { 0.2518, 0.5138, 0.2518 };
	int lenMask = 3;

	int i, j, x, y, m, sum, center;

	////////	���͸�
	for (x = 0; x < WIDTH; x++) {
		for (y = 0; y < HEIGHT; y++) {
			sum = 0;	//������� �� �ʱ�ȭ
			mask[1] = *(input + y * WIDTH + x);		//������ �߾Ӱ� �̹����� �ȼ� ���߱�

			for (i = -1 * lenMask / 2; i < lenMask / 2; i++) {
				////	�̹��� �ٱ� ���� ���
				int edge_y = y + i;

				///		���� ����
				if (edge_y < 0)
					edge_y = 0;
				else if (edge_y > HEIGHT - 1)
					edge_y = HEIGHT - 1;

			}
			for (m = 0; m < 3; m++) {
				sum += *(input + (y*WIDTH - 1 + m) + x)*mask[m];
			}

			sum = sum / 9;			//�������
			*(output + y * WIDTH + x) = sum;	//��������� ����� ���� �ȼ��� ����
		}
	}
}
*/
/*
void filter(unsigned char * input, double * output, double * outimg)
{
	int mask[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };

	int i, j, m, n, sum;
	int new_x, new_y, xtemp, ytemp;

	for (i = 1; i < HEIGHT - 1; i++) {
		for (j = 1; j < WIDTH - 1; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (*(input + (j - 1 + m) + (i*WIDTH - 1 + n))*mask[m][n]);
				}
			}
			*(output + i * WIDTH + j) = (double)(sum / 9);
		}
	}
	double * temp;
	temp = (double*)malloc(sizeof(double)*DOWN_SIZE*DOWN_SIZE);
	
	double ratio = 512 / 298;

	for (new_y = 0; new_y < DOWN_SIZE; new_y++) {
		for (new_x = 0; new_x < DOWN_SIZE; new_x++) {
			ytemp = (int)(floor(new_y / ratio));
			xtemp = (int)(floor(new_x / ratio));

			*(temp + new_y * DOWN_SIZE + new_x) = *(output + ytemp * WIDTH + xtemp);
		}
	}
	for (i = 0; i < DOWN_SIZE; i++) {
		for (j = 0; j < DOWN_SIZE; j++) {
			*(outimg + i * WIDTH + j) = *(temp + i * DOWN_SIZE + j);		//������ ũ�� ����
		}
	}
	
}
*/
/*
void filter(unsigned char * input, unsigned char * output)
{
	int mask[3][3] =
	{
		{1, 1, 1},
	{1, 1, 1},
	{1, 1, 1} };

	int i, j, m, n, sum;
	for (i = 1; i < HEIGHT - 1; i++) {
		for (j = 1; j < WIDTH - 1; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (*(input + i*WIDTH - 1 + m + j- 1 + n)*mask[m][n]);
				}
			}
			*(output + i * WIDTH + j) = (unsigned char)(sum / 9);
		}
	}
}

	/*
	int m, n;
	double normalize = 0;
	int temp[WIDTH*HEIGHT];

	double mask[3][3]=
	{
		{1, 1, 1},
	{1, 1, 1},
	{1, 1, 1}
	};

	for (m = 0; m < 3; m++) {
		for (n = 0; n < 3; n++) {
			normalize += mask[m][n];
		}
	}
	if (normalize == 0)
		normalize = 1;
	else
		normalize = 1 / normalize;

	///�������
	for (int y = 1; y < HEIGHT - 1; y++) {
		for (int x = 1; x < WIDTH - 1; x++) {
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					temp[y*WIDTH+x]+=mask[m][n]*
				}
			}
		}
	}

*/


/*	int mask[3][3] = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1} };
*/
	/*	for (int y = 1; y < HEIGHT; y++) {
			for (int x = 1; x < WIDTH; x++) {
				int temp = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						temp += mask[i][j] * (*(input + (y*WIDTH + i - 1) + (x + j - 1)));
					}
				}
				*(output + y * WIDTH + x) = (double)(temp / 3);
			}
		}
	*/

/*	int sum;
	int maskSize = 3;
	unsigned char * temp;
	temp = (unsigned char*)malloc(sizeof(unsigned char)*WIDTH*HEIGHT);
		*//*
			for (int y = 0; y < HEIGHT; y++) {
				for (int x = 0; x < WIDTH; x++) {
					*(temp + WIDTH * y + x) = *(input + WIDTH * y + x);
				}
			}
		*/
/*
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				sum = 0;
				for (int i = -1 * maskSize / 2; i <= maskSize / 2; i++) {
					for (int j = -1 * maskSize / 2; j <= maskSize / 2; j++) {

						//////	���� ������ ��� ��� ����� ������ �����(�׵θ� ���� mirroring)
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

						/// ������� ���
						//sum += *(temp)*mask[maskSize / 2 + i][maskSize / 2 + j];
						sum += *(temp + edge_y * WIDTH + edge_x)*mask[maskSize / 2 + i][maskSize / 2 + j];
					}


					sum = sum / (double)(maskSize*maskSize);


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