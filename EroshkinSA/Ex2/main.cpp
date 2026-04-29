#include <iostream>

using namespace std;

class A {
public:
	A() { cout << "A::A()\n"; }
	A(const A&) { cout << "A::A(const A&)\n"; }
	const A& operator=(const A&) {
		cout << "A::operator=(const A&)\n";
		return *this;
	}
	virtual ~A() { cout << "A::~A()\n"; }
	virtual void f() { cout << "A::f()\n"; }
};

class B : public A {
public:
	B() { cout << "B::B()\n"; }
	B(const A&) { cout << "B::B(const A&)\n"; }
	B(const B&) { cout << "B::B(const B&)\n"; }
	const B& operator=(const B&) {
		cout << "B::operator=(const A&)\n";
		return *this;
	}
	virtual ~B() { cout << "B::~B()\n"; }
	virtual void f() { cout << "B::f()\n"; }
};

class C : public B {
public:
	C() { cout << "C::C()\n"; }
	C(const C&) { cout << "C::C(const C&)\n"; }
	const C& operator=(const C&) {
		cout << "C::operator=(const C&)\n";
		return *this;
	}
	~C() { cout << "C::~C()\n"; }
	void f() { cout << "C::f()\n"; }
};

void main() {
	B* a = new B();
	cout << "_______\n";
	a->f();
	cout << "_____________________\n";

	A* ma = new B[5];
	cout << "_______\n";
	ma[0].f();
	cout << "_______\n";
	ma[1] = *a;
	cout << "_____________________\n";

	A* b = new A(*a);
	cout << "_______\n";
	b->f();
	cout << "_____________________\n";

	A aa;
	cout << "_______\n";
	B bb = *a;
	cout << "_______\n";
	B bbb = B(*b);
	cout << "_____________________\n";

	B* mc = new C[4];
	cout << "_______\n";
	mc[1] = *a;
	cout << "_______\n";
	mc[1].f();
	cout << "_____________________\n";
	
	A** mma = new A*[3];
	cout << "_______\n";
	mma[0] = a;
	cout << "_______\n";
	mma[0]->f();
	cout << "_____________________\n";

	delete a;
	cout << "_______\n";
	delete[]ma;
	cout << "_______\n";
	delete b;
	cout << "_______\n";
	delete[]mc;
	cout << "_____________________\n";
}