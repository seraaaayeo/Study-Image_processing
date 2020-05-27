<h2 align="center">Image Processing</h2>
<p align="center">
  Multimedia Processing Traning in Summer, 2019
</p>

* * *

## Project List
* [Image_pointer](https://github.com/seraaaayeo/study-image_processing/tree/master/src/img_pointer) : Image Rotation with Pointer
* [DCT](https://github.com/seraaaayeo/study-image_processing/tree/master/src/dct-idct) : Discrete Cosine Transform and Inverse
* [DFT](https://github.com/seraaaayeo/study-image_processing/tree/master/src/dft-idft) : Discrete Fourier Transform and Inverse
* [Interpolation-Sample_and_hold](https://github.com/seraaaayeo/study-image_processing/tree/master/src/interpolation-NN) : upscaling, downscaling with Sample and hold interpolation
* [Interpolation-Bilinear](https://github.com/seraaaayeo/study-image_processing/tree/master/src/interpolation-Bilinear) : upscaling, downscaling with Bilinear interpolation
* [Interpolation-cubic_convolution](https://github.com/seraaaayeo/study-image_processing/tree/master/src/interpolation-cubic_convolution) : upscaling, downscaling with Cubic convolution interpolation
* [Interpolation-cubic_B_Spline](https://github.com/seraaaayeo/study-image_processing/tree/master/src/interpolation-cubic_Bspline) : upscaling, downscaling with Cubic B Spline interpolation

* * *

## Getting Started

#### Stack
* C

#### Pre-requisties
|  <center>Requirement</center> |  <center>Description</center> |  
|:--------|:--------:|
|**visual studio** | <center>v2017 or higher</center> |
|**git** | <center>We follow the Github flow</center> |

#### Must to do
* you have to include raw image file in your working directory.
* I.E) if you work on dct-idct, you have to copy lena image in dct-idct\Project64

## Docs
#### display
* this includes raw image display program
    * RDisp
    * yuvplayer : Size -> Custom, Color -> Y

#### img
* this is raw image folder which are the most frequently used in image processing, including lena, baboon, and F16

#### src
* img_pointer
  * You can get used to pointer by vertical mirroring, horizon mirroring, and rotating
    * 
* dct-idct
  You can understand lossy and loseless compression by practicing discrete cosine transform(DCT) and reconstruction(Inverse DCT - IDCT).
    * default : 8X8 dct block (block param : N in dct.h)
    * dct_quantization.c : reconstruct with 35dB, 58dB, 28dB, and 30dB quantization coefficient
    * idct_coefficient.c : reconstruct with input coefficient
    * dct_direction.c : dct test
    * psnr.c : you can check how similar with original image and reconstruct image
      add below code in main.c
      ```
      psnr(input, outimg);
      ```
      ```
      if (menu == 1) {
		    DCT(input, output);
		    print(output, outimg);

		    FILE * outfile = fopen("lena_defaultDCT.img", "wb");
		    fwrite(outimg, sizeof(char), HEIGHT*WIDTH, outfile);
		    psnr(input, outimg);

        fclose(outfile);
		    free(output);
		    free(outimg);

		    printf("success!");
	    }
      ```
* dft-idft
* interpolation-NN
* interpolation-bilinear
* interpolation-cubic_convolution
* interpolation-cubic_Bspline