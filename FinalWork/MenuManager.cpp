#include "MenuManager.h"

MenuManager::MenuManager(vector<Person*> _object): object(_object)
{
}

MenuManager::MenuManager()
{
	 //we decided that deafult is null
}

MenuManager::MenuManager(const MenuManager& other)
{
	*this = other;
}

const MenuManager& MenuManager::operator=(const MenuManager& other)
{
	if (this != &other)
	{
		object.resize(other.object.size());
		int i = 0;
		while (other.object.size() != i)
		{
			object[i] = NULL;
			if (!strcmp(typeid(TeamLeader).name(), typeid(*other.object[i]).name()))
				object[i] = dynamic_cast<TeamLeader*>(other.object[i]);

			else if (!strcmp(typeid(Designer).name(), typeid(*other.object[i]).name()))
				object[i] = dynamic_cast<Designer*>(other.object[i]);

			else if (!strcmp(typeid(Programmer).name(), typeid(*other.object[i]).name()))
				object[i] = dynamic_cast<Programmer*>(other.object[i]);

			i++;
		}
	}
	
	return *this;
}

void MenuManager::addObject(Person* toAdd)
{
	if (!strcmp(typeid(TeamLeader).name(), typeid(*toAdd).name()))
		object.push_back(dynamic_cast<TeamLeader*>(toAdd));

	else if (!strcmp(typeid(Designer).name(), typeid(*toAdd).name()))
		object.push_back(dynamic_cast<Designer*>(toAdd));

	else if (!strcmp(typeid(Programmer).name(), typeid(*toAdd).name()))
		object.push_back(dynamic_cast<Programmer*>(toAdd));
}

void MenuManager::removeObject(long _id)
{
	
	for (int i = 0; i < object.size(); i++)
		if (object[i]->getID() == _id)
		{
			object.erase(object.begin() + i);
			cout << "Employee with id " << _id << " has been deleted." <<endl;
			return;
		}
			
	cout << "we can not find an employee with such id." << endl;
}

Person* MenuManager::searchObject(long _id)
{
	for (int i = 0; i < object.size(); i++)
		if (object[i]->getID() == _id)
		{
			if (!strcmp(typeid(TeamLeader).name(), typeid(*object[i]).name()))
				return object[i];

			if (!strcmp(typeid(Programmer).name(), typeid(*object[i]).name()))
				return object[i];

			if (!strcmp(typeid(Designer).name(), typeid(*object[i]).name()))
				return object[i];
		}
	
	cout << "we can not find such employee with such id." << endl;
	return NULL;
}

ostream& operator<<(ostream& out, const MenuManager& p)
{
	for (int i = 0; i < p.object.size(); i++)
	{
		out << endl << "-----------------------------------------" << endl;
		out << "Object #" << i + 1 << ": ";
		if (!strcmp(typeid(TeamLeader).name(), typeid(*p.object[i]).name()))
			out <<  (TeamLeader&)*p.object[i] << endl;

		if (!strcmp(typeid(Programmer).name(), typeid(*p.object[i]).name()))
			out << (Programmer&)*p.object[i] << endl;

		if (!strcmp(typeid(Designer).name(), typeid(*p.object[i]).name()))
			out << (Designer&)*p.object[i] << endl;


	}
	return out;

}

void MenuManager::show() const
{
	for (int i = 0; i < object.size(); i++)
	{
		cout << "employee #" << i + 1 << ": "<<endl;
		if (!strcmp(typeid(TeamLeader).name(), typeid(*object[i]).name()))
			cout << (TeamLeader&)*object[i] << endl;

		if (!strcmp(typeid(Programmer).name(), typeid(*object[i]).name()))
			cout << (Programmer&)*object[i] << endl;

		if (!strcmp(typeid(Designer).name(), typeid(*object[i]).name()))
			cout << (Designer&)*object[i] << endl;
		
		cout <<endl<< "-----------------------------------------" << endl;
	}
}

