#ifndef __SHOP_H
#define __SHOP_H

class Product
{
protected:
	string name;
	double cost;
	int discount;
	Product(string, double, int);
public:
	virtual int price();
	virtual double price_with_disc();
};

class WeightProduct :
	public Product
{
	double weight;
public:
	WeightProduct(std::string, int, double, int);
	virtual int price();
	virtual double price_with_disc();
};

class CountProduct :
	public Product
{
	int amount;
public:
	CountProduct(std::string, double, double, int);
	virtual int price();
	virtual double price_with_disc();
};

class Basket
{
protected:
	Product** products;
	int count;
int capacity;
static const int block_size;
public:
	Basket();
	void Add(Product*)
};

#endif