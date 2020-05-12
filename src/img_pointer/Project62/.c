/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HEIGHT 512
#define WIDTH 512
#define pi 3.1415926535


int main(void)
{
	int menu;
	unsigned char org_img[HEIGHT][WIDTH];
	unsigned char new_img[HEIGHT][WIDTH];

	printf("--------------------------------	Menu	----------------------------------------\n");
	printf("1.상하반전 2.좌우반전 3.90도 회전 4.180도 회전 5.270도 회전 6.360도 회전\n");
	printf("--------------------------------	Menu	----------------------------------------\n");

	printf("choose a number");
	scanf("%d", &menu);

	FILE * infile = fopen("lena.img", "rb");		//이미지 파일을 읽기 모드로 불러오기
	if (infile == NULL) {
		printf("file open error!");
		return 1;
	}

	fread(org_img, sizeof(char), HEIGHT*WIDTH, infile);		//이미지로부터 픽셀 정보 읽기

	fclose(infile);

	if (menu == 1) {
		///		상하반전	 ///
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				new_img[i][j] = org_img[HEIGHT - i - 1][j];
			}
		}

		FILE*outfile = fopen("lena_상하반전.img", "wb");		//출력 파일을 쓰기 모드로 열기
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//결과 이미지에 픽셀 정보 저장
		fclose(outfile);
	}
	else if (menu == 2) {
		////	좌우반전	///
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				new_img[i][j] = org_img[i][WIDTH - j - 1];
			}
		}

		FILE*outfile = fopen("lena_좌우반전.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//결과 이미지에 픽셀 정보 저장
		fclose(outfile);
	}
	else if (menu == 3) {
		////	90도 회전	///
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = org_img[HEIGHT - i - 1][j];
			}
		}
		
		FILE*outfile = fopen("lena_90도회전3.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//결과 이미지에 픽셀 정보 저장
		fclose(outfile);
	}
	else if (menu == 4) {
		///////////		180도 회전 = 90도 회전 * 2	///////////
		int i, j;
		unsigned char temp[HEIGHT][WIDTH];
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = org_img[HEIGHT - i - 1][j];
				temp[j][i] = new_img[j][i];
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = temp[HEIGHT - i - 1][j];
			}
		}
		FILE*outfile = fopen("lena_180도회전.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//결과 이미지에 픽셀 정보 저장
		fclose(outfile);
	}
	else if (menu == 5) {
		///////////		270도 회전 = 90도 회전 * 3	///////////
		int i, j;
		unsigned char temp[HEIGHT][WIDTH];
		unsigned char temp2[HEIGHT][WIDTH];

		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = org_img[HEIGHT - i - 1][j];
				temp[j][i] = new_img[j][i];
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = temp[HEIGHT - i - 1][j];
				temp2[j][i] = new_img[j][i];
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = temp2[HEIGHT - i - 1][j];
			}
		}
		FILE*outfile = fopen("lena_270도회전.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//결과 이미지에 픽셀 정보 저장
		fclose(outfile);
	}
	else if (menu == 6) {
		///////////		360도 회전 = 90도 회전 * 4	///////////
		int i, j;
		unsigned char temp[HEIGHT][WIDTH];
		unsigned char temp2[HEIGHT][WIDTH];
		unsigned char temp3[HEIGHT][WIDTH];


		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = org_img[HEIGHT - i - 1][j];
				temp[j][i] = new_img[j][i];
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = temp[HEIGHT - i - 1][j];
				temp2[j][i] = new_img[j][i];
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = temp2[HEIGHT - i - 1][j];
				temp3[j][i] = new_img[j][i];
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = temp3[HEIGHT - i - 1][j];
			}
		}
		FILE*outfile = fopen("lena_comp.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//결과 이미지에 픽셀 정보 저장
		fclose(outfile);

	}

	printf("이미지 변환 완료");
}
*/