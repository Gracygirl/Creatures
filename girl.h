#ifndef GIRL_CLASS
#define GIRL_CLASS
#include "room.h"
#include "tree.h"
#include <iostream>

using namespace std;

class girl
{
	public:
		girl();//constructor
		void insertRooms(room newRoom);//inserts each new room node into tree
		int reward();//returns the total gold
		bool gameOver();//check for gold that is <0 or if player has reached the wizard
		void countRooms();//counts how many room the player has overall visited
		void countElfRooms();
		void countMonsterRooms();
		void countWizardRooms();
		void setReward(string gold);//sets the starting gold
		void nextMove(string move);//set next move and determine the course of action for the player
		void printGirlStatus();//prints how many rooms visited and how much total gold is
		void printTree();//temp debug function, prints out tree
		void resetRoomCount();//resets all room counters to 0
		room getCurrentRoom();//gets current -> data 
		TreeType<room> getTree();//returns the whole tree
		void GirltoStart(); //sets girl to the starting position
		friend class room;
		friend class tree;

	private:
		TreeType<room> MazeTree; 
		int StartGold;	
		int RoomCount;
		int elfRoomCount;
		int monsterRoomCount;
		int wizardRoomCount;
		int totalReward;
		string newMove;
};
#endif
