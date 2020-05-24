#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define UP_SIZE 512
#define DOWN_SIZE 400

unsigned char * input, *outimg, *result, *upoutput, *downoutput;
double * output, *d_output;

void up(unsigned char * input, unsigned char * output);
void upwindow(unsigned char * input, unsigned char * output);

void down(unsigned char * input, unsigned char * output);
void downwindow(unsigned char * input, unsigned char * output);

//void f_downscale(double * input, double * output);
//void f_downscale(unsigned char * input, unsigned char * output);
void filter(unsigned char * input, unsigned char * output);
void newfilter(unsigned char * input, unsigned char * output);

//float clipping(float range);
void psnr(unsigned char * input, unsigned char * output);
void print(double *input, unsigned char *output);




