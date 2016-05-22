/*************************************************************************
*																		 *
* Problem:																 *
* 2차원 점																 *
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

class MyPoint
{
private:

public:
	int xpos, ypos;
	MyPoint();
	MyPoint(int xpos, int ypos);
	int getX();
	int getY();
	bool operator==(MyPoint &p);
};

MyPoint::MyPoint()
{
	xpos = 0;
	ypos = 0;
}

MyPoint::MyPoint(int xpos, int ypos)
{
	this->xpos = xpos;
	this->ypos = ypos;
}

int MyPoint::getX()
{
	return xpos;
}

int MyPoint::getY()
{
	return ypos;
}

bool MyPoint::operator==(MyPoint &p)
{
	if (xpos == p.xpos && ypos == p.ypos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class MyLineSegment
{
public:
	// constructors
	MyLineSegment();
	MyLineSegment(const MyPoint& p, const MyPoint& q);
	//MyLineSegment(const MyLineSegment& seg);
	// intersection test functions
	//bool isEndOfSegment(const MyPoint & p) const;
	//bool isOnSegment(const MyPoint& p) const;
	bool properIntersection(const MyLineSegment &s) const;
	bool improperIntersection(const MyLineSegment &s) const;
	//bool isLeftSide(const MyPoint &p) const; // test whether p is to the left side of the direction from p1 to p2
	//bool isCollinear(const MyPoint &p) const; // test whether p1, p2, p3 is collinear
	int check(const MyLineSegment &s) const;
	// utility functions
	//int length2sqr() const; // square of (Euclidean) length
private:
	MyPoint p1, p2;
	int getArea2(const MyPoint &p) const; // signed area of triangle p1, p2, p
};

MyLineSegment::MyLineSegment()
{
	p1 = MyPoint(0, 0);
	p2 = MyPoint(0, 0);
}

MyLineSegment::MyLineSegment(const MyPoint& p, const MyPoint& q)
{
	p1 = p;
	p2 = q;
}

bool MyLineSegment::properIntersection(const MyLineSegment &s) const
{
	int p, q, x, y;
	p = getArea2(s.p1);
	q = getArea2(s.p2);
	x = s.getArea2(p1);
	y = s.getArea2(p2);
	if (((p > 0 && q < 0)) && ((x > 0 && y < 0)))
	{
		return true;
	}
	else
		return false;
}

bool MyLineSegment::improperIntersection(const MyLineSegment &s) const
{
	if ((((getArea2(s.p1) > 0 && getArea2(s.p2) < 0) || (getArea2(s.p1) < 0 && getArea2(s.p2) > 0)) && ((s.getArea2(p1) > 0 && s.getArea2(p2) > 0) || (s.getArea2(p1) < 0 && s.getArea2(p2) < 0))) || (((s.getArea2(p1) > 0 || s.getArea2(p2) < 0) || (s.getArea2(p1) < 0 || s.getArea2(p2) > 0)) && ((s.getArea2(p1) > 0 && s.getArea2(p2) > 0) || (getArea2(s.p1) < 0 && getArea2(s.p2) < 0))))
	{
		return true;
	}
	else
		return false;
}

int MyLineSegment::check(const MyLineSegment &s) const
{
	int p, q, x, y;
	p = getArea2(s.p1);
	q = getArea2(s.p2);
	x = s.getArea2(p1);
	y = s.getArea2(p2);
	if (p == 0 || q == 0 || x == 0 || y == 0)
	{
		return 2;
	}
	if (((p > 0 && q < 0) || (p < 0 && q > 0)) && ((x > 0 && y < 0) || (x < 0 && y > 0)))
	{
		return 1;
	}
	else
		return 0;
}
int MyLineSegment::getArea2(const MyPoint &p) const // signed area of triangle p1, p2, p
{
	int p1x, p2x, px, p1y, p2y, py;
	p1x = p1.xpos;
	p1y = p1.ypos;
	p2x = p2.xpos;
	p2y = p2.ypos;
	px = p.xpos;
	py = p.ypos;
	return p1x * p2y - p1y * p2x +
		p1y * px - p1x * py +
		p2x * py - px * p2y;
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
		int a, b, c, d;
		in >> a >> b >> c >> d;
		MyPoint p(a, b), q(c, d), r(b, a);
		int equal;
		int eDistance;
		int rDistance;
		if (p == q)
		{
			equal = 1;
			cout << equal << " ";
		}
		else
		{
			equal = 0;
			cout << equal << " ";
		}
		eDistance = (p.xpos - q.xpos)*(p.xpos - q.xpos) + (p.ypos - q.ypos)*(p.ypos - q.ypos);
		rDistance = abs(p.xpos - q.xpos) + abs(p.ypos - q.ypos);


		cout << eDistance << " " << rDistance << " "; /* print out*/
		eDistance = (p.xpos - r.xpos)*(p.xpos - r.xpos) + (p.ypos - r.ypos)*(p.ypos - r.ypos);
		rDistance = abs(p.xpos - r.xpos) + abs(p.ypos - r.ypos);
		cout << eDistance << " " << rDistance << endl;
	}
	in.close(); /* close input file */
	return 0;
}