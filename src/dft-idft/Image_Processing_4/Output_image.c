#include "buffer.h"

void Output_Image(Img_Buf *img)
{
	free(img->Ori_pix);
	free(img->Re_pix);

	free(img->CurBlk);
	free(img->DFT_Real);
	free(img->DFT_Imag);
	free(img->Magnitude);
	free(img->Phase);

	free(img->IDFT_Real);
	free(img->IDFT_Imag);

	free(img->Spectrum);
	free(img->Re_CurBlk);

	fclose(img->Input_Original);
}