#include <iostream>
using namespace std;

class Robot 
{
public:
	static const int num = 0;
	static int numRobots;

	static void initializeRobot() {
		numRobots++;
	}
};

int Robot::numRobots = 100;

class Circle
{
private:
	double radius;
public:
	Circle();
	Circle(int r);
	void setRadius(double r);
	double getDiameter();
	double getArea();
	double getCircumference();
};
Circle::Circle()
{
	radius = 0.0;
}

Circle::Circle(int r)
{
	radius = r;
}

void Circle::setRadius(double r)
{
	radius = r;
}

double Circle::getDiameter()
{
	return radius * 2;
}

double Circle::getArea()
{
	return radius * radius * (22.0 / 7);
}

double Circle::getCircumference()
{
	return 2 * radius * (22.0 / 7);
}

class Time
{
private:
	int *hour, *minute, *second;
public:
	Time();
	Time(int h, int m, int s);

	void printTime();
	void setTime(int h, int m, int s);
	int getHour() 
	{ 
		return *hour; 
	}
	int getMinute() 
	{ 
		return *minute; 
	}
	int getSecond()
	{
		return *second;
	}
	void setHour(int h)
	{
		*hour = h;
	}
	void setMinute(int m)
	{
		*minute = m;
	}
	void setSecond(int s)
	{
		*second = s;
	}

	~Time();
};

Time::Time()
{
	hour = new int();
	minute = new int();
	second = new int();
}

Time::Time(int h, int m, int s)
{
	hour = new int(h);
	minute = new int(m);
	second = new int(s);
}

void Time::setTime(int h, int m, int s)
{
	*hour = h;
	*minute = m;
	*second = s;
}

void Time::printTime()
{
	cout << "The time is : (" << *hour << ":" << *minute << ":" << *second << ")" << endl;
}

Time::~Time()
{
	delete hour; delete minute; delete second;
}

int main(int argc, char *argv[]) {
	
	Circle *c1 = new Circle;
	Circle *c2 = new Circle(10);
	Circle c3(7);  // 이런식으로 생성자를 직접 호출하지 않고 쓴다.

	cout << "The area of c1 : " << c1->getArea() << endl;
	cout << "The area of c2 : " << c2->getArea() << endl;
	cout << "The area of c3 : " << c3.getArea() << endl;

	c1->setRadius(5);
	cout << "The area of c1 : " << (*c1).getArea() << endl; // 이렇게 접근 가능하지만 이렇게 쓰지는 않는다.
	cout << "The circumference of c1 : " << c1->getCircumference() << endl;
	cout << "The Diameter of c2 : " << c2->getDiameter() << endl;

	delete c1;
	delete c2;



	/*
	std::cout << Robot::num << std::endl;
	std::cout << Robot::numRobots << std::endl;

	Robot *r1 = new Robot;
	Robot r2;
	r1->numRobots = 200;
	std::cout << "Robot2 ::numRobots = " << r2.numRobots << std::endl;

	r1->numRobots = 400;
	std::cout << "Robot1 ::numRobots = " << r1->numRobots << std::endl;

	Robot::initializeRobot();
	std::cout << "Robot2 ::numRobots = " << r2.numRobots << std::endl;
	
	delete r1;
	return 0;
	*/
}