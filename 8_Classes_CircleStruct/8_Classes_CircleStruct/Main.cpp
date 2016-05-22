#include <iostream>
using namespace std;

struct Circle
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

int main(int argc, char *argv[]) {
	Circle *c1 = new Circle;
	Circle *c2 = new Circle(10);
	Circle c = Circle(5);

	cout << "The area of c1 : " << c1->getArea() << endl;
	cout << "The area of c2 : " << c2->getArea() << endl;

	c1->setRadius(5);
	cout << "The area of c1 : " << (*c1).getArea() << endl; // 이렇게 접근 가능하지만 이렇게 쓰지는 않는다.
	cout << "The circumference of c1 : " << c1->getCircumference() << endl;
	cout << "The Diameter of c2 : " << c2->getDiameter() << endl;

	delete c1;
	delete c2;
}