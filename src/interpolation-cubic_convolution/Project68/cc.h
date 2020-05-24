#include <stdio.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define UPSIZE 1000
#define REDOWN 512
#define DOWNSIZE 400
#define REUP 512


double find(double f1, double f2, double f3, double f4, double t);
//void bicubic(unsigned char * input, unsigned char * output, int newWIDTH, int newHEIGHT);
//void bicubicUp(unsigned char * input, unsigned char * output, int newWIDTH, int newHEIGHT);

void bicubicUp(unsigned char * input, unsigned char * output);
void DownAfterUp(unsigned char * input, unsigned char * output);
void bicubicDown(unsigned char * input, unsigned char * output);
void UpAfterDown(unsigned char * input, unsigned char * output);

void filter(unsigned char * input, unsigned char * output);
void menu();

unsigned char * input, *output, *outimg;
unsigned char * upoutput, *downoutput, *result;