#include "cc.h"

double find(double f1, double f2, double f3, double f4, double t)
{
	/*  f;	//������ ��
		f1, f2, f3, f4;	//������ �� f�� ������ ��ġ�� �ֺ� �ȼ��� 4��
		t;	//������ �� f�� �ֺ� �ȼ� 4�� �� ������ 1������ �Ÿ� 
		c1, c2, c3, c4;	//����ġ �Լ��� �������� �� t�� ���	*/
	
	double f, c1, c2, c3, c4;

	c1 = 2 * f2;
	c2 = -f1 + f3;
	c3 = 2 * f1 - 5 * f2 + 4 * f3 - f4;
	c4 = -f1 + 3 * f2 - 3 * f3 + f4;
	
	f = (c1 + t * (c2 + t * (c3 + t * c4))) / 2;

	return f;

}