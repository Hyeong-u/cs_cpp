#include <iostream>

using namespace std;

class Shape
{
public:
	virtual double circumference() = 0;
	virtual double surface() = 0;
	virtual double diameter() = 0;
	virtual void display() = 0;
};

class Rectangle : public Shape
{
private:
	double height;
	double width;
public:
	Rectangle(double height, double width);
	virtual double circumference();
	virtual double surface();
	virtual double diameter();
	virtual void display();
};

Rectangle::Rectangle(double height, double width)
{
	this->height = height;
	this->width = width;
}

double Rectangle::circumference() 
{
	return 2 * (height + width);
}

double Rectangle::surface()
{
	return height * width;
}

double Rectangle::diameter()
{
	return sqrt(height*height + width * width);
}

void Rectangle::display()
{
	cout << "Shape: diameter: " << diameter() << ", circumference: " << circumference() << ", surface: " << surface() << endl;
}

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double radius);
	virtual double circumference();
	virtual double surface();
	virtual double diameter();
	virtual void display();
};

Circle::Circle(double radius)
{
	this->radius = radius;
}

double Circle::circumference()
{
	return diameter() * 3.14159;
}

double Circle::surface()
{
	return 3.14159 * radius * radius;
}

double Circle::diameter()
{
	return 2 * radius;
}

void Circle::display()
{
	cout << "Shape: diameter: " << diameter() << ", circumference: " << circumference() << ", surface: " << surface() << endl;
}

class Window
{
private:
	int size;
	int index;
	Shape** shapes;
public:
	Window(const int size);
	~Window();

	void addShape(Shape* shape);
	void drawAll();
	void removeAll();
};

Window::Window(const int size)
{
	this->size = size;
	index = -1;
	shapes = new Shape*[size];
}

Window::~Window()
{
	removeAll();
	delete[] shapes;
}

void Window::addShape(Shape* shape)
{
	if (index >= size)
		return;
	shapes[++index] = shape;
}

void Window::drawAll()
{
	for (int i = 0; i <= index; i++)
	{
		shapes[i]->display();
	}
}

void Window::removeAll()
{
	for (int i = 0; i <= index; i++)
	{
		delete shapes[i];
	}
	index = -1;
}

int main()
{
	Window window(5);
	window.addShape(new Circle(1.0));
	window.addShape(new Circle(2.0));
	window.addShape(new Circle(3.5));
	window.addShape(new Rectangle(4.0, 3.5));
	window.addShape(new Rectangle(14.0, 13.5));

	window.drawAll();
	window.removeAll();
}