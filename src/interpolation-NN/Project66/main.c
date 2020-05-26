#include "snh.h"

int main(void)
{
	input = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	output = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	outimg = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	upoutput = (unsigned char*)malloc(sizeof(unsigned char)*UP_SIZE*UP_SIZE);
	downoutput = (unsigned char*)malloc(sizeof(unsigned char)*DOWN_SIZE*DOWN_SIZE);

	result = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);


	////////////		���� �̹��� �ҷ�����			////////////
	FILE * infile = fopen("lena.img", "rb");
	if (infile == NULL) {
		printf("file open error!");
		return 1;
	}

	fread(input, sizeof(char), HEIGHT*WIDTH, infile);
	fclose(infile);

	///////////////			���� ó��			///////////////
	newfilter(input, result);
	downwindow(result, output);
	upwindow(output, outimg);

	/////////////			���� �̹��� ���� �� �ݱ�			///////////////
	FILE * outfile = fopen("lena_trailFix.img", "wb");

	/*
	//UpToDown ����
	fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);
	psnr(input, outimg);
	fclose(outfile);
	free(outimg);
	*/
	/*
	fwrite(downoutput, sizeof(char), DOWN_SIZE*DOWN_SIZE, outfile);
	psnr(input, downoutput);
	fclose(outfile);
	free(downoutput);
	*/
	
	fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);
	psnr(input, outimg);
	fclose(outfile);
	free(outimg);
	
	/*
	//up
	fwrite(upoutput, sizeof(char), UP_SIZE*UP_SIZE, outfile);
	psnr(input, upoutput);
	fclose(outfile);
	free(upoutput);
	*/
	/*
	// default
	fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
	psnr(input, outimg);
	fclose(outfile);
	free(outimg);
	*/

	printf("image process : success!");

}

