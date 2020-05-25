#include "dct.h"

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
	printf("1.default DCT  3.X-DCT  4.Y-DCT \n");
	printf("5.DCT-IDCT	6.Q-DCT	7.일부계수 사용	8.DC계수  \n");
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

	///가로방향 dct///
	else if (menu == 3) {
		YDCT(input, output);
		print(output, outimg);

		FILE * outfile = fopen("lena_xDCT.img", "wb");
		fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		fclose(outfile);
		free(output);
		free(outimg);

		printf("success!");
	}

	///세로방향 dct///
	else if (menu == 4) {
		XDCT(input, output);
		print(output, outimg);

		FILE * outfile = fopen("lena_yDCT.img", "wb");
		fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		fclose(outfile);
		free(output);
		free(outimg);

		printf("success!");
	}

	///DCT-IDCT///
	else if (menu == 5) {
		DCT(input, output);
		IDCT(output, outimg);

		FILE * outfile = fopen("lena_DCT-IDCT.img", "wb");
		fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		fclose(outfile);
		free(output);
		free(outimg);

		printf("success!");
	}

	///양자화///
	else if (menu == 6) {
		DCT(input, output);
		QDCT(output, output2);
		IDCT(output2, outimg);

		FILE * outfile = fopen("lena_qDCT.img", "wb");
		fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		fclose(outfile);
		free(output);
		free(outimg);

		printf("success!");
	}

	///일부 계수 사용///
	else if (menu == 7) {
		int n;
		printf("input coeffi : ");
		scanf("%d", &n);
		DCT(input, output);
		coeIDCT(output, outimg, n);

		FILE * outfile = fopen("lena_coDCT.img", "wb");
		fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		fclose(outfile);
		free(output);
		free(outimg);

		printf("success!");
	}

	///DC 계수 사용///
	else if (menu == 8) {
		DCT(input, output);
		dcIDCT(output, outimg);

		FILE * outfile = fopen("lena_dcDCT.img", "wb");
		fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		fclose(outfile);
		free(output);
		free(outimg);

		printf("success!");
	}
}