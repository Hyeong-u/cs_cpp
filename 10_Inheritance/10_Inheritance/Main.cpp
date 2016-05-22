#include <iostream>
#include "Y.h"
#include "X.h"

using namespace std;
class BaseClass
{
	int data;
public:
	BaseClass();
	~BaseClass();
};

BaseClass::BaseClass()
{
	cout << "ctor for BaseClass" << endl;
}
BaseClass::~BaseClass()
{
	cout << "dtor for BaseClass" << endl;
}


class SubClass : public BaseClass  // SubClass에서 BaseClass가 보인다. 그래서 SubClass→BaseClass
{								   // 보인다라함은 그 안에 있는 것을 쓸 수 있다는 것.
	int data;
public:
	SubClass();
	~SubClass();
};

SubClass::SubClass()
{
	cout << "ctor for SubClass" << endl;
}

SubClass::~SubClass()
{
	cout << "dtor for SubClass" << endl;
}

class BaseClassA
{
public:
	void someFunction();
};

void BaseClassA::someFunction()
{
	cout << "SomeFunction in BaseClassA" << endl;
}

class BaseClassB
{
public:
	void someFunction();
};

void BaseClassB::someFunction()
{
	cout << "SomeFunction in BaseClassA" << endl;
}

class SubClassA : public BaseClassA, public BaseClassB
{
public:
	void theFunction();
};

void SubClassA::theFunction()
{
	BaseClassB::someFunction();
}

class Person
{
protected:
	char* name;
private:
	int age;
	//char* name;
	char gender;
public:
	Person() {}
	Person(char* name);
	char* getName();
};

Person::Person(char* name)
{
	this->name = name;
}

char* Person::getName()
{
	return name;
}

class Employee : public Person
{
private:
	char* department;
	int employeeCode;
public:
	Employee(char* name);

public:
	char* getDepartment();
	int getEmployeeCode();
	void setEmployeeCode(int employeeCode);
	void setDepartment(char* department);
};

Employee::Employee(char* name)
	//:name(name)
	//:Person(name) // super class의 citor를 호출할 때
{
	this->name = name;
}

int Employee::getEmployeeCode()
{
	return employeeCode;
}

char* Employee::getDepartment()
{
	return department;
}

void Employee::setEmployeeCode(int employeeCode) 
{
	this->employeeCode = employeeCode;
}

void Employee::setDepartment(char* department)
{
	this->department = department;
}

class Base
{
	//virtual void f();
	/*
public:
	int n;
	Base(int n) { this->n = n; }
	*/
public:
	unsigned int setValue(void* value);
};

unsigned int Base::setValue(void* value)
{
	unsigned int* re = reinterpret_cast<unsigned int*>(value);
	*re += 100;
	return *re;
}
/*
void Base::f()
{
	cout << "Hello Virtual Function in Base" << endl;
}
*/

class Derived : public Base
{
public:
	void f();
};

void Derived::f() 
{
	cout << "Hello Virtual Function in Derived" << endl;
}
void f(Base* pBase) {
	
	Derived *pDerived = static_cast<Derived*> (pBase);
	/*
	cout << pDerived->n << endl;
	*/
	//Derived *pDerived = dynamic_cast<Derived*> (pBase);
	pDerived->f();
}

class First
{
public:
	virtual void func() = 0; // 순수 가상함수, 구현은 자식에게
	/*
	virtual void func()
	{
		cout << "First Function" << endl;
	}
	*/
};

class Second : public First
{
public:
	virtual void func()
	{
		cout << "Second Function" << endl;
	}
};

class Third : public Second
{
public:
	virtual void func()
	{
		cout << "Third Function" << endl;
	}
};

int main(int argc, char* argv[])
{
	Third* third = new Third;
	Second* second = third;
	First* first = second;
	third->func();
	second->func();
	first->func();

	/*
	Base b1;
	f(&b1);

	Derived b2;
	f(&b2);
	*/
	/*
	Base b;
	int value = 10;
	unsigned int result = b.setValue(&value);
	cout << "Value:" << result << endl;
	*/
	return 0;

	/*
	Person* qPerson = new Person("Mr.Lee");
	char* name = qPerson->getName();
	Employee* qEmployee = (Employee*)qPerson;
	qEmployee->setEmployeeCode(10001);
	int code = qEmployee->getEmployeeCode();
	qEmployee->setDepartment("Development");
	char* dep = qEmployee->getDepartment();
	cout << "Name:" << name << ", Department:" << dep << ", Code:" << code << endl;
	*/
	/*
	Person* pPerson = new Employee("Mr.Kim");
	char* name = pPerson->getName();
	Employee* pEmployee = (Employee*)pPerson;  // 다운캐스팅은 반드시 명시해줘야 한다.  // 이것은 c 스타일의 캐스팅이다.
	pEmployee->setEmployeeCode(10001);
	int code = pEmployee->getEmployeeCode();
	pEmployee->setDepartment("Development");
	char* dep = pEmployee->getDepartment();
	cout << "Name:" << name << ", Department:" << dep << ", Code:" << code << endl;
	

	return 0;
	*/





	/*
	//BaseClass base;
	SubClass sub;
	return 0;
	*/
	/*
	Y y;
	y.x->SetX(20);
	return 0;
	*/
}

