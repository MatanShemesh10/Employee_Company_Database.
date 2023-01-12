#include "Person.h"
using namespace std;

Person::Person() : id(00000000), age(24), weight(70.00)
{
	name = NULL;
	delete[]name;
	name = new char[8];
	strcpy_s(name, 8, "default");
}

Person::Person(char* _name, long _id, int _age, double _weight) : id(_id), age(_age), weight(_weight)
{
	delete[]name;
	name = NULL;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

Person::Person(const Person& other)
{
	name = NULL;
	*this = other;
}

Person::~Person()
{
	delete[]name;
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		id = other.id;
		age = other.age;
		weight = other.weight;
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);

	}
	return (*this);
}

bool Person::operator==(Person& other)
{
	if (strcmp(name, other.name) == 0 && id == other.id && age == other.age && weight == other.weight)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "Name: " << p.name << endl << "Id: " << p.id << endl << "Age: " << p.age << endl << "Weight: " << p.weight;
	return out;
}

void Person::setName(char* _name)
{
	delete[]name;
	name = NULL;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

void Person::setWeight(double _weight)
{
	weight = _weight;
}

void Person::setAge(int _age)
{
	age = _age;
}

bool Person::fat()
{
	if (weight > 100)
		return true;
	else
		return false;
}

bool Person::old()
{
	if (age > 70)
		return true;
	else
		return false;
}

bool Person::healthy()
{
	return (fat() && old());
}


