#include "dct3.h"

int main(void)
{
	int menu;
	input = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
//	dinput = (double*)malloc(sizeof(double)*N*N);
	output = (double*)malloc(sizeof(double)*HEIGHT*WIDTH);
	output2 = (double*)malloc(sizeof(double)*HEIGHT*WIDTH);
	outimg = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	outimg2 = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	
	printf("--------------------------------	Menu	----------------------------------------\n");
	printf("1.default DCT  2.N x N DCT  3.X-DCT  4.Y-DCT \n");
	printf("5.DCT-IDCT	6.Q-DCT	7.�Ϻΰ�� ���	8.DC���  \n");
	printf("--------------------------------	Menu	----------------------------------------\n");

	printf("choose a number");
	scanf("%d", &menu);
	
	FILE * infile = fopen("lena.img", "rb");

	if (infile == NULL) {
		printf("file open error!");
		return 1;
	}

	fread(input, sizeof(char), HEIGHT*WIDTH, infile);
	fclose(infile);

	/*
	///		DCT-IDCT 	 ///
	DCT(input, output);
	print(output, outimg);
	//IDCT(output, outimg2);
	
	
	//// ���� ���ι��� ////
	YDCT(input, output);
	print(output, outimg);
	//XDCT(input, output);
	//print(output, outimg);
	
	
	///		����ȭ 	  ///
	//*dinput = (double)(*input);
	DCT(input, output);
	QDCT(output, output2);
	IDCT(output2, outimg);
	//QIDCT(output, output2);
	
	
	///		�Ϻ� ��� 	 ///
	DCT(input, output);
	coeIDCT(output, outimg, 0);
	
	
	///		DC ��� 	 ///
	DCT(input, output);
	dcIDCT(output, outimg);
	*/

	FILE * outfile = fopen("lena_w.img", "wb");
	fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
	psnr(input, outimg);

	fclose(outfile);
	free(output);
	free(outimg);

	printf("success!");

	
	///defaul DCT///
	if (menu == 1) {
		DCT(input, output);
		print(output, outimg);

		FILE * outfile = fopen("lena_defaultDCT.img", "wb");
		fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		fclose(outfile);
		free(output);
		free(outimg);

		printf("success!");
	}

	else if (menu == 2) {
		scanf("size : %d", );

		DCT(input, output);
		print(output, outimg);
	}

	///���ι��� dct///
	else if (menu == 3) {
		YDCT(input, output);
		print(output, outimg);
	}

	///���ι��� dct///
	else if (menu == 4) {
		XDCT(input, output);
		print(output, outimg);
	}

	///DCT-IDCT///
	else if (menu == 5) {
		DCT(input, output);
		IDCT(output, outimg2);
	}

	///����ȭ///
	else if (menu == 6) {
		DCT(input, output);
		QDCT(output, output2);
		IDCT(output2, outimg);
	}

	///�Ϻ� ��� ���///
	else if (menu == 7) {
		int n;
		printf(" ");
		scanf("%d\n", n);
		DCT(input, output);
		coeIDCT(output, outimg, n);
	}
}