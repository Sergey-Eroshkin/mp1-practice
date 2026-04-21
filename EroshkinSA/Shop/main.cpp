#include <iostream>
#include "Product.h"

using namespace std;

int main() {
	string s;
	double c;
	int disc, a;
	cout << "name cost discount amount\n";
	cin >> s >> c >> disc >> a;
	CountProduct p(s, a, c, disc);
	Basket b;
	b.Add(&p);
	Receipt r(&b);
	r.calc();
	cout << r << endl;
	return 0;
}