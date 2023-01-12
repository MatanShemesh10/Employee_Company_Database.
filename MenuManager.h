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

	void InternalDesigner1();//opertion all the option class design
	char InternalDesigner2();//menu of the option that we have to the designers

	void InternalProgrammer1();//opertion all the option class Programmer
	char InternalProgrammer2();//menu of the option that we have to the Programmer

	void InternalTeamLeader1();//opertion all the option class TeamLeader
	char InternalTeamLeader2();//menu of the option that we have to the TeamLeader


};

