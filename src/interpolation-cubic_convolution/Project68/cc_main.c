#include "cc.h"

int main(void)
{
	input = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	output = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	result = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	upoutput = (unsigned char*)malloc(sizeof(unsigned char)*UPSIZE*UPSIZE);
	downoutput = (unsigned char*)malloc(sizeof(unsigned char)*DOWNSIZE*DOWNSIZE);

	outimg = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	menu();

}


///////////		이미지 작업		///////////
//	bicubicUp(input, upoutput);
//	bicubicDown(input, outimg);
//	filter(input, output);	bicubicDown(output, outimg);
//	bicubicUp(input, upoutput); bicubicDown(upoutput, outimg);	//Up -> Down
//	bicubicDown(input, output); bicubicUp(output, outimg);	//Down -> Up(no LPF)
//	filter(input, result); bicubicDown(result, output); bicubicUp(output, outimg);
//	filter(input, outimg);
