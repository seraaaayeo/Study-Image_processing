#pragma once
#include <stdio.h>

#define WIDTH 512
#define HEIGHT 512
#define UP_SIZE 512
#define DOWN_SIZE 400

unsigned char * input, *outimg, *upout, *downout, *result, *output;
double * doutput;

void bilinear(unsigned char * input, unsigned char * output);
void upscaling(unsigned char * input, unsigned char * output);
void downscaling(unsigned char * input, unsigned char * output);

void print(double *input, unsigned char *output);
void psnr(unsigned char * input, unsigned char * output);
void filter(unsigned char * input, unsigned char * output);
//void makeFilter(unsigned char * input, unsigned char * output);
