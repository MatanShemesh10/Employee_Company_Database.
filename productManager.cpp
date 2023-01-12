#include "productManager.h"

productManger::productManger(char* _name, double _salary) :salary(_salary)
{
	delete[]name;
	name = NULL;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

productManger::productManger()
{
	salary = 0;
	delete[]name;
	name = NULL;
	name = new char[8];
	strcpy_s(name, 8, "default");
}

productManger::productManger(const productManger& other)
{
	name = NULL;
	*this = other;
}

productManger::~productManger()
{
	delete[]name;
}

bool productManger::operator==(productManger& other)
{
	if (strcmp(name, other.name) == 0 && salary == other.salary)
		return true;
	else
		return false;
}

const productManger& productManger::operator=(const productManger& other)
{
	if (this != &other)
	{
		salary = other.salary;
		delete[] name;
		name = new char[(strlen(other.name) + 1)];
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
	return (*this);
}

double productManger::getSalary() const
{
	return salary;
}

void productManger::setSalary(double _salary)
{
	salary = _salary;
}

void productManger::show() const
{
	cout << "Name: " << name << endl << "Salary: " << salary << endl;
}


ostream& operator<<(ostream& out, const productManger& p)
{
	out << "Name: " << p.name << endl << "Salary: " << p.salary << endl;
	return out;
}