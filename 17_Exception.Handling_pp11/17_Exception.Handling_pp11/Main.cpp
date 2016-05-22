#include <iostream>
#include <cstdlib>

using namespace std;
int function(int n);
double function(double n);

int main(int argc, char* argv[])
{
	try
	{
		throw 'e';
	}
	catch (int)
	{
		cerr << "Caught Integer!" << endl;
	}
	catch (double)
	{
		cerr << "Caught Double!" << endl;
	}
	catch (...)
	{
		cerr << "Caught Default Exception!" << endl;
	}

	/*
	int x = 15;
	int y = 40;
	try
	{
		if (x > 10)
			throw 10;
		if (y > 20)
			throw 20;
	}
	catch (int e)
	{
		cerr << "Caught Exception: " << e << endl;
	}
	return 0;
	*/
	/*
	try
	{
		try
		{
			throw function(10);
		}
		catch (int e)
		{
			cerr << "Caught Integer1: " << e << endl;
		}
	}
	catch (int e)
	{
		cerr << "Caught Integer2: " << e << endl;
	}
	catch (double e)
	{
		cerr << "Caught Double: " << e << endl;
	}
	*/
	/*
	try
	{
		throw 10;
	}
	catch (int e)
	{
		cerr << "We have a problem: " << e << endl;
	}
	*/
	return 0;
}

int function(int n)
{
	return n;
}

double function(double n)
{
	return n;
}