#include "Programmer.h"

Programmer::Programmer(char* _name, long _id, int _age, double _weight, int _experience, string _programLanguage) : Person(_name, _id, _age, _weight), experience(_experience), programLanguage(_programLanguage)
{
}

Programmer::Programmer() : Person(), experience(1), programLanguage("C++")
{
}

Programmer::Programmer(const Programmer& other)
{
	*this = other;
}

const Programmer& Programmer::operator=(const Programmer& other)
{
	if (this != &other)
	{
		experience = other.experience;
		programLanguage = other.programLanguage;
		Person::operator=((Person&)other); 
	}
	return (*this);
}

bool Programmer::operator==(Person& other)
{
	Programmer compere = dynamic_cast<Programmer&>(other);
	if (Person::operator==(other) && experience == compere.experience && programLanguage == compere.programLanguage)
		return true;
	else
		return false;
}


void Programmer::setExperience(int _experience) throw (const char*)
{
	if (_experience < 0 || _experience>60)
		throw "This experience does not make sense.";
	experience = _experience;
}

void Programmer::setProgramLanguage(string _programLanguage)
{
	programLanguage = _programLanguage;
}

void Programmer::isASenior()
{
	if (experience > 3)
		cout << "This programmer is a senior." << endl;
	else
		cout << "This programmer is not a senior." << endl;
}

bool Programmer::programInCplusplus()
{
	if (programLanguage == "c++")
		return true;
	else
		return false;

}

ostream& operator<<(ostream& out, const Programmer& p)
{
	out << (Person&)p << endl<< "Experience (in years): " << p.experience << endl << "Program language: " << p.programLanguage << endl;
	return out;
}

bool Programmer::operator!=(Programmer& other)
{
	if (!Person::operator==((Person&)other) || experience != other.experience || programLanguage != other.programLanguage)
		return true;
	return false;
}

bool Programmer::operator<(Programmer& other)
{
	if (experience < other.experience)
		return true;
	return false;
}

void Programmer::show() const
{
	cout << (Person&)*this << endl << "Experience (in years): " << experience <<endl<< "Program language: " << programLanguage << endl;
}


