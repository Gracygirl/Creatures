#include "room.h"
#include "tree.h"
#include "girl.h"
#include <iostream>
#include <string>

using namespace std;

girl::girl()
{
	RoomCount = 0;
	elfRoomCount = 0;
	monsterRoomCount = 0;
	wizardRoomCount = 0;
	newMove = "Unknown";
	MazeTree;
}
void girl::GirltoStart()
{
	MazeTree.setCurrentToRoot();
}
void girl::insertRooms(room newRoom)
{

	MazeTree.Insert(newRoom);

}
void girl::setReward(string gold)
{

	totalReward = atoi(gold.c_str());

}

void girl::resetRoomCount()
{
	RoomCount = 0;
	elfRoomCount = 0;
	monsterRoomCount = 0;
	wizardRoomCount = 0;
}

int girl::reward()
{

	if ((newMove == "left") || (newMove =="right"))
	{

		if ((MazeTree.getCurrentData().getlastName() == "wizard")||(MazeTree.getCurrentData().getlastName() == "Wizard"))
		{
			cout << MazeTree.getCurrentData().getA() << " x " << totalReward << " + " << MazeTree.getCurrentData().getB() << " on your gold!" << endl << endl;
			totalReward = (MazeTree.getCurrentData().getA() * totalReward) + MazeTree.getCurrentData().getB();		
			cout <<
"              *\n"
"             / \\\n"
"            /___\\\n"
"           ( o o )            * *\n"
"           )  L  (           /   * *\n"
"   ________()(-)()________  /     * * *\n"
" E\\| _____ )()()() ______ |/B     * * *\n"
"   |/      ()()()(       \\|      * * * *\n"
"           | )() |\n"
"           /     \\\n"
"          / *  *  \\\n"
"         /   *  *  \\\n"
"        / *_  *  _  \\ \n" 
"                          " << endl;
		}
		else if ((MazeTree.getCurrentData().getlastName() == "monster") || (MazeTree.getCurrentData().getlastName() == "Monster") 
			|| (MazeTree.getCurrentData().getlastName() == "elf") || (MazeTree.getCurrentData().getlastName() == "Elf"))
		{
			totalReward += MazeTree.getCurrentData().getReward();
		}
	}
	else
	{
		//do nothing
	}
	
	return totalReward; 	
}

bool girl::gameOver()
{
	if (totalReward <= 0)
	{
		cout << "Final Statistics: " << endl;
		cout << "Monster Rooms Visited: " << monsterRoomCount << endl;
		cout << "Elf Rooms Visited: " << elfRoomCount << endl;
		cout << "Wizard Rooms Visited: " << wizardRoomCount << endl;
		cout << "Your total gold: " << totalReward << endl;	
		return true;
	}
	else if (MazeTree.getCurrentData().getlastName() == "wizard")
	{
		cout << "Final Statistics: " << endl;
		cout << "Monster Rooms Visited: " << monsterRoomCount << endl;
		cout << "Elf Rooms Visited: " << elfRoomCount << endl;
		cout << "Wizard Rooms Visited: " << wizardRoomCount << endl;
		cout << "Your total gold: " << totalReward << endl;	
		return true;
	} 
	else
	{
		return false;
	}	
}

void girl::countRooms()
{
	if ((newMove == "left") || (newMove == "right"))
	{
		RoomCount++;
	}

	if ((MazeTree.getCurrentData().getlastName() == "wizard")||(MazeTree.getCurrentData().getlastName() == "Wizard"))
	{
		wizardRoomCount++;
	}
	else if ((MazeTree.getCurrentData().getlastName() == "elf")||(MazeTree.getCurrentData().getlastName() == "Elf"))
	{
		elfRoomCount++;
	}
	else if ((MazeTree.getCurrentData().getlastName() == "monster")||(MazeTree.getCurrentData().getlastName() == "Monster"))
	{
		monsterRoomCount++;
	}
	
}

void girl::countElfRooms()
{
	elfRoomCount++;
}

void girl::countMonsterRooms()
{
	monsterRoomCount++;
}

void  girl::countWizardRooms()
{
	wizardRoomCount++;
}

TreeType<room> girl::getTree()
{
	return MazeTree;
}


void girl::nextMove(string move)
{

	if ((move == "right")||(move == "r"))
	{
		newMove = "right";
		cout << "You open the right door and step through!" << endl;
		MazeTree.moveCurrentRight();
	}
	else if ((move == "left")||(move == "l"))
	{
		newMove = "left";
		cout << "You open the left door and step through!" << endl;
		MazeTree.moveCurrentLeft();
	}
	else
	{
		newMove = "Incorrect";
//		cout << "Incorrect Format. Try Again." << endl;
	}
	
}


void girl::printGirlStatus()
{

	cout << "You have visited " << RoomCount << " rooms." << endl;
	cout << "You're total gold is " << totalReward << "." << endl << endl << endl;

}

room girl::getCurrentRoom()
{
        return	MazeTree.getCurrentData();
}

void girl::printTree()
{
	MazeTree.Print();
}
