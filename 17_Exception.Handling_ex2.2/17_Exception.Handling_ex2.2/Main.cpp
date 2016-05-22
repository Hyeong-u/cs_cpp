#include <iostream>
#include "ErrorLogic.h"

using namespace std;

static int divide(int value, int denominator, double &result);

int main(int argc, char *agrv[])
{
	double result;
	int err = divide(40, 0, result);

	if(err != ERROR_LOGIC::FAIL_LOGIC)
		cout << "Result=" << result << endl;
	
}

int divide(int value, int denominator, double &result)
{
	if (denominator == 0)
		return ERROR_LOGIC::FAIL_LOGIC;
	
	result = value / denominator;
	return ERROR_LOGIC::SUCCESS_LOGIC;
}