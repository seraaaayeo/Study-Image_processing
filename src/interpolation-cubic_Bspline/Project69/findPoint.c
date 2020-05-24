#include "Bspline.h"

double findPoint(double f1, double f2, double f3, double f4, double t)
{
	/*  Xk;	//������ �� X(k)
		f1, f2, f3, f4;	//������ ���� ������ ��ġ�� �ֺ� �ȼ��� 4��
		t;	//������ �� f�� �ֺ� �ȼ� 4�� �� ������ 1������ �Ÿ�
		c1, c2, c3, c4;	//����ġ �Լ��� �������� �� t�� ���	*/

	double Xk, c1, c2, c3, c4;
	
	c1 = f1 + 4 * f2 + f3;
	c2 = -3 * f1 + 3 * f3;
	c3 = 3 * f1 - 6 * f2 + 3 * f3;
	c4 = -f1 + 3 * f2 - 3 * f3 + f4;

	Xk = (c1 + t * (c2 + t * (c3 + t * c4))) / 6;
	
	/*
	c1 = -4 * f1 + f2 + 4 * f3 - 4 * f4;
	c2 = 3 * f2 - 3 * f4;
	c3 = 3 * f2 - 6 * f3 + 3 * f4;
	c4 = f1 - 3 * f2 + 3 * f3 - f4;

	f = (c1 + t * (c2 + t * (c3 + t * c4))) / 6;
	*/
	return Xk;

}
