#include "input.h"

typedef struct _Image_information
{
	int width;
	int height;
}Info;

typedef struct _Image_Buffer
{
	FILE *Input_Original; // 원본 영상을 불러오기 위해 파일 변수 선언
	FILE *Output;         // 출력 영상을 저장하기 위해 파일 변수 선언

	UChar *Ori_pix; // 원본 영상 저장 버퍼	
	UChar *Re_pix; // 원본 영상 저장 버퍼; // 패딩 영상 저장 버퍼
	
	UChar  *CurBlk;
	Double *DFT_Real;
	Double *DFT_Imag;
	Double *Magnitude;
	Double *Phase;

	Double *IDFT_Real;
	Double *IDFT_Imag;

	Double *Spectrum;
	Double *Re_CurBlk;

	Info info;

}Img_Buf;

void Input_Image (Img_Buf *img); //입력 영상 관련 함수
void Output_Image(Img_Buf *img);
void DFT         (Img_Buf *img);
void IDFT        (Img_Buf *img);
void DCT         (Img_Buf *img);
void IDCT        (Img_Buf *img);
void PSNR        (Img_Buf *img);
void LPF         (Img_Buf *img, Int Blk_Row, Int Blk_COl);