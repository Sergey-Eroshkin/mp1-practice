#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


struct Vector {
	double* x;
	int n;
	Vector(int);
	Vector(const Vector&);
	~Vector();
	double len() const;
	double operator *(const Vector&);
	Vector operator *(double);
	Vector operator +(const Vector&);
	Vector operator -(const Vector&);
	void operator =(const Vector&);
};

Vector::Vector(int n) {
	this->n = n;
	this->x = new double[n];
}

Vector::Vector(const Vector& v) {
	this->n = v.n;
	this->x = new double[v.n];
	for (int i = 0; i < n; i++) this->x[i] = v.x[i];
}

Vector::~Vector() {
	delete[] this->x;
}

double Vector::len() const {
	double s = 0.0;
	for (int i = 0; i < n; i++) s += x[i] * x[i];
	return sqrt(s);
}

double Vector::operator *(const Vector& v) {
	if (n != v.n) throw "Enter";
	double s = 0.0;
	for (int i = 0; i < n; i++) s += x[i] * v.x[i];
	return s;
}

Vector Vector::operator *(double a) {
	for (int i = 0; i < n; i++) x[i] *= a;
	return *this;
}

Vector Vector::operator +(const Vector& v) {
	if (n != v.n) throw "Error";
	Vector v1(n);
	for (int i = 0; i < n; i++) v1.x[i] = x[i] + v.x[i];
	return v1;
}

Vector Vector::operator -(const Vector& v) {
	if (n != v.n) throw "Error";
	Vector v1(n);
	for (int i = 0; i < n; i++) v1.x[i] = x[i] - v.x[i];
	return v1;
}

void Vector::operator =(const Vector& v) {
	if (n != v.n) throw "Error";
	for (int i = 0; i < n; i++) x[i] = v.x[i];
}


vector<bool> was;
void MethodGaussJordan(vector<Vector>& M, int m) {
	was.resize();
	for (int i = 0; i < m; i++) {
		int j = i;
		while (M[j].x[i] == 0 && j < m) j++;
		if (j == m) continue;

	}
}

int main() {
	int n; cin >> n;
	Vector v(n), v1(n);
	for (int i = 0; i < n; i++) {
		cin >> v.x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> v1.x[i];
	}
	cout << v * v1 << endl;
	Vector v2(n);
	v2 = v + v1 * 5;
	for (int i = 0; i < n; i++) {
		cout << v2.x[i] << " ";
	}
}