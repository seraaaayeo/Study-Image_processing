#include "bilinear.h"

int main(void)
{
	input = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	outimg = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	output = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	doutput = (double*)malloc(sizeof(double)*HEIGHT*WIDTH);

	upout = (unsigned char*)malloc(sizeof(unsigned char)*UP_SIZE*UP_SIZE);
	downout = (unsigned char*)malloc(sizeof(unsigned char)*DOWN_SIZE*DOWN_SIZE);

	result = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	////////////		���� �̹��� �ҷ�����			////////////
	FILE * infile = fopen("lena.img", "rb");
	if (infile == NULL) {
		printf("file open error!");
		return 1;
	}

	fread(input, sizeof(char), HEIGHT*WIDTH, infile);
	fclose(infile);

	///////////		�̹��� �۾�		///////////
	//bilinear(input, outimg);	//������ ũ�⺯ȭ ���� Ȯ��
	//upscaling(input, upout);
	//downscaling(input, outimg);
	//upscaling(input, upout); downscaling(upout, outimg);	//Up -> Down
	//downscaling(input, result); upscaling(result, outimg);	//Down -> Up(no LPF)
	filter(input, output);	downscaling(output, result);  upscaling(result, outimg);	//Down -> Up(LPF)
	

	/////////////			���� �̹��� ��� �� �ݱ�			///////////////
	FILE * outfile = fopen("lena_trial7.img", "wb");

	fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);
	
	psnr(input, outimg);
	fclose(outfile);
	free(outimg);

	printf("image process : success!");
}