Designer MenuManager::createDesinger()
{
	char _name[50]; long _id; int _age; double _weight; int _seniority; string _designProgram; char _city[50]; string _street; int _houseNo;
	int taskEnter;
	cout << "Please insert designer name: ";
	cin.ignore();
	cin.getline(_name, 50);
	cout << "Id: ";
	cin >> _id;
	cout << "Age: ";
	cin >> _age;
	cout << "Weight: ";
	cin >> _weight;
	cout << "Seniority in design: ";
	cin >> _seniority;
	cout << "Design program name: ";
	cin >> _designProgram;
	cout << "Adress of the desinger:" << endl;
	cout << "City: ";
	cin.ignore();
	cin.getline(_city, 50);
	cout << "Street: ";
	cin >> _street;
	cout << "House number: ";
	cin >> _houseNo;
	cout << "Does the desinger have tasks? yes-1 no-2: ";
	cin >> taskEnter;
	vector<string> _tasks;
	if (taskEnter == 1)
	{
		cout << "How many tasks?";
		cin >> taskEnter;
		if (taskEnter > 0)
		{
			string inputTask;
			for (int i = 0; i < taskEnter; i++)
			{
				cout << "Please enter task #" << i + 1 << ": ";
				cin >> inputTask;
				_tasks.push_back(inputTask);
			}
		}
		else
			cout << "You have chosen that there are no tasks, moving on";
	}

	Address a1(_city, _street, _houseNo);
	Address* a2 = new Address;
	*a2 = a1;
	Designer p1(_name, _id, _age, _weight, _seniority, _designProgram, a2, _tasks);
	return p1;
}

Programmer MenuManager::createProgrammer()
{
	char _name[50]; long _id; int _age; double _weight; int _experience; string _programLanguage;

	cout << "Please insert programmer name: ";
	cin.ignore();
	cin.getline(_name, 50);
	cout << "Id: ";
	cin >> _id;
	cout << "Age: ";
	cin >> _age;
	cout << "Weight: ";
	cin >> _weight;
	cout << "Experience in programming: ";
	cin >> _experience;
	cout << "Program language using name: ";
	cin >> _programLanguage;

	Programmer p1(_name, _id, _age, _weight, _experience, _programLanguage);
	return p1;
}

TeamLeader MenuManager::createTeamLeader()
{
	char _name[50]; long _id; int _age; double _weight; int _experience; string _programLanguage; char _nameTeam[50]; double salary;

	cout << "Please insert team leader name: ";
	cin.ignore();
	cin.getline(_name, 50);
	cout << "Id: ";
	cin >> _id;
	cout << "Age: ";
	cin >> _age;
	cout << "Weight: ";
	cin >> _weight;
	cout << "Experience in programming: ";
	cin >> _experience;
	cout << "Program language using name: ";
	cin >> _programLanguage;
	cout << "The name of the Team: ";
	cin.ignore();
	cin.getline(_nameTeam, 50);
	cout << "Salary of the team leader: ";
	cin >> salary;

	TeamLeader d1(_name, _id, _age, _weight, _experience, _programLanguage, _nameTeam, salary);
	d1.create();
	return d1;
}

void MenuManager::StartProgram()
{
	cout << endl << "Welcome to the data base of M&A engineering!" << endl <<
		"In our software you can management a database of a company." << endl
		<< "You can find information about employees such programmer, designer and team leader." << endl;
	cout << "In any stage it is possible to go back to the main menu.";
	cout << endl << "Please choose an option from the menu:" << endl;
	
	while (1)
	{
		switch (mainMenu())
		{
		case '1': addObjectMenu1(); break;
		case '2': 
		{
			cout << endl << "-----------------------------------------" << endl;
			if (object.size() == 0)
			{
				cout << "There are no employees in the database." << endl;
				break;
			}
			long id;
			cout << "Please enter the id of the employee you want to remove: ";
			cin >> id;
			removeObject(id);
			break;
		}
		case '3':
		{
			cout << endl << "-----------------------------------------" << endl;
			long id;
			cout << "Please enter an employee's id for the search: ";
			cin >> id;

			if (!strcmp(typeid(TeamLeader).name(), typeid(*searchObject(id)).name()))
			{
				TeamLeader* p1 = (TeamLeader*)searchObject(id);
				cout << *p1;
				break;
			}
				
			if (!strcmp(typeid(Programmer).name(), typeid(*searchObject(id)).name()))
			{
				Programmer* p1 = (Programmer*)searchObject(id);
				cout << *p1;
				break;
			}
				
			if (!strcmp(typeid(Designer).name(), typeid(*searchObject(id)).name()))
			{
				Designer* p1 = (Designer*)searchObject(id);
				cout << *p1;
				break;
			}
			
			break;
		}
		case '4':
		{
			cout << endl << "-----------------------------------------" << endl;
			show();
			break;
		}
		case '5':
		{
			InternalDesigner1();
			break;
		}
		case '6':
		{
			InternalProgrammer1();
			break;
		}
		case '7':
		{
			InternalTeamLeader1();
			break;
		}

		case '0': cout << "Exiting in progress." << endl << endl;	return;
		default: cout <<endl<< "Wrong. Please try again" << endl<<endl;
		}
	} 

}

