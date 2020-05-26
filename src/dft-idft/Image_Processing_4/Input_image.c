#include "buffer.h"

void Input_Image(Img_Buf *img)
{
	img->info.width = WIDTH;
	img->info.height = HEIGHT;

	fopen_s(&img->Input_Original, FILENAME, "rb");                                                  // 원본 입력 영상 읽기 모드로 열기
	img->Ori_pix = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));               // 원본 영상 크기만큼 메모리(버퍼) 선언
	img->Re_pix  = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));               // 원본 영상 크기만큼 메모리(버퍼) 선언

	img->CurBlk    = (UChar* )calloc(NNBlk_SIZE * NNBlk_SIZE         , sizeof(UChar ));
	//img->CurBlk = (UChar*)calloc(img->info.width * img->info.height, sizeof(UChar));
	img->DFT_Real  = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));
	img->DFT_Imag  = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));
	img->Magnitude = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));
	img->Phase     = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));

	img->IDFT_Real = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));
	img->IDFT_Imag = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));

	img->Spectrum  = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));
	img->Re_CurBlk = (Double*)calloc(img->info.width*img->info.height, sizeof(Double));

	fread(img->Ori_pix, sizeof(UChar), (img->info.width * img->info.height), img->Input_Original);  // 원본 영상 읽기(원본 영상의 화소값을 배열 변수에 저장)
}