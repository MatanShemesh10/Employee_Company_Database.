#pragma once

#include <iostream>
#include <string>
using namespace std;
class Address
{
	char* city;
	string street;
	int houseNo;
public:
	Address(char* _city, string _street, int _houseNo);
	Address();
	Address(const Address& other);
	~Address();
	const Address& operator=(const Address& other);
	void setCity(char* city);
	void setStreet(string street);
	void setHouse(int h);
	friend ostream& operator<<(ostream& out, const Address& p);
	char* getCity() const;
	string getStreet() const;
	int getHouse() const;
	bool operator== (const Address& otherDate) const;

};