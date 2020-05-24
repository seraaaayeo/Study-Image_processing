#include "cc.h"

void menu()
{
	int menu;

	input = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	output = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	outimg = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	result = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

	upoutput = (unsigned char*)malloc(sizeof(unsigned char)*UPSIZE*UPSIZE);

	printf("********************* Select menu ***********************\n");
	printf("*	1.Upscaling : 512 -> 945			*\n");
	printf("*	2.Downscaling : 512 -> 298			*\n");
	printf("*	3.Downscaling w.o LPF				*\n");
	printf("*	4.Up & Down : 512 -> 1000 -> 512		*\n");
	printf("*	5.Down & Up : 512 -> 400 -> 512			*\n");
	printf("*	6.Down & Up w.o LPF				*\n");
	printf("*********************************************************\n");
	printf("\n");
	printf("choose a menu");
	scanf("%d", &menu);

	////////////		레나 이미지 불러오기			////////////
	FILE * infile = fopen("lena.img", "rb");
	if (infile == NULL) {
		printf("file open error!\n");
		return 1;
	}
	fread(input, sizeof(char), HEIGHT*WIDTH, infile);
	fclose(infile);


	if (menu == 1) {		//Up
		
		bicubicUp(input, upoutput);
		
		FILE * outfile = fopen("lena_CC_up.img", "wb");

		fwrite(upoutput, sizeof(char), UPSIZE*UPSIZE, outfile);

		psnr(input, upoutput);
		fclose(outfile);
		free(upoutput);

		printf("Upscaling : success!\n");
	}

	else if (menu == 2) {	//Down
		filter(input, result);
		bicubicDown(result, outimg);

		FILE * outfile = fopen("lena_cc_down.img", "wb");

		fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);

		psnr(input, outimg);
		fclose(outfile);
		free(outimg);

		printf("Downscaling : success!\n");

	}

	else if (menu == 3) {	//Down, No LPF
		
		bicubicDown(input, outimg);

		FILE * outfile = fopen("lena_cc_down_noLPF.img", "wb");

		fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);

		psnr(input, outimg);
		fclose(outfile);
		free(outimg);

		printf("Downscaling without LPF : success!\n");

	}

	else if (menu == 4) { //Up -> Down + filter
		bicubicUp(input, upoutput);
		DownAfterUp(upoutput, outimg);

		FILE * outfile = fopen("lena_cc_up&down.img", "wb");

		fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);

		psnr(input, outimg);
		fclose(outfile);
		free(outimg);

		printf("Up and down : success!\n");

	}

	else if (menu == 5) {	//Down -> Up +filter
		filter(input, result);
		bicubicDown(result, output);
		UpAfterDown(output, outimg);

		FILE * outfile = fopen("lena_cc_Down&Up.img", "wb");

		fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);

		psnr(input, outimg);
		fclose(outfile);
		free(outimg);

		printf("down and up : success!\n");
	}

	else if (menu == 6) { 	//Down -> Up No filter
		filter(input, result);
		bicubicDown(result, output);
		UpAfterDown(output, outimg);

		FILE * outfile = fopen("lena_cc_down&up_noLPF.img", "wb");

		fwrite(outimg, sizeof(char), WIDTH*HEIGHT, outfile);

		psnr(input, outimg);
		fclose(outfile);
		free(outimg);

		printf("down and up without LPF : success!\n");
	}

	return menu;
}