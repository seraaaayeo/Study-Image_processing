#include "buffer.h"

void main()
{
	Img_Buf img; 
	Int Transform_type;

	printf("��ȯ ���� : 1. DFT, 2. DCT\n");
	scanf_s(" %d", &Transform_type);
	system("cls");

	Input_Image(&img);

	if (Transform_type == 1)
	{
		DFT (&img); //���� ����
		IDFT(&img); //���� ����
	}
	else if (Transform_type == 2)
	{
		DCT (&img); //���� ����
		IDCT(&img); //���� ����
	}

	PSNR(&img); //���� ����

	Output_Image(&img);

}