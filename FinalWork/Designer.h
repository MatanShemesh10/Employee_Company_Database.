#pragma once
#include "Address.h"
#include "Person.h"
#include <string.h>
#include <vector>
using namespace std;

class Designer : public Person
{
	static int numberOfDesignersInCompnay;
	int seniority;
	string designProgram;
	Address* myAddress;
	vector<string> tasks;
public:
	Designer(char* _name, long _id, int _age, double _weight, int _seniority, string _designProgram, Address* _myAddress, vector<string> _Tasks);
	Designer();
	Designer(const Designer& other);
	const Designer& operator=(const Designer& other);
	virtual bool operator==(Person& other);
	bool operator!=(Designer& other);
	bool operator<(Designer& other);//check the seniority
	int getSeniority() const { return seniority; }
	string getDesignProgram() const { return designProgram; }
	void setSeniority(int _seniority)throw (const char*);
	void setDesignProgram(string _designProgram);

	friend ostream& operator<<(ostream& out, const Designer& p);
	virtual void show() const;
	void printTasks();

	void IsASenior();
	void designInPhotoShop();
	int getNumberOfDesignersInCompnay() { return numberOfDesignersInCompnay; }

};