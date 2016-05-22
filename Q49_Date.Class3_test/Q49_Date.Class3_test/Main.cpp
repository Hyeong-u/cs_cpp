#include <iostream>
#include <fstream>
#include <cstdlib>
#include "myDate.h"
using namespace std;
const int yoon_day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int not_yoon_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// 생성자
myDate::myDate(int year, int month, int day) :y(year), m(month), d(day) {}
//접근자
int myDate::getDayOfMonth() const
{
	return d;
}
int myDate::getMonth() const
{
	return m;
}
int myDate::getYear() const
{
	return y;
}
//변경자
void myDate::setDayOfMonth(int day)
{
	d = day;
}
void myDate::setMonth(int month)
{
	m = month;
}
void myDate::setYear(int year)
{
	y = year;
}
void myDate::setDate(int year, int month, int day)
{
	d = day;
	m = month;
	y = year;
}

//// utility functions
bool myDate::isLeapYear() const //윤년
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}
int myDate::getDayOfWeek() const //0=Sunday, 1=Monday, ..., 6=Saturday
{
	int zellerMonth = 0;
	int zellerYear = 0;
	int year = y;
	int month = m;
	int day = d;
	if (month < 3)// 월값이 3보다 작으면 
	{
		zellerMonth = month + 12; // 월 + 12
		zellerYear = year - 1; // 연 - 1
	}
	else
	{
		zellerMonth = month;
		zellerYear = year;
	}
	int computation = day + (26 * (zellerMonth + 1)) / 10 + zellerYear + zellerYear / 4 + 6 * (zellerYear / 100) + zellerYear / 400;
	int dayOfWeek = (computation - 1) % 7;

	return dayOfWeek;
}
int myDate::getDayOfYear() const
{
	int resu = 0;
	if (this->isLeapYear() == true)//윤년일때
	{
		for (int i = 0; i < m - 1; i++)
		{
			resu += yoon_day[i];
		}
		resu += d;
	}
	else
	{
		for (int i = 0; i < m - 1; i++)
		{
			resu += not_yoon_day[i];
		}
		resu += d;
	}
	return resu;
}

int myDate::getNumHolidays() const
{
	int year = this->getYear();
	int Holidays = 0;
	if (this->isLeapYear() == true) //윤년일때
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < yoon_day[i]; j++)
			{
				myDate temp(year, i + 1, j + 1);
				if (temp.getDayOfWeek() == 0 || temp.getDayOfWeek() == 6)
					Holidays++;

			}
		}
	}
	else //윤년이 아닐때
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < not_yoon_day[i]; j++)
			{
				myDate temp(year, i + 1, j + 1);
				if (temp.getDayOfWeek() == 0 || temp.getDayOfWeek() == 6)
					Holidays++;
			}
		}
	}

	myDate temp_1(year, 1, 1), temp_2(year, 3, 1), temp_3(year, 5, 5), temp_4(year, 6, 6), temp_5(year, 7, 17), temp_6(year, 8, 15), temp_7(year, 10, 3), temp_8(year, 12, 25);
	myDate sul_1(year, 2, 1), sul_2(year, 2, 2), sul_3(year, 2, 3);
	myDate sug(year, 5, 15);
	myDate coo_1(year, 9, 15), coo_2(year, 9, 16), coo_3(year, 9, 17);
	if (temp_1.getDayOfWeek() != 0 && temp_1.getDayOfWeek() != 6) Holidays++;
	if (temp_2.getDayOfWeek() != 0 && temp_2.getDayOfWeek() != 6) Holidays++;
	if (temp_3.getDayOfWeek() != 0 && temp_3.getDayOfWeek() != 6) Holidays++;
	if (temp_4.getDayOfWeek() != 0 && temp_4.getDayOfWeek() != 6) Holidays++;
	if (temp_5.getDayOfWeek() != 0 && temp_5.getDayOfWeek() != 6) Holidays++;
	if (temp_6.getDayOfWeek() != 0 && temp_6.getDayOfWeek() != 6) Holidays++;
	if (temp_7.getDayOfWeek() != 0 && temp_7.getDayOfWeek() != 6) Holidays++;
	if (temp_8.getDayOfWeek() != 0 && temp_8.getDayOfWeek() != 6) Holidays++;
	if (sul_1.getDayOfWeek() != 0 && sul_1.getDayOfWeek() != 6) Holidays++;
	if (sul_2.getDayOfWeek() != 0 && sul_2.getDayOfWeek() != 6) Holidays++;
	if (sul_3.getDayOfWeek() != 0 && sul_3.getDayOfWeek() != 6) Holidays++;
	if (sug.getDayOfWeek() != 0 && sug.getDayOfWeek() != 6) Holidays++;
	if (coo_1.getDayOfWeek() != 0 && coo_1.getDayOfWeek() != 6) Holidays++;
	if (coo_2.getDayOfWeek() != 0 && coo_2.getDayOfWeek() != 6) Holidays++;
	if (coo_3.getDayOfWeek() != 0 && coo_3.getDayOfWeek() != 6) Holidays++;

	return Holidays;
}
int myDate::getNumSummerTimeDays() const
{
	int day_3, day_10, sum_day = 0;
	int temp_year = this->getYear();
	for (int i = 0; i < 31; i++)
	{
		myDate temp(temp_year, 3, i + 1);
		if (temp.getDayOfWeek() == 0)
			day_3 = i + 1;
	}
	for (int i = 0; i < 31; i++)
	{
		myDate temp(temp_year, 10, i + 1);
		if (temp.getDayOfWeek() == 0)
			day_10 = i;
	}
	sum_day = (yoon_day[2] - day_3 + 1) + day_10 + yoon_day[3] + yoon_day[4] + yoon_day[5] + yoon_day[6] + yoon_day[7] + yoon_day[8];
	return sum_day;
}
void myDate::printCalendarOfMonth() const
{
	myDate temp(this->getYear(), this->getMonth(), 1);
	int dow = temp.getDayOfWeek();
	int day, calrow;
	int cal[6][7] = { 0, };
	int num = 1;
	if (temp.isLeapYear() == true)//윤년이면
		day = yoon_day[this->getMonth() - 1];
	else
		day = not_yoon_day[this->getMonth() - 1];

	if (dow + day == 28)
		calrow = 4;
	else if (dow + day > 35)
		calrow = 6;
	else
		calrow = 5;

	for (int i = 0; i < dow; i++)
		cal[0][i] = 0;

	for (int j = dow; j < 7; j++)
	{
		cal[0][j] = num++;
	}

	for (int i = 1; i < calrow; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cal[i][j] = num++;
			if (num > day + 1) cal[i][j] = 0;
		}
	}
	cout << temp.getYear() << " " << temp.getMonth() << endl;

	for (int i = 0; i < calrow; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << cal[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i < numTestCases; i++)
	{
		int year, month, day;
		inStream >> year >> month >> day;
		myDate date(year, month, day);
		cout << date.getNumSummerTimeDays() << endl;
		date.printCalendarOfMonth();
	}
	inStream.close();
}