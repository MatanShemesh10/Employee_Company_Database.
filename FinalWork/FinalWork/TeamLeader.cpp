#include "TeamLeader.h"
#include <queue>
using namespace std;

void TeamLeader::create() throw (const char*)
{
	char _name[50]; long _id; int _age; double _weight; int _experience; string _programLanguage;
	cout << "Please insert number of programmers in the team leader's team: ";
	cin >> numOfEmployees;
	for (int i = 0; i < numOfEmployees; i++)
	{
		cout << "Programmer #" << i + 1 << ":" << endl;
		cout << "Name: ";
		cin.ignore();
		cin.getline(_name, 50);
		cout << "Id: ";
		cin >> _id;
		cout << "Age: ";
		cin >> _age;
		cout << "Weight: ";
		cin >> _weight;
		cout << "Experience in coding: ";
		cin >> _experience;
		if (_id < 0 || _age < 0 || _weight < 0 || _experience < 0)
			throw "You insert invaild number. stopping the system...";
		cout << endl << "Program language using: ";
		cin >> _programLanguage;
		Programmer p1(_name, _id, _age, _weight, _experience, _programLanguage);
		programmerQueue.push(p1);
	}

}

void TeamLeader::Add(Programmer newProgrammer)
{
	numOfEmployees++;
	programmerQueue.push(newProgrammer);
}

TeamLeader::TeamLeader(char* _name, long _id, int _age, double _weight, int _experience, string _programLanguage, char* _nameOfTeam, double _salary)
	: Programmer(_name, _id, _age, _weight, _experience, _programLanguage), productManger(_name, _salary)
{
	if (numOfEmployees>0)
		create(); //the helping function 'create' create queue and insert all the programmers under the team leader

	delete[]nameOfTeam;
	nameOfTeam = NULL;
	nameOfTeam = new char[strlen(_nameOfTeam) + 1];
	strcpy_s(nameOfTeam, strlen(_nameOfTeam) + 1, _nameOfTeam);
}

TeamLeader::TeamLeader() : Programmer(), numOfEmployees(0), productManger() 
{
	delete[]nameOfTeam;
	nameOfTeam = NULL;
	nameOfTeam = new char[10];
	strcpy_s(nameOfTeam, 10, "teamAlpha");

}

TeamLeader::TeamLeader(const TeamLeader& other)
{
	*this = other;
}

TeamLeader::~TeamLeader()
{
	delete[] nameOfTeam;
}

const TeamLeader& TeamLeader::operator=(const TeamLeader& other)
{
	if (this != &other)
	{
		numOfEmployees = other.numOfEmployees;
		Programmer::operator=((Programmer&)other); 
		programmerQueue = other.programmerQueue; 
		delete[] nameOfTeam;
		nameOfTeam = new char[(strlen(other.nameOfTeam) + 1)];
		strcpy_s(nameOfTeam, strlen(other.nameOfTeam) + 1, other.nameOfTeam);
		productManger::operator=((productManger&)other);
	}
	return (*this);
}


bool TeamLeader::operator==(TeamLeader& other)//we assume that the original and other Queue in the same order of employees otherwise they can not be equal
{
	if (Programmer::operator==((Programmer&)other) && numOfEmployees == other.numOfEmployees &&/*please see comment below*/ compereQueue(other.programmerQueue) && !strcmp(nameOfTeam, other.nameOfTeam) && productManger::operator==((productManger&)other))
		return true;
	return false;
}

bool TeamLeader::compereQueue(queue<Programmer>& other) //this function start only if (numOfEmployees == other.numOfEmployees)
{
	queue<Programmer> original = programmerQueue; //present "this"
	queue<Programmer> otherTemp = other; //preset "other"
	while (!original.empty() && !otherTemp.empty())
	{
		if (original.front() != otherTemp.front())
			return false;

		original.pop();
		otherTemp.pop();
	}

	return true;

}

void TeamLeader::setNumOfEmployees(int num)
{
	numOfEmployees = num;
}

void TeamLeader::show() const
{
	int i = 1;
	queue<Programmer> tempQueue = programmerQueue;
	Programmer temp;
	cout << "the name of the team: " << nameOfTeam << endl;
	cout << "The information of the team leader: " << endl << (Programmer&)*this << "Salary: " << getSalary() << endl;
	cout << "The information of leader's employees: " << endl << "Number of employees: " << numOfEmployees << endl;
	while (!tempQueue.empty())
	{
		cout << "Employee #" << i++ << ": " << tempQueue.front() << endl;
		tempQueue.pop();
	}

}

ostream& operator<<(ostream& out, const TeamLeader& p)
{
	int i = 1;
	queue<Programmer> tempQueue = p.programmerQueue;
	Programmer temp;
	out << "the name of the team: " << p.nameOfTeam << endl;
	out << "The information of the team leader person: " << endl << (Programmer&)p << "Salary: " << p.getSalary() << endl;;
	out << "The inforation of leader's employees: " << endl << "Number of employees: " << p.numOfEmployees << endl;
	while (!tempQueue.empty())
	{
		out << "Employee #" << i++ << ": " << tempQueue.front() << endl;
		tempQueue.pop();
	} 

	return out;
}

int TeamLeader::numOfProgrammersIncPlusplus()
{
	queue<Programmer> tempQueue = programmerQueue;
	int count = 0;

	while (!tempQueue.empty())
	{
		if (tempQueue.front().programInCplusplus())
			count++;

		tempQueue.pop();
	}
	return count;
}

int TeamLeader::avrageAge()
{
	if (numOfEmployees < 1)
		return 0;

	queue<Programmer> tempQueue;
	tempQueue = programmerQueue;
	int sum = 0;
	while (!tempQueue.empty()) {
		sum += tempQueue.front().getAge();
		tempQueue.pop();
	}
	return (sum / numOfEmployees);
}