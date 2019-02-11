#include<iostream>
#include "Header.h"
using namespace std;

int main()
{
	Cricketteam Pakistan("cricket.txt");
	Cricketteam India;
	Pakistan.printinformation();
	Pakistan.Inputanotherteam(India);
	return 0;
}