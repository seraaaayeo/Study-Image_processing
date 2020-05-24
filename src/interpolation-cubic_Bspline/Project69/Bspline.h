#include <stdio.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define UPSIZE 1000
#define REDOWN 512
#define DOWNSIZE 400
#define REUP 512

double findPoint(double f1, double f2, double f3, double f4, double t);
void BUp(unsigned char * input, unsigned char * output);
void BUptoDown(unsigned char * input, unsigned char * output);
void BDown(unsigned char * input, unsigned char * output);
void BDowntoUp(unsigned char * input, unsigned char * output);


void preEmphasis(unsigned char * input, unsigned char * output);
void LPF(unsigned char * input, unsigned char * output);
void Highboost(unsigned char * input, unsigned char * output);
void High(unsigned char * input, unsigned char * output);
void spline(unsigned char * input, unsigned char * output);
void menu();

unsigned char * input, *output, *outimg;
unsigned char * upoutput, *result, *result2;

