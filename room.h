#ifndef ROOM_CLASS
#define ROOM_CLASS
#include "tree.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <sstream>
#include <limits.h>

using namespace std;

class room
{
	public:
		room();//constructor
		void splitfullName(string FLLN);//takes in fullName string and splits it to firstName and lastName
		void setfirstName(string FN);//is used in splitfullName
		void setlastName(string LN);//is used in splitfullName
		void setReward();//sets the amount of gold for each room
		string getfirstName();//returns first name
		string getlastName();//returns last name
		int getReward();//returns gold in each room
		int getA();//returns A for the A * X + B wizard function
		int getB();//returns B for wizard function
		void printInfo();//prints out the message for each room
		friend class girl;

	private:
		string fullName;
		string firstName;
		string lastName;
		int reward;
		int A;
		int B;
};
#endif
