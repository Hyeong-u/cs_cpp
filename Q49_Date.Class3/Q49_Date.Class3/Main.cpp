/*************************************************************************
*																		 *
* Problem:																 *
* Date Class 3															 *
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
	bool isLeapYear() const; //윤년
	int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
	int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
	int getNumHolidays() const; //휴일수 계산
	int getNumSummerTimeDays()const; //써머타임 날짜수
	void printCalendarOfMonth() const; // 달력출력하기
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

int myDate::getNumSummerTimeDays() const
{
	int march;
	int october;
	myDate date(year, 1, 1);
	int dayOfWeek = date.getDayOfWeek() - 1;
	if (isLeapYear())
	{
		for (size_t i = 1; i < 32; i++)
		{
			if ((dayOfWeek + 60 + i) % 7 == 0)
			{
				march = 60 + i;
			}
			if ((dayOfWeek + 274 + i) % 7 == 0)
			{
				october = 274 + i;
			}
		}
		return october - march;
	}
	for (size_t i = 1; i < 32; i++)
	{
		if ((dayOfWeek + 59 + i) % 7 == 0)
		{
			march = 60 + i;
		}
		if ((dayOfWeek + 273 + i) % 7 == 0)
		{
			october = 274 + i;
		}
	}
	return october - march;
	
}

void myDate::printCalendarOfMonth() const
{
	myDate date(year, month, 1);
	int dayOfWeek = date.getDayOfWeek();
	cout << year << ' ' << month << endl;
	int k = 1;
	if (isLeapYear()) // 윤년
	{
		for (int j = 0; j < dayOfWeek; j++)
		{
			cout << '0' << ' ';
		}
		while (k < leapYear[month - 1])
		{
			if (dayOfWeek == 6)
			{
				cout << k << endl;
				k++;
				dayOfWeek = 0;
			}
			else
			{
				cout << k << ' ';
				k++;
				dayOfWeek++;
			}
		}
		if (dayOfWeek == 6)
		{
			cout << k << endl;
		}
		else
		{
			cout << k << ' ';
			for (int j = 0; j < 5 - dayOfWeek; j++)
			{
				cout << '0' << ' ';
			}
			cout << '0' << endl;
		}
		//0 -> 6 1-> 5 ... 6 -> 0
	}
	else // 평년
	{
		for (int j = 0; j < dayOfWeek; j++)
		{
			cout << '0' << ' ';
		}
		while (k < normalYear[month - 1])
		{
			if (dayOfWeek == 6)
			{
				cout << k << endl;
				k++;
				dayOfWeek = 0;
			}
			else
			{
				cout << k << ' ';
				k++;
				dayOfWeek++;
			}
		}
		if (dayOfWeek == 6)
		{
			cout << k << endl;
		}
		else
		{
			cout << k << ' ';
			for (int j = 0; j < 5 - dayOfWeek; j++)
			{
				cout << '0' << ' ';
			}
			cout << '0' << endl;
		}
	}
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
		cout << date.getNumSummerTimeDays() << endl;
		date.printCalendarOfMonth();
	}
	in.close(); /* close input file */
	return 0;
}