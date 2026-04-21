#include <string>
#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(string s, double c, int d) : name(s), cost(c), discount(d) {}

CountProduct::CountProduct(string s, int a, double c, int d) : Product(s, c, d), amount(a) {}
WeightProduct::WeightProduct(string s, double w, double c, int d) : Product(s, c, d), weight(w) {}

int CountProduct::price() { return amount * cost; }
int WeightProduct::price() { return (weight / 100.0) * cost; }

double CountProduct::disc() { return amount * cost * (discount * 0.01); }
double WeightProduct::disc() { return (weight / 100.0) * cost * (discount * 0.01); }

double CountProduct::price_with_disc() { return amount * (cost * (100 - discount) * 0.01); }
double WeightProduct::price_with_disc() { return (weight / 100.0) * (cost * (100 - discount) * 0.01); }

Basket::Basket() {
	capacity = 10;
	count = 0;
	products = new Product * [capacity];
}

void Basket::Add(Product* p) {
	if (count == capacity) {
		capacity *= 2;
		Product** newdata = new Product * [capacity];
		for (int i = 0; i < count; i++) newdata[i] = products[i];
		delete[] products;
		products = newdata;
	}
	products[count++] = p;
}

Product* Basket::operator[](int ind) {
	if (ind >= count) throw "Out of range";
	return products[ind];
}

Basket::~Basket() {
	for (int i = 0; i < count; i++) delete products[i];
	delete[] products;
}

Receipt::Receipt(Basket* b) : basket(b) {}

void Receipt::calc() {
	for (int i = 0; i < basket->size(); i++) {
		total += (*basket)[i]->price();
		total_discount += (*basket)[i]->disc();
		sum += (*basket)[i]->price_with_disc();
	}
}

ostream& operator<<(ostream& out, Receipt& r) {
	out << "Total: " << r.total << "  |  " << "Discount: " << r.total_discount << "  |  " << "To pay == " << r.sum << endl;
	return out;
}

Receipt::~Receipt() {
	delete[] basket;
}