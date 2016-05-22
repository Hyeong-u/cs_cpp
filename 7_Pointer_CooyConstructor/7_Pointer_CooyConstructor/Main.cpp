#include <iostream>

using namespace std;

class Circle
{
public:
	double radius;

	Circle(int radius = 10);
	~Circle(){}
	double getDiameter();
	double getArea();
	double getCircumference();
	void setRadius(double r);
};

Circle::Circle(int radius)
{
	this->radius = radius;
}

double Circle::getArea()
{
	return radius * radius * 3.14;
}

double Circle::getCircumference()
{
	return 2 * radius * 3.14;
}

double Circle::getDiameter()
{
	return radius * 2;
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

class Rectangle
{
public:
	double height;
	double width;
	Circle *circleInner;

public:
	Rectangle(double height = 10, double width = 10)
	{
		this->height = height;
		this->width = width;
		//circleInner -> radius = height;
		circleInner = new Circle(height);
	}
	Rectangle(const Rectangle &rectange)  // copy constructor
	{
		circleInner = new Circle(height);
		*circleInner = *rectange.circleInner;
	}
	~Rectangle()
	{
		cout << "Destructor for Rectangle" << endl;
		delete circleInner;
	}
	void print()
	{
		/*
		cout << "height:" << height << " width:" << width << endl;
		cout << "The area of InnerCricle: " << circleInner.getArea() << endl;
		cout << "The circumference of InnerCircle: " << circleInner.getCircumference() << endl;
		cout << "The Diameter of InnerCircle: " << circleInner.getDiameter() << endl;
		*/
	}
	double calculateArea()
	{
		return height * width;
	}
};

int main()
{
	Rectangle rect1(400, 400);
	Rectangle rect2 = rect1;

	cout << (*rect1.circleInner).radius << endl;
	cout << (*rect2.circleInner).radius << endl;

	cout << &rect1.circleInner << endl;
	cout << &rect2.circleInner << endl;

	cout << &rect1.circleInner->radius << endl;
	cout << &rect2.circleInner->radius << endl;

	rect1.circleInner->radius = 999;
	cout << (*rect1.circleInner).radius << endl;
	cout << (*rect2.circleInner).radius << endl;

	cout << &rect1.circleInner << endl;
	cout << &rect2.circleInner << endl;

	cout << &rect1.circleInner->radius << endl;
	cout << &rect2.circleInner->radius << endl;




	/*
	Circle circle1(15);

	Circle circle2 = circle1;

	cout << circle1.radius << endl;
	cout << circle2.radius << endl;

	cout << &circle1.radius << endl;
	cout << &circle2.radius << endl;

	circle1.radius = 999;

	cout << circle1.radius << endl;
	cout << circle2.radius << endl;

	cout << &circle1.radius << endl;
	cout << &circle2.radius << endl;
	*/

	

}