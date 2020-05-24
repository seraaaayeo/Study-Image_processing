#include "cc.h"

void bicubicUp(unsigned char * input, unsigned char * output)

{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	double tx, ty, dx, dy;
	double p1, p2, p3, p4;
	double v1, v2, v3, v4, v;

	double org_size = 512;
	double new_size = 1000;
	double ratio = new_size / org_size;
	double delta = org_size / new_size;

//	double ratio = newWIDTH / WIDTH;
//	double delta = WIDTH / newWIDTH;
//	double ratio = UPSIZE / WIDTH;
//	double delta = WIDTH / UPSIZE;

	unsigned char * temp;
//	temp = (unsigned char*)malloc(sizeof(unsigned char)*newWIDTH*newHEIGHT);
	temp = (unsigned char*)malloc(sizeof(unsigned char)*UPSIZE*UPSIZE);

//	for (int i = 0; i < newHEIGHT; i++) {
//		for (int j = 0; j < newWIDTH; j++) {
	for (int i = 0; i < UPSIZE; i++) {
		for (int j = 0; j < UPSIZE; j++) {
			dy = i * delta;	//(dx, dy) = (0,0) ~ (������ ���� x��ǥ, y��ǥ)�Ÿ�
			dx = j * delta;

			//	������ ���� ������ ��ġ�� �ֺ� 16���� �ȼ��� ����	//
			//	x���� 4�� ����	//
			x2 = (int)(dx);		//x2�� ������ ���� ���� ����� ���� �ȼ��� ����

			if (x2 == 0)
				x1 = 0;
			else
				x1 = x2 - 1;

			if (x2 == WIDTH - 1) {
				x3 = WIDTH - 1;
				x4 = WIDTH - 1;
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
			if (y2 == HEIGHT - 1) {
				y3 = HEIGHT - 1;
				y4 = HEIGHT - 1;
			}
			else {
				y3 = y2 + 1;
				y4 = y2 + 2;
			}
			ty = dy - y2;



			//	x�������� 4���� ���� �����Ͽ� 4���� ������ ����	//
			p1 = *(input + y1 * WIDTH + x1);
			p2 = *(input + y1 * WIDTH + x2);
			p3 = *(input + y1 * WIDTH + x3);
			p4 = *(input + y1 * WIDTH + x4);

			v1 = find(p1, p2, p3, p4, tx);
			
			//p1, p2, p3, p4 = 0;

			p1 = *(input + y2 * WIDTH + x1);
			p2 = *(input + y2 * WIDTH + x2);
			p3 = *(input + y2 * WIDTH + x3);
			p4 = *(input + y2 * WIDTH + x4);

			v2 = find(p1, p2, p3, p4, tx);
			//p1, p2, p3, p4 = 0;

			p1 = *(input + y3 * WIDTH + x1);
			p2 = *(input + y3 * WIDTH + x2);
			p3 = *(input + y3 * WIDTH + x3);
			p4 = *(input + y3 * WIDTH + x4);

			v3 = find(p1, p2, p3, p4, tx);
			//p1, p2, p3, p4 = 0;

			p1 = *(input + y4 * WIDTH + x1);
			p2 = *(input + y4 * WIDTH + x2);
			p3 = *(input + y4 * WIDTH + x3);
			p4 = *(input + y4 * WIDTH + x4);

			v4 = find(p1, p2, p3, p4, tx);

			//	������ 4���� �������� y�������� �� �� �� ����	//
			v = find(v1, v2, v3, v4, ty);

			*(temp + i * UPSIZE + j) = (unsigned char)(v + 0.5);
//			*(output + i * UPSIZE + j) = (unsigned char)(v);
		}
	}
	for (int i = 0; i < UPSIZE; i++) {
		for (int j = 0; j < UPSIZE; j++) {
			*(output + i * UPSIZE + j) = *(temp + i * UPSIZE + j);
		}
	}
	/*
	for (int i = 0; i < newWIDTH; i++) {
		for (int j = 0; j < newWIDTH; j++) {
			*(output + i * WIDTH + j) = *(temp + i * newWIDTH + j);
		}
	}
	*/
}