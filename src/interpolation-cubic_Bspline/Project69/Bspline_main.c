#include "Bspline.h"

int main(void)
{
	input = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	output = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	outimg = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	result = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	result2 = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	upoutput = (unsigned char*)malloc(sizeof(unsigned char)*UPSIZE*UPSIZE);

	menu();
	
}
///////////		이미지 작업		///////////
	//preEmphasis(input, outimg);
	//BUp(input, upoutput); BUptoDown(upoutput, outimg); //Up -> Down
	//LPF(input, result); preEmphasis(result, result2); BDown(result2, output); BDowntoUp(output, outimg);	//Down -> Up
	//Highboost(input, result); BUp(result, upoutput); BUptoDown(upoutput, outimg); //Up -> Down + filter
	//LPF(input, result); Highboost(result, result2); BDown(result2, output); BDowntoUp(output, outimg);	//Down -> Up +filter
	//Highboost(input, result); BUp(result, upoutput);	//UP
	//Highboost(input, result); LPF(result, result2); BDown(result2, outimg); //Down