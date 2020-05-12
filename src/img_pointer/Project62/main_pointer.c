
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HEIGHT 512
#define WIDTH 512
#define pi 3.1415926535


int main(void)
{
	int menu;

	unsigned char * org_img;
	org_img = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	unsigned char * new_img;
	new_img = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
	
	printf("--------------------------------	Menu	----------------------------------------\n");
	printf("1.상하반전 2.좌우반전 3.90도 회전 4.180도 회전 5.270도 회전 6.360도 회전\n");
	printf("--------------------------------	Menu	----------------------------------------\n");

	printf("choose a number ");
	scanf("%d", &menu);

	FILE * infile = fopen("F16.img", "rb");		//이미지 파일을 읽기 모드로 불러오기
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
				*(new_img + WIDTH * i + j) = *(org_img + WIDTH*(HEIGHT-i-1) + j);
			}
		}
	
		FILE * outfile = fopen("F16_UpDown.img", "wb");		//출력 파일을 쓰기 모드로 열기
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//결과 이미지에 픽셀 정보 저장
		fclose(outfile);
		free(new_img);		//���� �Ҵ��� �޸��� ���ҽ� ����
	}
	
	else if (menu == 2) {
		////	좌우반전	///
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				*(new_img + WIDTH * i + j) = *(org_img + WIDTH * i + (WIDTH - j - 1));
			}
		}

		FILE*outfile = fopen("F16_LeftRight.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		
		fclose(outfile);
		free(new_img);
	}
	
	else if (menu == 3) {
		////	90도 회전	///
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT*j + i) = *(org_img + WIDTH * (HEIGHT - i - 1) + j);
			}
		}
		
		FILE*outfile = fopen("F16_rot_90.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		
		fclose(outfile);
		free(new_img);
	}
	
	else if (menu == 4) {
		///////////		180도 회전 = 90도 회전 * 2	///////////
		int i, j;
		unsigned char * temp;
		temp = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(org_img + WIDTH * (HEIGHT - i - 1) + j);
				*(temp + HEIGHT * j + i) = *(new_img + HEIGHT * j + i);
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(temp + WIDTH * (HEIGHT - i - 1) + j);
			}
		}
		FILE*outfile = fopen("F16_rot_180.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		
		fclose(outfile);
		free(new_img);
	}
	
	else if (menu == 5) {
		///////////		270도 회전 = 90도 회전 * 3	///////////
		int i, j;
		unsigned char * temp, *temp2;
		temp = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
		temp2 = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(org_img + WIDTH * (HEIGHT - i - 1) + j);
				*(temp + HEIGHT * j + i) = *(new_img + HEIGHT * j + i);
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(temp + WIDTH * (HEIGHT - i - 1) + j);
				*(temp2 + HEIGHT * j + i) = *(new_img + HEIGHT * j + i);
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(temp2 + WIDTH * (HEIGHT - i - 1) + j);
			}
		}
		FILE*outfile = fopen("F16_rot_270.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		
		fclose(outfile);
		free(new_img);
	}
	
	else if (menu == 6) {
		///////////		360도 회전 = 90도 회전 * 4	///////////
		int i, j;

		unsigned char * temp, *temp2, *temp3;
		temp = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
		temp2 = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);
		temp3 = (unsigned char*)malloc(sizeof(unsigned char)*HEIGHT*WIDTH);

		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(org_img + WIDTH * (HEIGHT - i - 1) + j);
				*(temp + HEIGHT * j + i) = *(new_img + HEIGHT * j + i);
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(temp + WIDTH * (HEIGHT - i - 1) + j);
				*(temp2 + HEIGHT * j + i) = *(new_img + HEIGHT * j + i);
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(temp2 + WIDTH * (HEIGHT - i - 1) + j);
				*(temp3 + HEIGHT * j + i) = *(new_img + HEIGHT * j + i);
			}
		}
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				*(new_img + HEIGHT * j + i) = *(temp3 + WIDTH * (HEIGHT - i - 1) + j);
			}
		}
		FILE*outfile = fopen("F16_rot_360.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		
		fclose(outfile);
		free(new_img);
	}
	
	printf("이미지 변환 완료");
}
