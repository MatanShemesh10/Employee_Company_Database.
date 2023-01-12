#pragma once
#include "Person.h"
#include "Programmer.h"
#include "Address.h"
#include "Designer.h"
#include "productManager.h"
#include "TeamLeader.h"
#include <vector>
using namespace std;

class MenuManager
{
	vector <Person*> object;
public:
	MenuManager(vector <Person*> _object);
	MenuManager();
	MenuManager(const MenuManager& other);
	const MenuManager& operator=(const MenuManager& other);
	void addObject(Person* toAdd);
	void removeObject(long _id);
	Person* searchObject(long _id);
	friend ostream& operator<<(ostream& out, const MenuManager& p);
	virtual void show() const;
	void StartProgram();

private:

	char mainMenu();
	void addObjectMenu1();
	char addObjectMenu2();
	Designer createDesinger();
	Programmer createProgrammer();
	TeamLeader createTeamLeader();

	void InternalDesigner1();
	char InternalDesigner2();

	void InternalProgrammer1();
	char InternalProgrammer2();

	void InternalTeamLeader1();
	char InternalTeamLeader2();


};

