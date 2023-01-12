#pragma once
#include "Person.h"

class Programmer : public Person
{
	int experience;
	string programLanguage;
public:
	Programmer(char* _name, long _id, int _age, double _weight, int _experience, string _programLanguage);
	Programmer();
	Programmer(const Programmer& other);
	const Programmer& operator=(const Programmer& other);
	virtual bool operator==(Person& other);
	int getExperience() const { return experience; }
	string getProgramLanguage() const { return programLanguage; }
	void setExperience(int _experience)throw (const char*);
	void setProgramLanguage(string _programLanguage);

	void isASenior();
	bool programInCplusplus();
	bool operator!=(Programmer& other);
	bool operator<(Programmer& other);//check the experience

	friend ostream& operator<<(ostream& out, const Programmer& p);
	virtual void show() const;



};

