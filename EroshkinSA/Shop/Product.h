#ifndef __SHOP_H
#define __SHOP_H

using namespace std;

class Product
{
protected:
	string name;
	double cost;
	int discount;
	Product(string, double, int);
public:
	virtual int price() = 0;
	virtual double disc() = 0;
	virtual double price_with_disc() = 0;
};

class WeightProduct :
	public Product
{
	double weight;
public:
	WeightProduct(string, double, double, int);
	virtual int price();
	virtual double disc();
	virtual double price_with_disc();
};

class CountProduct :
	public Product
{
	int amount;
public:
	CountProduct(string, int, double, int);
	virtual int price();
	virtual double disc();
	virtual double price_with_disc();
};

class Basket
{
	int capacity;
	static const int block_size;
protected:
	Product** products;
	int count;
public:
	Basket();
	void Add(Product*);
	~Basket();
	size_t size() { return count; }
	Product* operator[](int);
};

class Receipt {
	double total = 0.0, total_discount = 0.0, sum = 0.0;
	Basket* basket;
public:
	Receipt(Basket*);
	void calc();
	friend ostream& operator<<(ostream&, Receipt&);
	~Receipt();
};

#endif