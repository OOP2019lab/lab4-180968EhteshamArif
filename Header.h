#include<string>
using namespace std;
class Cricketteam
{
public:
    string * membernames;
    int no_of_members;
    char *teamName;
    int Scoreinlast10matches[10];
    int Rank;
    string *captain;
	Cricketteam();
	Cricketteam(string name, int noofmembers);
	Cricketteam(string filepath);
	string getcaptain();
	char* getteamname();
	int get_no_of_members();
	void setcaptain(string cap);
	void setteamName(string);
	void set_no_of_members(int);
	void inputTeamMember(string name);
	int average();
	void inputScore(int score);
	void prints();
	void printinformation();
	void Compare(Cricketteam &);
	void Inputanotherteam(Cricketteam &);
	~Cricketteam();
};