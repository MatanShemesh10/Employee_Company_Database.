#pragma once

#include <iostream>
using namespace std;
class Person
{
	char* name;
	long id;
	int age;
	double weight;
public:
	Person();
	Person(char* _name, long _id, int _age, double _weight);
	Person(const Person& other);
	~Person();
	const Person& operator=(const Person& other);
	friend ostream& operator<<(ostream& out, const Person& p);
	bool operator==(Person& other);
	char* getName() const { return name; }
	long getID() const { return id; }
	int getAge() const { return age; }
	double getWeight() const { return weight; }
	void setName(char* _name);
	void setWeight(double _weight);
	void setAge(int _age);

	bool fat(); //over 100
	bool old(); //over 70
	bool healthy(); //true fat & true old

	virtual void show() const = 0;

};
