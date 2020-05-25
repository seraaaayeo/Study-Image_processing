#include "dct.h"

void DCT(unsigned char *input, double * output)
{
	//////////////////////////////////////			base setting		///////////////////////////////////////
	/* i:�ȼ��� ���ι���(i_max=HEIGHT)	j:�ȼ��� ���ι���(j_max=WIDTH)	N:��� ���� (default : N=8)
	   v:basis vector ���Ǹ� ���� ������	c_v:basis vector ���ǿ� ���ԵǴ� �Լ�   b_vec : basis vector x1, x2,...,x8 
	   By : i����(���ι���) �� ����		Bx :j����(���ι���) �� ���� (8X8 ��, 512X512 -> Bx,By=64(512/8) 	*/

	int i, j, u, v;
	int Bx, By;
	double c_v, c_u, sum, b_vec, howlong;
	clock_t start, end;

	start = clock();

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
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							sum +=
								cos((2 * i + 1) * u * pi / (2 * N)) * cos((2 * j + 1) * v * pi / (2 * N))*
								(*(input + (Bx * N) + (By * N * WIDTH) + i * WIDTH + j));	//Bx, By�� ���ԵǴ� N���� �ȼ��� ����
								//(*(input + i * WIDTH + j));
						}
					}
					*(output + (Bx * N) + (By * N * WIDTH) + u * WIDTH + v) = (c_u * c_v) / (sqrt(N * N) / 2) * sum;
				}
				//printf("\n");
			}
		}
	end = clock();
	howlong = (double)(end - start);
	printf("how long : %lf (ms)\n", howlong);

}
