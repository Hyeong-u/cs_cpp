/*************************************************************************
*																		 *
* Problem:																 *
* Date Class 1															 *
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
using namespace std;

class myDate
{
private:
	const static int normalYear[12];
	const static int leapYear[12];
	const static int dayOfTheWeek[7];
	int year;
	int month;
	int day;
	//int dayOfWeek;
public:
	myDate(int year, int month, int day);
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;
	bool isLeapYear() const;
	int getDayOfWeek() const;
	

};

const int myDate::normalYear[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int myDate::leapYear[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int myDate::dayOfTheWeek[] = { 4, 5, 6, 0, 1, 2, 3 };

myDate::myDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

int myDate::getDayOfMonth() const
{
	return day;
}

int myDate::getMonth() const
{
	return month;
}

int myDate::getYear() const
{
	return year;
}

bool myDate::isLeapYear() const
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int myDate::getDayOfWeek() const
{
	int idx = 0;
	int Sum = 0;
	for (int j = 1582; j < year; j++)
	{
		if (j % 400 == 0 || (j % 100 != 0 && j % 4 == 0)) // 윤년
		{
			Sum += 366;
		}
		else // 평년
		{
			Sum += 365;
		}
	}

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		for (int j = 0; j < month - 1; j++)
		{
			Sum += leapYear[j];
		}
	}
	else
	{
		for (int j = 0; j < month - 1; j++)
		{
			Sum += normalYear[j];
		}
	}

	Sum += day;
	idx = Sum % 7;
	return dayOfTheWeek[idx];
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
		int year, month, day;
		for (size_t j = 0; j < 3; j++)
		{
			in >> year >> month >> day;

			myDate date(year, month, day);

			cout << date.getYear() << " " << date.getMonth() << " " << date.getDayOfMonth() << endl;
			cout << date.isLeapYear() << " " << date.getDayOfWeek() << endl;
		}
	}
	in.close(); /* close input file */
	return 0;
}