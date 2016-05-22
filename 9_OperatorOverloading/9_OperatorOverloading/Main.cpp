#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
using std::setw;

class PhoneNumber
{
	friend ostream &operator<<(ostream &os, const PhoneNumber &number);
	friend istream &operator>>(istream &is, PhoneNumber &number);
private:
	string areaCode;
	string exchange;
	string line;
public:
	PhoneNumber();
	PhoneNumber(const string &areaCode, const string &exchange, const string &line);
	string getAreaCode() const;
	string getExchange() const;
	string getLine() const;
	void setAreaCode(string areaCode);
	//bool operator!() const;
};
ostream &operator<<(ostream &os, const PhoneNumber &number) 
{
	os << "(" << number.areaCode << ")" << number.exchange << "-" << number.line;
	return os;
}

istream &operator>>(istream &is, PhoneNumber &number)
{
	is.ignore();
	is >> setw(3) >> number.areaCode;
	is.ignore(2);
	is >> setw(3) >> number.exchange;
	is.ignore();
	is >> setw(4) >> number.line;
	return is;
}

PhoneNumber::PhoneNumber()
{
}

PhoneNumber::PhoneNumber(const string &areaCode, const string &exchange, const string &line)
{
	this->areaCode = areaCode;
	this->exchange = exchange;
	this->line = line;
}

string PhoneNumber::getAreaCode() const // 내 몸에 있는 것을 바꾸지 않겠다. 그래서 엑세서에는 기본적으로 const를 붙여 놓는다.
{
	return areaCode;
}

string PhoneNumber::getExchange() const
{
	return exchange;
}

string PhoneNumber::getLine() const
{
	return line;
}

void PhoneNumber::setAreaCode(string areaCode)
{
	this->areaCode = areaCode;
}



class Rect
{
private:
	int area;
public:
	Rect();
	Rect(int area);
	int getArea();
	int operator+(const Rect &r);
};
Rect::Rect()
{
	area = 0;
}

Rect::Rect(int area)
{
	this->area = area;
}
int Rect::getArea()
{
	return area;
}
int Rect::operator+(const Rect &r)
{
	return this->area + r.area;
}

class Money
{
	friend ostream &operator<<(ostream &os, const Money &money);
public:
	Money();
	Money(int d, int c);
	Money(int allc);

	double getAmount();
	void printMoney();
	Money operator+(const Money &m);

private:
	int dollar;
	int cent;
};

ostream &operator<<(ostream &os, const Money &money)
{
	os << "$" << (double)money.dollar + (double)money.cent*0.01 << endl;
	return os;
}


Money::Money()
{
	dollar = 0;
	cent = 0;
}

Money::Money(int d, int c)
{
	dollar = d;
	cent = c;
}

double Money::getAmount() 
{
	double dcent = 0.01 * cent;
	return (double)dollar + dcent;
}

void Money::printMoney()
{
	cout << "$" << getAmount() << endl;
}

Money Money::operator+(const Money &m)
{
	Money m3(this->dollar + m.dollar, this->cent + m.cent);
	return m3;
}


int main(int argc, char* argv[])
{

	Money m1(3, 25), m2(19, 5);
	Money m3 = m1 + m2;
	m3.printMoney();
	cout << m1;
	/*
	Rect r1(40), r2(80);
	cout << r1 + r2 << endl;
	*/
	/*
	string areaCode;
	PhoneNumber *number = new PhoneNumber("123", "456", "7890");
	PhoneNumber number2;

	cout << *number << endl;
	delete number;
	*/
	
	/*
	cout << "(" << number->getAreaCode() << ")";
	cout << number->getExchange() << "-";
	cout << number->getLine() << endl;

	cin.ignore();
	cin >> setw(3) >> areaCode;
	number->setAreaCode(areaCode);

	cout << "(" << number->getAreaCode() << ")";
	cout << number->getExchange() << "-";
	cout << number->getLine() << endl;
	*/
}