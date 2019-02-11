#include"Header.h"
#include<iostream>
#include<fstream>
using namespace std;
//Fucntion to get captain name
string Cricketteam:: getcaptain()
{
	return *captain;
}
//Function to get Team name
char* Cricketteam::getteamname()
{
	return teamName;
}
//Function to get no of members
int Cricketteam::get_no_of_members()
{
	return no_of_members;
}
//Function to set Captain name
void Cricketteam::setcaptain(string cap)
{
	if(captain!=nullptr)
	{
		delete captain;
	}
	captain=new string;
	*captain=cap;
}
//Function to set Team name
void Cricketteam::setteamName(string teamname)
{
	if(teamName!=nullptr)
	{
		delete teamName;
	}
	int size = teamname.length();
	teamName=new char[size + 1];
	strcpy(teamName, teamname.c_str());
}
//Function to set No. Of Members
void Cricketteam::set_no_of_members(int no)
{
	if(no<0)
	{
		no_of_members=0;
	}
	else
	{
		no_of_members=no;
	}
}
//Parametrized Constructor 1
Cricketteam::Cricketteam()
{
	teamName=nullptr;
	no_of_members=0;
	for(int i=0;i<10;i++)
	{
		Scoreinlast10matches[i]=0;
	}
	Rank=0;
	captain=nullptr;
	membernames=nullptr;
}

//Parameterized Constructor 2
Cricketteam::Cricketteam(string name, int noofmembers)
{
	if(teamName!=nullptr)
	{
		strcpy(teamName,name.c_str());
	}
	else
	{
		name=" ";
	}
	if(noofmembers<0)
	{
		no_of_members=0;
	}
	else
	{
		no_of_members=noofmembers;
	}
	membernames=nullptr;
	for(int i=0;i<10;i++)
	{
		Scoreinlast10matches[i]=0;
	}
	Rank=0;
	captain=nullptr;
}
//Parameterized Constructor 3
Cricketteam::Cricketteam(string filepath)
{
	char buff[500];
	ifstream fin(filepath);
	if(!fin)
	{
		cout<<"----Error----"<<endl;
	}
	fin.getline(buff,500,':');
	fin.getline(buff,500,'\n');
	teamName=new char[strlen(buff)+1];
	strcpy(teamName,buff);
	fin.getline(buff,500,':');
	fin.getline(buff,500,'\n');
	no_of_members=atoi(buff);
	membernames=new string[no_of_members];
	for(int i=0;i<no_of_members;i++)
	{
		getline(fin,membernames[i]);
	}
	fin.getline(buff,500,':');
	fin.getline(buff,500,'\n');
	Rank=atoi(buff);
	fin.getline(buff,500,':');
	fin.getline(buff,500,'\n');
	captain=new string;
	string s(buff);
	*captain = s;
	fin.getline(buff,500,':');
	fin.getline(buff,500);
	char buffa[500];
	int j=0;
	int l=0;
	for(int i=0;buff[i]!='\0';i++)
	{
		if(buff[i]!=',')
		{
			buffa[j]=buff[i];
			j++;
		}
		else
		{
			buffa[j]='\0';
			int k=atoi(buffa);
			Scoreinlast10matches[l]=k;
			l++;
			j=0;
		}
	}
}
//Input team Member Function
void Cricketteam::inputTeamMember(string name)
{
	if(membernames!=nullptr&&no_of_members==11)
	{
		cout<<"The Team is full";
	}
	else if(membernames!=nullptr&&no_of_members!=11)
	{
		membernames[11]=name;
	}
}
//Function to print Average
int Cricketteam::average()
{
	int avg=0;
	for(int i=0;i<10;i++)
	{
		avg=(avg+Scoreinlast10matches[i]);
	}
	avg=avg/10;
	return avg;
}
//Function to take input in Score
void Cricketteam::inputScore(int score)
{
	for(int i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(Scoreinlast10matches!=nullptr)
			{
				Scoreinlast10matches[i]=Scoreinlast10matches[j];
				Scoreinlast10matches[9]=score;
			}
			else
			{
				cout<<"Enter the value of Score :";
				cin>>Scoreinlast10matches[i];
			}
		}
	}
	
}
//Function that Prints latest score with team name and Captain Name
void Cricketteam::prints()
{
	cout<<"The latest score of the team is :"<<Scoreinlast10matches[9]<<endl;
	cout<<"The name of the team is :"<<teamName<<endl;
	cout<<"The name of the Captain is :"<<captain<<endl;
}
//Function that Prints all Information
void Cricketteam::printinformation()
{
	cout<<"The name of the team is :"<<teamName<<endl;
	cout<<"The no. of Members of the team is :"<<no_of_members;
	cout<<"The team Members are :";
	for(int i=0;i<11;i++)
	{
		cout<<membernames[i]<<endl;
	}
	cout<<"The Rank is :"<<Rank<<endl;
	cout<<"The name of the captain is :"<<captain<<endl;
	cout<<"Score :";
	for(int i=0;i<10;i++)
	{
		cout<<Scoreinlast10matches[i]<<" ";
	}
}
//Function that Compares two Teams with better Score Average
void Cricketteam::Compare(Cricketteam & C)
{
	if(average()>C.average())
	{
		cout<<"The team which is better is :"<<teamName;
	}
	else if(C.average()>average())
	{
		cout<<"The team which is better is :"<<C.teamName;
	}
}
//Destructor
Cricketteam::~Cricketteam()
{
	if(membernames!=nullptr)
	{
		delete membernames;
		membernames=nullptr;
	}
	no_of_members=0;
	if(teamName!=nullptr)
	{
		delete teamName;
		teamName=nullptr;
	}
	for(int i=0;i<10;i++)
	{
		Scoreinlast10matches[i]=0;
	}
	Rank=0;
	if(captain!=nullptr)
	{
		delete captain;
		captain=nullptr;
	}
}
//Get data for another team
void Cricketteam::Inputanotherteam(Cricketteam& anotherteam)
{
	cout<<"Enter the name of the team :";
	cin>>anotherteam.teamName;
	cout<<"Ente the no of Members :";
	cin>>anotherteam.no_of_members;
	cout<<"Enter the Member Name :";
	for(int i=0;i<no_of_members;i++)
	{
		cin>>anotherteam.membernames[i];
	}
	cout<<"Enter the Rank for the Team :";
	cin>>anotherteam.Rank;
	cout<<"Enter the score for last 10 matched :";
	for(int i=0;i<10;i++)
	{
		cin>>anotherteam.Scoreinlast10matches[i];
	}
}