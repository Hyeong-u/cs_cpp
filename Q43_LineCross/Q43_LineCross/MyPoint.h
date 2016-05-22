#ifndef _MY_POINT_H_
#define _MY_POINT_H_

class MyPoint
{
private:
	int x;
	int y;
public:
	MyPoint(int x, int y);
	int getX();
	int getY();
};

MyPoint::MyPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

int MyPoint::getX()
{
	return x;
}

int MyPoint::getY()
{
	return y;
}

#endif