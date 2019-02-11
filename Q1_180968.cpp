#include<iostream>
#include "Header.h"
using namespace std;

int main()
{
	Cricketteam Pakistan("Q1_180968_in");
	Cricketteam India;
	Pakistan.printinformation();
	Pakistan.Inputanotherteam(India);
	return 0;
}
