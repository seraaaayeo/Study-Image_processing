#include "input.h"

typedef struct _Image_information
{
	int width;
	int height;
}Info;

typedef struct _Image_Buffer
{
	FILE *Input_Original; // ���� ������ �ҷ����� ���� ���� ���� ����
	FILE *Output;         // ��� ������ �����ϱ� ���� ���� ���� ����

	UChar *Ori_pix; // ���� ���� ���� ����	
	UChar *Re_pix; // ���� ���� ���� ����; // �е� ���� ���� ����
	
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

void Input_Image (Img_Buf *img); //�Է� ���� ���� �Լ�
void Output_Image(Img_Buf *img);
void DFT         (Img_Buf *img);
void IDFT        (Img_Buf *img);
void DCT         (Img_Buf *img);
void IDCT        (Img_Buf *img);
void PSNR        (Img_Buf *img);
void LPF         (Img_Buf *img, Int Blk_Row, Int Blk_COl);