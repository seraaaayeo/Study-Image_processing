#include "buffer.h"

#define convert(x, y)	sqrt( (Double)(x*x + y*y) );
#define D0				32.0
#define N0				4.0

void LPF(Img_Buf *img, Int Blk_Row, Int Blk_COl)
{
	UInt	i, j;
	UInt	Tmpx, Tmpy;
	Double	FliterCoeff;
	Double  Coordinate;

	for (i = 0; i < img->info.height; i++)
	{
		if (i >= img->info.width / 2)
			Tmpy = i - (img->info.width / 2);
		else
			Tmpy = i + (img->info.width / 2);

		for (j = 0; j < img->info.width; j++)
		{
			if (i >= img->info.height / 2)
				Tmpx = i - (img->info.height / 2);
			else
				Tmpx = i + (img->info.height / 2);

			Coordinate = convert((Tmpx - (img->info.width / 2)), (Tmpy - (img->info.height / 2)));
			FliterCoeff = 1.0 / (1.0 + pow(Coordinate / D0, 2 * N0));

			img->DFT_Real[i*img->info.height + j] *= FliterCoeff;
			img->DFT_Imag[i*img->info.height + j] *= FliterCoeff;
		}
	}
}