char MenuManager::mainMenu()
{
	cout <<endl<< "======================================= " << endl;
	cout << " \t\tMENU \t " << endl;
	cout << "======================================= " << endl;
	cout << " 1. Add an employee. " << endl;
	cout << " 2. Remove an employee (according id). " << endl;
	cout << " 3. Search an employee (according id).  " << endl;
	cout << " 4. View all employees.  " << endl;
	cout << " 5. Internal desinger options.  " << endl;
	cout << " 6. Internal programmer options.  " << endl;
	cout << " 7. Internal team leader options.  " << endl;
	cout << " 0. End program. " << endl << endl;
	cout << "Enter your choice:";
	fseek(stdin, 0, SEEK_END);
	return(getchar());
}

void MenuManager::addObjectMenu1()
{
	
	while (1)
	{
		switch (addObjectMenu2())
		{
		case '1': 
		{
			Designer d1 = createDesinger();
			Designer* d2 = new Designer;
			*d2 = d1;
			addObject(d2);
			return;
		}
		case '2': 
		{
			Programmer p1 = createProgrammer();
			Programmer* p2 = new Programmer;
			*p2 = p1;
			addObject(p2);
			return;
		}
		case '3': 
		{
			TeamLeader t1 = createTeamLeader();
			TeamLeader* t2 = new TeamLeader;
			*t2 = t1;
			addObject(t2);
			return;
		}
		case '4':return;
		default: cout << endl << "Wrong. Please try again" << endl << endl;
		}
	}
}

char MenuManager::addObjectMenu2()
{
	cout <<endl<< "======================================= " << endl;
	cout << " 1. Add a designer. " << endl;
	cout << " 2. Add a programmer. " << endl;
	cout << " 3. Add a team leader.  " << endl;
	cout << " 4. Go back to main menu.  " << endl;
	cout << "Enter your choice:";
	fseek(stdin, 0, SEEK_END);
	return(getchar());
}

void MenuManager::InternalDesigner1()
{
	long id;
	int input;
	while (1)
	{
		switch (InternalDesigner2())
		{
		case '1':
		{
			cout << "enter an designer's id: ";
			cin >> id;
			Designer* d1 = (Designer*)searchObject(id);
			if (!strcmp(typeid(Designer).name(), typeid(*d1).name()))
				cout << "Seniority Of designer with id " << id << " is: " << d1->getSeniority() << endl;
		}
		case '2':
		{
			cout << "enter an designer's id: ";
			cin >> id;
			Designer* d1 = (Designer*)searchObject(id);
			if (d1 == NULL) break;
			if (!strcmp(typeid(Designer).name(), typeid(*d1).name()))
			{
				cout<< "Enter the new seniority's value you want: ";
				cin >> input;
				d1->setSeniority(input);
			}
			else
				cout << "we can not find such employee with such id." << endl;
			break;
		}
		case '3':
		{
			cout << "enter an designer's id: ";
			cin >> id;
			Designer* d1 = (Designer*)searchObject(id);
			if (d1 == NULL) break;
			if (!strcmp(typeid(Designer).name(), typeid(*d1).name()))
			{
				d1->printTasks();
				break;
			}
			else
				cout << "we can not find an employee with such id." << endl;
			break;
		}
		case '4':
		{
			cout << "enter an designer's id: ";
			cin >> id;
			Designer* d1 = (Designer*)searchObject(id);
			if (d1 == NULL)break;
			if (!strcmp(typeid(Designer).name(), typeid(*d1).name()))
			{
				d1->IsASenior();
				break;
			}
			else
				cout << "This employee is not a designer." << endl;
			break;
		}
		case '0': return;
		default: cout << endl << "Wrong. Please try again" << endl << endl;
		}
	}
}

char MenuManager::InternalDesigner2()
{
	cout << endl <<"=======================================" << endl;
	cout << "(In all the option you required to enter an id)" << endl;
	cout << " 1. Show designer's seniority (getSeniority)." << endl;
	cout << " 2. Change designer's seniority (setSeniority)." << endl;
	cout << " 3. Print task of specific designer." << endl;
	cout << " 4. Check if designer is a senior." << endl;
	cout << " 0. Go back to main menu." << endl;
	cout << "Enter your choice:";
	fseek(stdin, 0, SEEK_END);
	return(getchar());
}

