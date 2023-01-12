#include "Address.h"

Address::Address(char* _city, string _street, int _houseNo) : street(_street), houseNo(_houseNo)
{
	delete[]city;
	city = NULL;
	city = new char[strlen(_city) + 1];
	strcpy_s(city, strlen(_city) + 1, _city);
}

Address::Address() : street("Sumsum"), houseNo(1)
{
	delete[]city;
	city = NULL;
	city = new char[9];
	strcpy_s(city, 9, "Tel Aviv");
}

Address::Address(const Address& other)
{
	delete[]city;
	*this = other;
}

Address::~Address()
{
	delete[]city;
}

const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		street = other.street;
		houseNo = other.houseNo;
		delete[] city;
		city = new char[(strlen(other.city) + 1)];
		strcpy_s(city, strlen(other.city) + 1, other.city);
	}
	return (*this);
}

void Address::setCity(char* _city)
{
	delete[]city;
	city = NULL;
	city = new char[strlen(_city) + 1];
	strcpy_s(city, strlen(_city) + 1, _city);
}

void Address::setStreet(string _street)
{
	street = _street;
}

void Address::setHouse(int h)
{
	houseNo = h;
}

char* Address::getCity() const
{
	return city;
}

string Address::getStreet() const
{
	return street;
}

int Address::getHouse() const
{
	return houseNo;
}

bool Address::operator==(const Address& otherAddress) const
{
	if (strcmp(city, otherAddress.city) == 0 && street == otherAddress.street && houseNo == otherAddress.houseNo)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const Address& p)
{
	out << "City: " << p.city << "\tStreet: " << p.street << "\tHouse number: " << p.houseNo << endl;
	return out;
}
