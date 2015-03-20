//main.cpp

#include <iostream>
using std::cout;
using std::endl;

#include "gamePlay.h"	//let the games begin

int main()
{	cout 	<< endl
	 	<< "        WELCOME TO BAJAN BATTLESHIP" << endl
		 << "      A test of wits, will, and might" << endl;

	cout 	<< endl
		 << "  Bajan Battleship is a two player game. Each places their five" << endl
		 << "  ships in a line then take turns attempting to hit the other's" << endl 
		 << "  ships. To hit a ship, a player enters a location (0 through 69)." << endl
		 << "  If an enemy ship is in this location, it qualifies as a hit and" << endl
		 << "  the player gets another turn. If the player misses, the other " << endl
		 << "  player gets a crack at the enemy." << endl;

	getc(stdin);
	int end = gamePlay();

	cout 	<< endl
		 << "         We hope you enjoyed the game  " << endl
		 << "       ** A product of impaqSoftware **" << endl
		 << "                Copyright MMIX         " << endl;
	getc(stdin);

	return end;
}//end main()

//end main.cpp

//	FITZROY EDINBOROUGH	//
//	408004140			//
//	Cre 07.03.09			//
//	Mod 16.03.09			//
