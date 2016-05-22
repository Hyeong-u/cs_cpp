#include <iostream>

using namespace std;

static double divide(int value, int denominator);

int main(int argc, char *agrv[])
{
	double result = divide(40, 20);
	cout << "Result=" << result << endl;

	result = divide(40, 0);
	cout << "Result=" << result << endl;
}

double divide(int value, int denominator)
{
	if (denominator == 0)
		exit(1);
	/*
	if (denominator == 0)
		abort(); // runtime시 디버그용
		*/
	return value / denominator;
}