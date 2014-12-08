#include "tree.h"
#include "room.h"
#include "girl.h"
#include <cctype>
#include <cstring>

using namespace std;

int main( int argc, char *argv[] )
{
	if ( argc != 2)
	{
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else
	{
		char choice;
		int numGames = 0;
		string newFile;
		char charFile[100];

		do{
			if (numGames != 0)
			{
				
				system("clear");
				cout << "Please enter new file: ";
				cin >> newFile;
				
			}
			else
			{
				newFile = argv[1];
			}
		
			strcpy(charFile, newFile.c_str());	
			ifstream MazeTxt (charFile);
		
			
			if (!MazeTxt.is_open())
			{
				cout << "Could not open file. Quitting program." << endl;
				return 0;
			}
			else 
			{
				
				int check; 
				
				girl myGirl;
				string Full;
				room Start;			
				getline(MazeTxt, Full);	
				Start.splitfullName(Full);
				check = atoi(Start.getlastName().c_str());
				if (check == 0)
				{
					cout << "Incorrect File Structure. Please change '" << Start.getlastName() << "' to a legal number and restart the program." << endl;
					return 0;
				}
				if ((Start.getfirstName() != "Start") && (Start.getfirstName() != "start"))
				{
					cout << "Please check file. Make sure first line reads in either 'start' or 'Start'. " << endl;
					return 0;
				}
		
				myGirl.setReward(Start.getlastName());
				myGirl.insertRooms(Start);
		
				while (getline(MazeTxt, Full))
				{
					room newRoom;
					newRoom.splitfullName(Full);
					if (((newRoom.getlastName() != "elf") && (newRoom.getlastName() != "Elf"))&&((newRoom.getlastName() != "monster")
						&& (newRoom.getlastName() != "Monster")) && ((newRoom.getlastName() != "wizard") && (newRoom.getlastName() != "Wizard")))
					{
						cout << "Please check file. Incorrect character type detected. " << endl;
						return 0;
					}
					newRoom.setReward();
					myGirl.insertRooms(newRoom);
					//cout << "Press Enter to Continue" << endl;
					//cin.ignore();
				}
	
					string move;
					system("clear");
					myGirl.setReward(Start.getlastName());
					myGirl.resetRoomCount();
					myGirl.GirltoStart();
					cout << "!!!!WELCOME TO MOVETRACK CASTLE!!!!" << endl;
					cout << 
		
		"                                       /\\ \n"
		"                                      /`:\\ \n"
		"                                     /`'`:\\ \n"
		"                                    /`'`'`:\\ \n"
		"                                   /`'`'`'`:\\ \n"
		"                                  /`'`'`'`'`:\\ \n"
		"                                   |`'`'`'`:|   \n"
		"     _ _  _  _  _                  |] ,-.  :|_  _  _  _\n"
		"    ||| || || || |                 |  |_| ||| || || || |\n" 
		"    |`' `' `' `'.|                 | _'=' |`' `' `' `'.|\n"
		"    :          .:;                 |'-'   :          .:;\n"
		"     \\-..____..:/  _  _  _  _  _  _| _  _'-\\-..____..:\n"
		"      :--------:_,' || || || || || || || `.::--------:\n"
		"      |]     .:|:.  `' `'_`' `' `' `' `'    | '-'  .:|\n"
		"      |  ,-. .[|:._     '-' ____     ___    |   ,-.'-|\n"
		"      |  | | .:|'--'_     ,'____`.  '---'   |   | |.:|\n"
		"      |  |_| .:|:.'--' ()/,| |`|`.\\()   __  |   |_|.:|\n"
		"      |  '=' .:|:.     |::_|_|_|\\|::   '--' |  _'='.:|\n"
		"      | __   .:|:.     ;||-,-,-,-,|;        | '--' .:|\n"
		"      |'--'  .:|:. _  ; ||       |:|        |      .:|\n"
		"      |      .:|:.'-':  ||       |;|     _  |]     _:|\n"
		"      |      '-|:.   ;  ||       :||    '-' |     '--|\n"
		"      |  _   .:|].  ;   ||       ;||]       |   _  .:|\n"
		"      | '-'  .:|:. :   [||      ;|||        |  '-' .:|\n"
		"  ,', ;._____.::-- ;---->'-,--,:-'<'--------;._____.::.`.\n"
		" ((  (          )_;___,' ,' ,  ; //________(          ) ))\n"
		"  `. _`--------' : -,' ' , ' '; //-       _ `--------' ,'\n"
		"       __  .--'  ;,' ,'  ,  ': //    -.._    __  _.-  -\n"
		"   `-   --    _ ;',' ,'  ,' ,;/_  -.       ---    _,\n"
		"       _,.   /-:,_,_,_,_,_,_(/:-\\   ,     ,.    _\n"
		"      -'   `-'--'-'-'-'-'-'-'-''--'-' `-'`'  `'`' `" << endl;
					cout << "Press Enter to enter the castle" << endl;
					cin.ignore();
					system("clear");
		
					cout << "Once you enter the castle, you realize the interior is built like a maze!";
					cout << " Quickly find one of the wizards before the monsters steal all of your gold!" << endl;
					cout << "Starting Gold: " << myGirl.reward() << endl;
					do{
						cout <<
		
		"      ______                  ______\n"
		"   ,-' ;  ! `-.            ,-' ;  ! `-.\n"
		"  / :  !  :  . \\          / :  !  :  . \\ \n"
		" |_ ;     :  ;  |        |_ ;     :  ;  |\n"
		" )| .  ;  :  !  |        )| .  ;  :  !  |\n"
		" |           _  |        |           _  |\n"
		" |  :  ;    (_) (        |  :  ;    (_) (\n"
		" |  :  :  .     |        |  :  :  .     |\n"
		" )_ !  ,  ;  ;  |        )_ !  ,  ;  ;  |\n"
		" || .  .  :  :  |        || .  .  :  :  |\n"
		" |  .  |  :  .  |        |  .  |  :  .  |\n"
		" |.. _ _________|        |.. _ _________|" << endl << endl;
		
						cout << "In front of you are two doors: one to the left and one to the right. Which one do you choose? (l/r): ";
						cin >> move;
						cout << endl << endl;
						myGirl.nextMove(move);
						if (((move == "right")||(move == "r"))||(move == "left") || (move == "l"))
						{
							myGirl.getCurrentRoom().printInfo();
								cout << endl;
						}
						else
						{
							cout << "What are you doing? You need to find a wizard! Go left or go right!" << endl;
						}
						myGirl.reward();
						myGirl.countRooms();
						myGirl.printGirlStatus();
	
					}while(!myGirl.gameOver());
				
					cout << "Would you like to play again? (y/n): " << endl;
					cin >> choice;
					if (((choice != 'y') && (choice != 'Y')) && ((choice != 'n')&&(choice != 'N')))
					{
						cout << "Incorrect Format. Quiting program." << endl;
						choice = 'n';
					}
					else
					{
						numGames++;
					}
				
		}
	}while((choice != 'n') && (choice != 'N'));	
	return 0;	
}}							
