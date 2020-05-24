#include "Bspline.h"

double filter(unsigned char * input, unsigned char * output)
{
	double sum = 0;
	double S;
	double * temp_in; 
	unsigned char * temp_out;

	temp_in = (double*)malloc(sizeof(double)*(HEIGHT + 2)*(WIDTH + 2));
	temp_out = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			*(temp_in + i * WIDTH + 1 + j + 1) = *(input + i * WIDTH + j);
		}
	}
	
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			for (int m = HEIGHT-1; m <= 0; m--) {
				for (int n = WIDTH-1; n <= 0; n--) {
					S = (1.7316836452)*(-0.2679)*(m*WIDTH + n);
					printf("check sk : %lf \n", S);
					sum += (*(temp_in + m * WIDTH + n)*(S));
					//printf("check sum : %lf \n", sum);
				}
			}
			*(temp_out + i * WIDTH + j) = (unsigned char)(sum);
			sum = 0;
			//printf("check : %lf\n", *(temp_out + i * WIDTH + j));
		}
	}
}