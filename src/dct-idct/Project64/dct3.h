#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define pi 3.1415926535
#define N 8

void psnr(unsigned char * input, unsigned char * output);

void DCT(unsigned char * input, double * output);
void QDCT(double * input, double * output);
void sampleDCT(double * sample, double * result);

void IDCT(double * input, unsigned char * output);
void coeIDCT(double * input, unsigned char * output, int coeffi);
void dcIDCT(double * input, unsigned char * output);
//void QIDCT(double * input, unsigned char * output);

void YDCT(unsigned char *input, double * output);
void YDCT(unsigned char *input, double * output);

void print(double *input, unsigned char *output);
void yprint(double * input, unsigned char * output);

unsigned char * input, *outimg, *outimg2;
double * output, *output2, *dinput;


