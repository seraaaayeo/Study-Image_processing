#include "Bspline.h"

void BUptoDown(unsigned char * input, unsigned char * output)

{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	double tx, ty, dx, dy;
	double p1, p2, p3, p4;
	double v1, v2, v3, v4, v;

	double org_size = 1000;
	double new_size = 512;
	double ratio = new_size / org_size;
	double delta = org_size / new_size;

	unsigned char * temp;
	temp = (unsigned char*)malloc(sizeof(unsigned char)*REDOWN*REDOWN);

	for (int i = 0; i < REDOWN; i++) {
		for (int j = 0; j < REDOWN; j++) {
			dy = i * delta;	//(dx, dy) = (0,0) ~ (������ ���� x��ǥ, y��ǥ)�Ÿ�
			dx = j * delta;

			//	������ ���� ������ ��ġ�� �ֺ� 16���� �ȼ��� ����	//
			//	x���� 4�� ����	//
			x2 = (int)(dx);		//x2�� ������ ���� ���� ����� ���� �ȼ��� ����

			if (x2 == 0)
				x1 = 0;
			else
				x1 = x2 - 1;
			if (x2 == UPSIZE - 1) {
				x3 = UPSIZE - 1;
				x4 = UPSIZE - 1;
			}
			else {
				x3 = x2 + 1;
				x4 = x2 + 2;
			}
			tx = dx - x2;

			//	y���� 4�� ����	//
			y2 = (int)(dy);
			if (y2 == 0)
				y1 = 0;
			else
				y1 = y2 - 1;
			if (y2 == UPSIZE - 1) {
				y3 = UPSIZE - 1;
				y4 = UPSIZE - 1;
			}
			else {
				y3 = y2 + 1;
				y4 = y2 + 2;
			}
			ty = dy - y2;

			//	x�������� 4���� ���� �����Ͽ� 4���� ������ ����	//
			p1 = *(input + y1 * UPSIZE + x1);
			p2 = *(input + y1 * UPSIZE + x2);
			p3 = *(input + y1 * UPSIZE + x3);
			p4 = *(input + y1 * UPSIZE + x4);

			v1 = findPoint(p1, p2, p3, p4, tx);
//			printf("check : %lf\n", v1);
			p1, p2, p3, p4 = 0;

			p1 = *(input + y2 * UPSIZE + x1);
			p2 = *(input + y2 * UPSIZE + x2);
			p3 = *(input + y2 * UPSIZE + x3);
			p4 = *(input + y2 * UPSIZE + x4);

			v2 = findPoint(p1, p2, p3, p4, tx);
			p1, p2, p3, p4 = 0;

			p1 = *(input + y3 * UPSIZE + x1);
			p2 = *(input + y3 * UPSIZE + x2);
			p3 = *(input + y3 * UPSIZE + x3);
			p4 = *(input + y3 * UPSIZE + x4);

			v3 = findPoint(p1, p2, p3, p4, tx);
			p1, p2, p3, p4 = 0;

			p1 = *(input + y4 * UPSIZE + x1);
			p2 = *(input + y4 * UPSIZE + x2);
			p3 = *(input + y4 * UPSIZE + x3);
			p4 = *(input + y4 * UPSIZE + x4);

			v4 = findPoint(p1, p2, p3, p4, tx);

			//	������ 4���� �������� y�������� �� �� �� ����	//
			v = findPoint(v1, v2, v3, v4, ty);

			*(temp + i * REDOWN + j) = (unsigned char)(v + 0.5);
		}
	}

	for (int i = 0; i < REDOWN; i++) {
		for (int j = 0; j < REDOWN; j++) {
			*(output + i * WIDTH + j) = *(temp + i * REDOWN + j);
		}
	}

}