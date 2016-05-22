#include <iostream>


using namespace std;

static int divide(int value, int denominator);

int main(int argc, char *agrv[])
{
	/*
	try
	{
		double result = divide(40, 10);
		cout << "Result=" << result << endl;
	}
	catch (int err)
	{
		cerr << "Error! Divide by zero" << endl;
	}
	*/
	double result = divide(40, 0);
}

int divide(int value, int denominator)
{
	if (denominator == 0)
		throw - 1;

	return value / denominator;
	
}