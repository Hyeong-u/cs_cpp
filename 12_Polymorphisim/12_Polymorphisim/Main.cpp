#include <iostream>

using namespace std;

/*
class A {
public:
	int i;
protected:
	int j;
private:
	int k;
};

class B : public A {

};

class C : protected A {

};

class D : private A {

};
*/

class A {
public:
	A() { cout << "A"; }
	virtual ~A() { cout << "~A";}
};

class B : public A {
public:
	B() : A() { cout << "B"; }
	~B() { cout << "~B"; }
};


int main()
{
	A *ap = new B;
	delete ap;

	return 0;

	/*
	A a;
	B b;
	C c;
	D d;

	a.i;
	a.j;
	a.k;
	
	b.i;
	b.j;
	b.k;

	c.i;
	c.j;
	c.k;

	d.i;
	d.j;
	d:k;
	*/
}