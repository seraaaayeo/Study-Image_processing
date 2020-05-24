#include "bilinear.h"

void makeFilter(unsigned char * input, unsigned char * output)
{
	int sum;
	int mask[3] = { 1, 1, 1 };
	int msize = 3;
	int hsize = msize / 2;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			sum = 0;

			int i = hsize - 1;
			for (i = 0; i < HEIGHT; i++) {

				int yedge = y + i;

				if (yedge < 0)
					yedge = 0;
				else if (yedge > HEIGHT - 1)
					yedge = HEIGHT - 1;

					sum += *(input + yedge * WIDTH)*(i);


			}
			*(output + y * WIDTH + x) = (unsigned char)sum / 3;

		}
	}
}