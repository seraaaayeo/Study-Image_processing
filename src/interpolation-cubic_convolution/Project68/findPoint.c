#include "cc.h"

double find(double f1, double f2, double f3, double f4, double t)
{
	/*  f;	//보간된 점
		f1, f2, f3, f4;	//보간된 점 f에 영향을 끼치는 주변 픽셀값 4개
		t;	//보간된 점 f와 주변 픽셀 4개 중 임의의 1개와의 거리 
		c1, c2, c3, c4;	//가중치 함수를 정리했을 때 t의 계수	*/
	
	double f, c1, c2, c3, c4;

	c1 = 2 * f2;
	c2 = -f1 + f3;
	c3 = 2 * f1 - 5 * f2 + 4 * f3 - f4;
	c4 = -f1 + 3 * f2 - 3 * f3 + f4;
	
	f = (c1 + t * (c2 + t * (c3 + t * c4))) / 2;

	return f;

}