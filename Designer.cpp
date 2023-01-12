#include "Designer.h"

int Designer::numberOfDesignersInCompnay = 0;

Designer::Designer(char* _name, long _id, int _age, double _weight, int _seniority, string _designProgram, Address* _myAddress, vector<string> _tasks)
	: Person(_name, _id, _age, _weight), seniority(_seniority), designProgram(_designProgram), tasks(_tasks), myAddress(_myAddress)
{
	numberOfDesignersInCompnay++;
}

Designer::Designer() : Person(), seniority(1), designProgram("PhotoShop")
{
	Address* a1 = new Address;//using us to provide dynamic Address for empty Designer
	Address a2;
	*a1 = a2;
	myAddress = a1;
	tasks.push_back("deafult");
	numberOfDesignersInCompnay++;
}

Designer::Designer(const Designer& other)
{
	*this = other;
	numberOfDesignersInCompnay++;
}

const Designer& Designer::operator=(const Designer& other)
{
	if (this != &other)
	{
		seniority = other.seniority;
		designProgram = other.designProgram;
		Person::operator=((Person&)other);
		myAddress = other.myAddress;
		tasks = other.tasks;
	}
	return (*this);

}

bool Designer::operator==(Person& other)
{
	Designer compere = dynamic_cast<Designer&>(other);
	if (Person::operator==(other) && seniority == compere.seniority && designProgram == compere.designProgram && myAddress == compere.myAddress && tasks == compere.tasks)
		return true;
	return false;

}

bool Designer::operator!=(Designer& other)
{
	if (!Person::operator==((Person&)other) || seniority != other.seniority || designProgram != other.designProgram || !(myAddress == other.myAddress) || !(tasks == other.tasks))
		return true;
	return false;
}

bool Designer::operator<(Designer& other)
{
	if (seniority < other.seniority)
		return true;
	return false;
}

void Designer::setSeniority(int _seniority) throw (const char*)
{
	if (_seniority < 1 || _seniority>60)
		throw "This seniority does not make sense.";
	seniority = _seniority;
}

void Designer::setDesignProgram(string _designProgram)
{
	designProgram = _designProgram;
}

void Designer::show() const
{
	cout << (Person&)*this << endl << "Seniority (in years): " << seniority << endl << "Design Program: " << designProgram << endl << "Address: " << *myAddress << endl;
	cout << "Tasks: " << endl;
	vector<string> temp = tasks;
	int i = 1;
	vector<string>::iterator itr = temp.begin();
	vector<string>::iterator itrEnd = temp.end();
	for (; itr != itrEnd; ++itr)
		cout << "Task number #" << i++ << ": " << *itr << endl;
}

ostream& operator<<(ostream& out, const Designer& p)
{
	out << (Person&)p << endl << "Seniority (in years): " << p.seniority << endl << "Design Program: " << p.designProgram << endl << "Address: " << *p.myAddress << endl;

	if (p.tasks.size() != 0)
	{
		vector<string> temp = p.tasks;
		int i = 1;
		vector<string>::iterator itr = temp.begin();
		vector<string>::iterator itrEnd = temp.end();
		for (; itr != itrEnd; ++itr)
			out << "Task number #" << i++ << ": " << *itr << endl;
	}
	else
		out << "This designer has no task." << endl;

	return out;
}

void Designer::printTasks()
{
	if (tasks.size() == 0)
	{
		cout << "There are no tasks to this designer." << endl;
		return;
	}
	int i = 1;
	vector<string>::iterator itr = tasks.begin();
	vector<string>::iterator itrEnd = tasks.end();
	for (; itr != itrEnd; ++itr)
		cout << "Task number #" << i++ << ": " << *itr << endl;
}


void Designer::IsASenior()
{
	if (seniority > 3)
		cout << "The designer is a senior" << endl;
	else
		cout << "The designer is not a senior" << endl;
}

void Designer::designInPhotoShop()
{
	if (designProgram == "PhotoShop")
		cout << "The designer using PhotoShop" << endl;
	else
		cout << "The designer not using PhotoShop" << endl;
}


