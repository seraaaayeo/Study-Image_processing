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
	printf("1.���Ϲ��� 2.�¿���� 3.90�� ȸ�� 4.180�� ȸ�� 5.270�� ȸ�� 6.360�� ȸ��\n");
	printf("--------------------------------	Menu	----------------------------------------\n");

	printf("choose a number");
	scanf("%d", &menu);

	FILE * infile = fopen("lena.img", "rb");		//�̹��� ������ �б� ���� �ҷ�����
	if (infile == NULL) {
		printf("file open error!");
		return 1;
	}

	fread(org_img, sizeof(char), HEIGHT*WIDTH, infile);		//�̹����κ��� �ȼ� ���� �б�

	fclose(infile);

	if (menu == 1) {
		///		���Ϲ���	 ///
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				new_img[i][j] = org_img[HEIGHT - i - 1][j];
			}
		}

		FILE*outfile = fopen("lena_���Ϲ���.img", "wb");		//��� ������ ���� ���� ����
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//��� �̹����� �ȼ� ���� ����
		fclose(outfile);
	}
	else if (menu == 2) {
		////	�¿����	///
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				new_img[i][j] = org_img[i][WIDTH - j - 1];
			}
		}

		FILE*outfile = fopen("lena_�¿����.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//��� �̹����� �ȼ� ���� ����
		fclose(outfile);
	}
	else if (menu == 3) {
		////	90�� ȸ��	///
		for (int j = 0; j < WIDTH; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				new_img[j][i] = org_img[HEIGHT - i - 1][j];
			}
		}
		
		FILE*outfile = fopen("lena_90��ȸ��3.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//��� �̹����� �ȼ� ���� ����
		fclose(outfile);
	}
	else if (menu == 4) {
		///////////		180�� ȸ�� = 90�� ȸ�� * 2	///////////
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
		FILE*outfile = fopen("lena_180��ȸ��.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//��� �̹����� �ȼ� ���� ����
		fclose(outfile);
	}
	else if (menu == 5) {
		///////////		270�� ȸ�� = 90�� ȸ�� * 3	///////////
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
		FILE*outfile = fopen("lena_270��ȸ��.img", "wb");
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//��� �̹����� �ȼ� ���� ����
		fclose(outfile);
	}
	else if (menu == 6) {
		///////////		360�� ȸ�� = 90�� ȸ�� * 4	///////////
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
		fwrite(new_img, sizeof(char), HEIGHT*WIDTH, outfile);		//��� �̹����� �ȼ� ���� ����
		fclose(outfile);

	}

	printf("�̹��� ��ȯ �Ϸ�");
}
*/