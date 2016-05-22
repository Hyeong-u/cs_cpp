/*************************************************************************
*																		 *
* Problem:																 *
* Date Class 2															 *
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
	const static int normalHoliday[15];
	const static int leapHoliday[15];
	int year;
	int month;
	int day;
	//int dayOfWeek;
public:
	myDate(int year, int month, int day);
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;
	void setDayOfMonth(int day);
	bool isLeapYear() const;
	int getDayOfWeek() const;
	int getDayOfYear() const;
	int getNumHolidays() const;
};

const int myDate::normalYear[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int myDate::leapYear[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int myDate::dayOfTheWeek[] = { 4, 5, 6, 0, 1, 2, 3 };
const int myDate::normalHoliday[] = { 1, 32, 33, 34, 60, 125, 135, 157, 198, 227, 258, 259, 260, 276, 359 };
const int myDate::leapHoliday[] = { 1, 32, 33, 34, 61, 126, 136, 158, 199, 228, 259, 260, 261, 277, 360 };
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

void myDate::setDayOfMonth(int day)
{
	this->day = day;
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

int myDate::getDayOfYear() const
{
	int result = 0;
	if (isLeapYear())
	{
		for (int i = 0; i < month - 1; i++)
		{
			result += leapYear[i];
		}
		result += day;
		return result;
	}
	for (int i = 0; i < month - 1; i++)
	{
		result += normalYear[i];
	}
	result += day;
	return result;
}

int myDate::getNumHolidays() const
{
	myDate date(year, 1, 1);
	int dayOfWeek = date.getDayOfWeek() - 1;
	int result = 0;
	int numOfLegalHolidays = 15;
	if (isLeapYear())
	{
		for (size_t i = 1; i < 367; i++)
		{
			if ((dayOfWeek + i) % 7 == 0 || (dayOfWeek + i) % 7 == 6)
			{
				result++;
			}
		}
		for (size_t i = 0; i < 15; i++)
		{
			if ((dayOfWeek + leapHoliday[i]) % 7 == 0 || (dayOfWeek + leapHoliday[i]) % 7 == 6)
			{
				numOfLegalHolidays--;
			}
		}
		return result + numOfLegalHolidays;
	}

	for (size_t i = 1; i < 366; i++)
	{
		if ((dayOfWeek + i) % 7 == 0 || (dayOfWeek + i) % 7 == 6)
		{
			result++;
		}
	}
	for (size_t i = 0; i < 15; i++)
	{
		if ((dayOfWeek + normalHoliday[i]) % 7 == 0 || (dayOfWeek + normalHoliday[i]) % 7 == 6)
		{
			numOfLegalHolidays--;
		}
	}
	return result + numOfLegalHolidays;

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
		in >> year >> month >> day;
		myDate date(year, month, day);
		cout << date.getDayOfYear() << " " << date.getNumHolidays() << endl;
	}
	in.close(); /* close input file */
	return 0;
}