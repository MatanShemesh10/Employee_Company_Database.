#pragma once
#include <iostream>
using namespace std;
class productManger
{
	char* name;
	double salary;

public:
	productManger(char* _name, double _salary);
	productManger();
	productManger(const productManger& other);
	~productManger();
	friend ostream& operator<<(ostream& out, const productManger& p);
	virtual void show() const;
	bool operator==(productManger& other);
	const productManger& operator=(const productManger& other);
	double getSalary() const;
	void setSalary(double _salary);
	
};

