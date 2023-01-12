#pragma once
#include "Programmer.h"
#include "productManager.h"
#include <queue>
using namespace std;

class TeamLeader : public Programmer, public productManger
{
	int numOfEmployees;
	queue<Programmer> programmerQueue;
	char* nameOfTeam;

public:
	TeamLeader(char* _name, long _id, int _age, double _weight, int _experience, string _programLanguage, char* _nameOfTeam, double _salary);
	TeamLeader();
	TeamLeader(const TeamLeader& other);
	~TeamLeader();
	const TeamLeader& operator=(const TeamLeader& other);
	friend ostream& operator<<(ostream& out, const TeamLeader& p);
	bool operator==(TeamLeader& other);
	int getNumOfEmployees() const { return numOfEmployees; }
	void setNumOfEmployees(int num);
	virtual void show() const;

	void Add(Programmer newProgrammer);
	int numOfProgrammersIncPlusplus();
	int avrageAge();
	void create();
	

private:
	bool compereQueue(queue<Programmer>& other);
	

};