void MenuManager::InternalProgrammer1()
{
	long id;
	int input;
	while (1)
	{
		switch (InternalProgrammer2())
		{
		case '1':
		{
			cout << "enter an programmer's id: ";
			cin >> id;
			Programmer* p1 = (Programmer*)searchObject(id);
			if (p1 == NULL)break;
			if (!strcmp(typeid(Programmer).name(), typeid(*p1).name()))
				cout << "Experience Of programmer with id " << id << " is: " << p1->getExperience() << endl;
			else
				cout << "This employee is not a programmer." << endl;
			break;
		}
		case '2':
		{
			cout << "enter an programmer's id: ";
			cin >> id;
			Programmer* p1 = (Programmer*)searchObject(id);
			if (p1 == NULL)break;
			if (!strcmp(typeid(Programmer).name(), typeid(*p1).name()))
			{
				cout << "Enter the new experience's value you want: ";
				cin >> input;
				p1->setExperience(input);
			}
			else
				cout << "This employee is not a programmer." << endl;
			break;
		}
		case '3':
		{
			cout << "enter an programmer's id: ";
			cin >> id;
			Programmer* p1 = (Programmer*)searchObject(id);
			if (p1 == NULL)break;
			if (!strcmp(typeid(Programmer).name(), typeid(*p1).name()))
			{
				p1->isASenior();
				break;
			}
			else
				cout << "This employee is not a programmer." << endl;
			break;
		}
		case '4':
		{
			cout << "enter an programmer's id: ";
			cin >> id;
			Programmer* p1 = (Programmer*)searchObject(id);
			if (p1 == NULL)break;
			if (!strcmp(typeid(Programmer).name(), typeid(*p1).name()))
			{
				bool check = p1->programInCplusplus();
				if (check == true)
					cout << "This programmer is programming in c++." << endl;
				else
					cout << "This programmer is not programming in c++." << endl;
			}
			else
			cout<< "This employee is not a programmer." << endl;
			break;
		}

		case '0': return;
		default: cout << endl << "Wrong. Please try again" << endl << endl;
		}
	}
}

char MenuManager::InternalProgrammer2()
{
	cout << endl<<"=======================================" << endl;
	cout << "(In all the option you required to enter an id)" << endl;
	cout << " 1. Show programmer's experience (getExperience)." << endl;
	cout << " 2. Change programmer's experience (setExperience)." << endl;
	cout << " 3. Check if programmer is a senior." << endl;
	cout << " 4. Check if programmer is programming in c++." << endl;

	cout << " 0. Go back to main menu." << endl;
	cout << "Enter your choice:";
	fseek(stdin, 0, SEEK_END);
	return(getchar());
}

void MenuManager::InternalTeamLeader1()
{
	long id;
	int input;
	while (1)
	{
		switch (InternalTeamLeader2())
		{
		case '1':
		{
			cout << "enter an team leader's id: ";
			cin >> id;
			TeamLeader* t1 = (TeamLeader*)searchObject(id);
			if (t1 == NULL)break;
			if (!strcmp(typeid(TeamLeader).name(), typeid(*t1).name()))
			{
				t1->Add(createProgrammer());
			}
			else
				cout << "This employee is not a team leader." << endl;
			break;
		}
		case '2':
		{
			cout << "enter an team leader's id: ";
			cin >> id;
			TeamLeader* t1 = (TeamLeader*)searchObject(id);
			if (t1 == NULL)break;
			if (!strcmp(typeid(TeamLeader).name(), typeid(*t1).name()))
			{
				if (t1->getNumOfEmployees() == 0)
				{
					cout << "This team leader has no programmers under him." << endl;
				}
				else
					cout<< "The avrage age of the programmers under this team leader is: "<< t1->avrageAge();
			}
			else
				cout << "This employee is not a team leader." << endl;

			break;
		}
		case '0': return;
		default: cout << endl << "Wrong. Please try again" << endl << endl;
		}
	}
}

char MenuManager::InternalTeamLeader2()
{
	cout << endl <<"=======================================" << endl;
	cout << "(In all the option you required to enter an id)" << endl;
	cout << " 1. Add programmer for a specific team leader." << endl;
	cout << " 2. Calculate the avrage age of a specific team of team leader." << endl;
	cout << " 0. Go back to main menu." << endl;
	cout << "Enter your choice:";
	fseek(stdin, 0, SEEK_END);
	return(getchar());
}
