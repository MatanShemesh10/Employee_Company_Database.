#include <iostream>
#include <fstream>
#include "MenuManager.h"
#include "Person.h"
#include "Programmer.h"
#include "Address.h"
#include "Designer.h"
#include "productManager.h"
#include "TeamLeader.h"
using namespace std;

Designer readDesigner(char buffer[150])
{
	int i = 0;
	char name[15];
	long id = 0;
	int age = 0;
	double weight = 0;
	int seniority = 0;
	char tempArrayChar[100];
	string designProgram;
	char city[100];
	string street;
	int houseNo = 0;
	vector<string> tasks;
	int counter = 0;//count how many commas ','
	while (buffer[i] != '\0')
	{
		int j = 0;
		while (buffer[i] != ',' && buffer[i] != '\0')
		{
			if (counter == 0)//insert name
			{
				name[j] = buffer[i];
				j++;
			}
			else if (counter == 1)//insert id
			{
				id = id * 10;
				id += (int)(buffer[i] - '0');
			}
			else if (counter == 2)//insert age
			{
				age = age * 10;
				age += (int)(buffer[i] - '0');
			}
			else if (counter == 3)//insert weight
			{
				if (buffer[i] == '.') {
					double temp = 0;
					double temp2 = 0.1;
					i++;
					while (buffer[i] != ',')
					{
						temp += (double)(buffer[i] - '0') * temp2;
						temp2 *= 0.1;
						i++;
					}
					temp2 = 0.1;
					weight += temp;
					break;
				}
				weight = weight * 10;
				weight += (int)(buffer[i] - '0');
			}
			else if (counter == 4)//insert seniority
			{
				seniority = seniority * 10;
				seniority += (int)(buffer[i] - '0');
			}
			else if (counter == 5)//insert designProgram
			{
				tempArrayChar[j] = buffer[i];
				j++;
			}
			else if (counter == 6)//insert city
			{
				city[j] = buffer[i];
				j++;
			}
			else if (counter == 7)//insert street
			{
				tempArrayChar[j] = buffer[i];
				j++;
			}
			else if (counter == 8)//insert houseNo
			{
				houseNo = houseNo * 10;
				houseNo += (int)(buffer[i] - '0');
			}
			else if (counter > 8)//insert taskes
			{
				tempArrayChar[j] = buffer[i];
				j++;
			}
			i++;
		}
		if (counter == 0)
			name[j] = '\0';
		if (counter == 5)
		{
			tempArrayChar[j] = '\0';
			string temp(tempArrayChar);
			designProgram = temp;
		}
		if (counter == 6)
			city[j] = '\0';
		if (counter == 7)
		{
			tempArrayChar[j] = '\0';
			string temp(tempArrayChar);
			street = temp;
		}
		if (counter > 8)
		{
			tempArrayChar[j] = '\0';
			string temp(tempArrayChar);
			tasks.push_back(temp);
		}
		counter++;
		j = 0;
		if (buffer[i] == '\0')
			i--;
		i++;
	}
	Address a1(city, street, houseNo);
	Address* myAddress = new Address;
	*myAddress = a1;
	Designer d1(name, id, age, weight, seniority, designProgram, myAddress, tasks);
	return d1;
}//function the read a designer
Programmer readProgrammer(char buffer[150])
{
	int i = 0;
	char name[15];
	long id = 0;
	int age = 0;
	double weight = 0;
	int experience = 0;
	char tempArrayChar[100];
	string programLanguage;
	int counter = 0;//count how many commas ','
	while (buffer[i] != '\0')
	{
		int j = 0;
		while (buffer[i] != ',' && buffer[i] != '\0')
		{
			if (counter == 0)//insert name
			{
				name[j] = buffer[i];
				j++;
			}
			else if (counter == 1)//insert id
			{
				id = id * 10;
				id += (int)(buffer[i] - '0');
			}
			else if (counter == 2)//insert age
			{
				age = age * 10;
				age += (int)(buffer[i] - '0');
			}
			else if (counter == 3)//insert weight
			{
				if (buffer[i] == '.') {
					double temp = 0;
					double temp2 = 0.1;
					i++;
					while (buffer[i] != ',')
					{
						temp += (double)(buffer[i] - '0') * temp2;
						temp2 *= 0.1;
						i++;
					}
					temp2 = 0.1;
					weight += temp;
					break;
				}
				weight = weight * 10;
				weight += (int)(buffer[i] - '0');
			}
			else if (counter == 4)//insert seniority
			{
				experience = experience * 10;
				experience += (int)(buffer[i] - '0');
			}
			else if (counter == 5)//insert programLanguage
			{
				tempArrayChar[j] = buffer[i];
				j++;
			}
			i++;
		}
		if (counter == 0)
			name[j] = '\0';
		if (counter == 5)
		{
			tempArrayChar[j] = '\0';
			string temp(tempArrayChar);
			programLanguage = temp;
		}
		counter++;
		j = 0;
		if (buffer[i] == '\0')
			i--;
		i++;
	}
	Programmer p1(name, id, age, weight, experience, programLanguage);
	return p1;
}//function the read a programmer
TeamLeader readTeamLeader(char buffer[150])
{
	int i = 0;
	char name[15];
	long id = 0;
	int age = 0;
	double weight = 0;
	int experience = 0;
	char tempArrayChar[100];
	string programLanguage;
	char nameOfTeam[100];
	double salary = 0;
	int counter = 0;//count how many commas ','
	while (buffer[i] != '\0')
	{
		int j = 0;
		while (buffer[i] != ',' && buffer[i] != '\0')
		{
			if (counter == 0)//insert name
			{
				name[j] = buffer[i];
				j++;
			}
			else if (counter == 1)//insert id
			{
				id = id * 10;
				id += (int)(buffer[i] - '0');
			}
			else if (counter == 2)//insert age
			{
				age = age * 10;
				age += (int)(buffer[i] - '0');
			}
			else if (counter == 3)//insert weight
			{
				if (buffer[i] == '.') {
					double temp = 0;
					double temp2 = 0.1;
					i++;
					while (buffer[i] != ',')
					{
						temp += (double)(buffer[i] - '0') * temp2;
						temp2 *= 0.1;
						i++;
					}
					temp2 = 0.1;
					weight += temp;
					break;
				}
				weight = weight * 10;
				weight += (int)(buffer[i] - '0');
			}
			else if (counter == 4)//insert experience
			{
				experience = experience * 10;
				experience += (int)(buffer[i] - '0');
			}
			else if (counter == 5)//insert number of employees
			{
				tempArrayChar[j] = buffer[i];
				j++;
			}
			else if (counter == 6)//insert name of team
			{
				nameOfTeam[j] = buffer[i];
				j++;
			}
			else if (counter == 7)//insert salary
			{
				if (buffer[i] == '.') {
					double temp = 0;
					double temp2 = 0.1;
					i++;
					while (buffer[i] != ',')
					{
						temp += (double)(buffer[i] - '0') * temp2;
						temp2 *= 0.1;
						i++;
					}
					temp2 = 0.1;
					salary += temp;
					break;
				}
				salary = salary * 10;
				salary += (int)(buffer[i] - '0');
			}
			i++;
		}
		if (counter == 0)
			name[j] = '\0';
		if (counter == 5)
		{
			tempArrayChar[j] = '\0';
			string temp(tempArrayChar);
			programLanguage = temp;
		}
		if (counter == 6)
			nameOfTeam[j] = '\0';
		counter++;
		j = 0;
		if (buffer[i] == '\0')
			i--;
		i++;
	}
	TeamLeader t1(name, id, age, weight, experience, programLanguage, nameOfTeam, salary);
	return t1;
}//function the read a team leader
vector<Person*> readingFromFile()
{
	vector<Person*> MnA;
	ifstream myFile("myText.txt", ios::in);
	char buffer[150];
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile.getline(buffer, 150);
			Designer d1 = readDesigner(buffer);
			Designer* d2 = new Designer;
			*d2 = d1;
			MnA.push_back(d2);

			myFile.getline(buffer, 150);
			Designer d3 = readDesigner(buffer);
			Designer* d4 = new Designer;
			*d4 = d3;
			MnA.push_back(d4);

			myFile.getline(buffer, 150);
			Programmer p1 = readProgrammer(buffer);
			Programmer* p2 = new Programmer;
			*p2 = p1;
			MnA.push_back(p2);

			myFile.getline(buffer, 150);
			Programmer p3 = readProgrammer(buffer);
			Programmer* p4 = new Programmer;
			*p4 = p3;
			MnA.push_back(p4);

			myFile.getline(buffer, 150);
			TeamLeader t1 = readTeamLeader(buffer);//we create the txt file by asumming that the team leaders have no programmers for easier scan to the database
			t1.setNumOfEmployees(0);
			TeamLeader* t2 = new TeamLeader;
			*t2 = t1;
			MnA.push_back(t2);

			myFile.getline(buffer, 150);
			TeamLeader t3 = readTeamLeader(buffer);
			t3.setNumOfEmployees(0);
			TeamLeader* t4 = new TeamLeader;
			*t4 = t3;
			MnA.push_back(t4);
		}
	}
	myFile.close();
	return MnA;

}
void printToTxtFile(MenuManager myMenuManager)
{
	try {
		ofstream Myfile("OUT.txt");
		if (!Myfile.is_open())throw exception("the file did not open\n");

		Myfile << myMenuManager;
		Myfile.close();
	}
	catch (exception ex) {
		cout << ex.what();
	}
}

void main()
{
	vector<Person*> MnA;//our company name(matan and ariel)
	MnA = readingFromFile();
	MenuManager myMenuManager(MnA);
	try
	{
		myMenuManager.StartProgram();
	}
	catch (const char* emsg)	{cout << emsg<<endl;}
	printToTxtFile(myMenuManager);
	cout << "The database send all the employees information to a txt file called OUT.txt." << endl<<"Good bye." <<endl;
}


