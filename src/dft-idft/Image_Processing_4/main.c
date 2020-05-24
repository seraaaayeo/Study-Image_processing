#include "buffer.h"

void main()
{
	Img_Buf img; 
	Int Transform_type;

	printf("변환 선택 : 1. DFT, 2. DCT\n");
	scanf_s(" %d", &Transform_type);
	system("cls");

	Input_Image(&img);

	if (Transform_type == 1)
	{
		DFT (&img); //과제 구현
		IDFT(&img); //과제 구현
	}
	else if (Transform_type == 2)
	{
		DCT (&img); //과제 구현
		IDCT(&img); //과제 구현
	}

	PSNR(&img); //과제 구현

	Output_Image(&img);

}