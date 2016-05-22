/*************************************************************************
*																		 *
* Problem:																 *
* 삼각형																 *
*																		 *
*************************************************************************/
/*************************************************************************
*																		 *
* 국민대학교 전자정보통신대학 컴퓨터공학부 2 학년						 *
* 20153168 김형우														 *
*																		 *
*************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Triangle
{
private:
	int p1x, p1y, p2x, p2y, p3x, p3y;
	int tx, ty;
	int l1, l2, max;
public:
	Triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int tx, int ty);
	int area2();
	int getArea2();
	int signedArea2(int ax, int ay, int bx, int by, int cx, int cy);
	bool isTri(); // 삼각형 True, 아니면 False
	int determine(); // 정(1), 직각/직각이등변(2), 이등변(3), 일반(4)
	int determine2(); // 직각(1), 둔각(2), 예각(3)
	int determine3(); // 내부(1), 변(2), 외부(3)

};

Triangle::Triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int tx, int ty)
{
	int temp = 0;
	this->p1x = p1x;
	this->p1y = p1y;
	this->p2x = p2x;
	this->p2y = p2y;
	this->p3x = p3x;
	this->p3y = p3y;
	this->tx = tx;
	this->ty = ty;
	l1 = (p2x - p1x)*(p2x - p1x) + (p2y - p1y)*(p2y - p1y);
	l2 = (p3x - p1x)*(p3x - p1x) + (p3y - p1y)*(p3y - p1y);
	max = (p2x - p3x)*(p2x - p3x) + (p2y - p3y)*(p2y - p3y);
	if (max < l1)
	{
		temp = max;
		max = l1;
		l1 = temp;
	}
	if (max < l2)
	{
		temp = max;
		max = l2;
		l2 = temp;
	}
}

int Triangle::area2()
{
	return p1x * p2y - p1y * p2x +
		p1y * p3x - p1x * p3y +
		p2x * p3y - p3x * p2y;
}

int Triangle::getArea2()
{
	return abs(area2());
}

int Triangle::signedArea2(int ax, int ay, int bx, int by, int cx, int cy)
{
	return (bx - ax)*(cy - ay) - (cx - ax)*(by - ay);
}

bool Triangle::isTri()
{
	double L1, L2, MAX;
	L1 = sqrt(l1);
	L2 = sqrt(l2);
	MAX = sqrt(max);
	if (MAX < L1+L2 || getArea2() != 0)
	{
		return true;
	}
	return false;
}

int Triangle::determine()
{
	if (l1 == l2 == max)
	{
		return 1;
	}
	if (max == l1 + l2)
	{
		return 2;
	}
	if (l1 == l2 || l1 == max || l2 == max)
	{
		if (max == l1 + l2)
		{
			return 2;
		}
		return 3;
	}
	return 4;
}

int Triangle::determine2()
{
	if (max == l1 + l2)
	{
		return 1;
	}
	if (max > l1 + l2)
	{
		return 2;
	}
	return 3;
}

int Triangle::determine3()
{
	int r1, r2, r3;
	r1 = signedArea2(p1x, p1y, p2x, p2y, tx, ty);
	r2 = signedArea2(p2x, p2y, p3x, p3y, tx, ty);
	r3 = signedArea2(p3x, p3y, p1x, p1y, tx, ty);
	if (r1 == 0 || r2 == 0 || r3 == 0)
	{
		return 2;
	}
	if ((r1 > 0 && r2 > 0 && r3 > 0) || (r1 < 0 && r2 < 0 && r3 < 0))
	{
		return 1;
	}
	return 3;
}

int main()
{
	ifstream in;
	int numTestCases;
	in.open("input.txt"); /* open input file */
	if (in.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		int p1x, p1y, p2x, p2y, p3x, p3y;
		int tx, ty;
		in >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y >> tx >> ty;
		Triangle tri(p1x, p1y, p2x, p2y, p3x, p3y, tx, ty);
		if (tri.isTri())
		{
			cout << tri.getArea2() << " " << tri.determine() << " " << tri.determine2() << " " << tri.determine3() << endl;
			continue;
		}

		cout << '0' << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}