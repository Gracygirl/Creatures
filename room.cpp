#include "room.h"

using namespace std;

room::room()
{
	firstName = "Enter First Name";
	lastName = "Enter Last Name";
	reward = 0;
	A = 0;
	B = 0;
}

void room::splitfullName(string FLLN)
{
	string FN, LN;

	istringstream NAME( FLLN );
	getline( NAME, FN, ' ');
	getline( NAME, LN, ' ');

	setfirstName(FN);
	setlastName(LN);	

//	cout << FN << " " << LN << endl;

}
	

void room::setfirstName(string FN)
{
	firstName = FN;
}

void room::setlastName(string LN)
{
	lastName = LN;
}


void room::setReward()
{
	int R;
	int number;
	if ((lastName == "elf") || (lastName == "Elf"))
	{
        	R = (rand()%(30-5))+5;
		reward = R;
	}
	else if ((lastName == "monster") || (lastName == "Monster"))
	{
		R = (rand()%(30-5))+5;
		R = R * -1 ;
		reward = R;
	}
	else if ((lastName == "wizard") || (lastName == "Wizard"))
	{
		A = rand()%10 + 1;
		B = rand()%10 + 1;
	}			
}

string room::getfirstName()
{
	return firstName;
}

string room::getlastName()
{
	return lastName;
}

int room::getReward()
{
	return reward;
}

int room::getA()
{
	return A;
}

int room::getB()
{
	return B;
}

void room:: printInfo()
{
	if ((lastName == "elf") || (lastName == "Elf"))
	{
	
		cout << "You find a " << firstName << " " << lastName << " and he gives you " << reward << " gold." << endl;
		cout << 		
"                ___,@\n"
"               /  <\n"
"          ,_  /    \\  _,\n"
"           \\`/______\\`/\n"
"   ,_ _ .  |; (e  e) ;|\n"
"    \\___ \\ \\/\\   7  /\\/    _\\8/_\n"
"        \\/\\   \\'=='/      | /| /|\n"
"         \\ \\___)--(_______|//|//|\n"
"          \\___  ()  _____/|/_|/_|\n"
"             /  ()  \\    `----'\n"
"            /   ()   \\\n"
"           '-.______.-'\n"
"         _    |_||_|    _\n"
"        (@____) || (____@)\n"
"         \\______||______/\n" << endl;

		
	}
	else if ((lastName == "monster") || (lastName == "Monster"))
	{
		cout << "You find a  " << firstName << " " << lastName << " and it steals " << (reward * -1) << " gold from you." << endl << endl;
		
		cout << 
		
"             \\                  /\n"
"    ________'_))                ((__________\n"
"   /.-------./\\\\    \\    /    //\\.--------.\\\n"
"  //#######//##\\\\   ))  ((   //##\\\\########\\\\\n"
" //#######//###((  ((    ))  ))###\\\\########\\\\\n"
"((#######((#####\\\\  \\\\  //  //#####))########))\n"
" \\##' `###\\######\\\\  \\)(/  //######/####' `##/\n"
"  )'    ``#)'  `##\\`->oo<-'/##'  `(#''     `(\n"
"          (       ``\\`..'/''       )\n"
"                     \\""(\n"
"                      `- )\n"
"                      / /\n"
"                     ( /\\  \n"
"                     /\\| \\\n"
"                    (  \\\n"
"                        )\n"
"                       /\n"
"                      (\n" << endl;

	}
	else if ((lastName == "wizard") || (lastName == "Wizard"))
	{
		cout << "You find a " << firstName << " " << lastName << " and he uses the magic multiplayer ";
		
	}
}
