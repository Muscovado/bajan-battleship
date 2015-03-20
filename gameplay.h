//gamePlay.h

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

#include "shouter.h"
#include "PlayerClass.h"
#include "ShipClass.h"
#include "gameBoardClass.h"
#include "createPlayer.h";	//creates and returns a player object
#include "create_gameBoard.h";	//simply creates and returns the gameboard for each player
#include "createShip.h";	/*used for all ten ships, receives a gameboard object to place 
				the ship on, a description of the ship, returns a ship object	*/

int gamePlay()
{	//declare variables
	string carrier;
	string battleship;
	string cruiser;
	string submarine;
	string destroyer;
	int k;	//location of ship
	
	//this we do for player 1
	//create a player object
	Player player1 = createPlayer(1);
	getc(stdin);
	//create a gameBoard object
	gameBoard GBoard1 = create_gameBoard();
	//create shadow gameBoard object
	gameBoard GBoard11 = create_gameBoard();
	//create several ships
	//create a carrier
	cout << "Enter Carrier location: ";
	cin >> k;
	getc(stdin);
	Ship carrier1 = createShip(carrier, k+1, 5);
	//place ship in gameBoard
	GBoard11.set_ship(k+1, 5);
	//create a battleship
	cout << "Enter Battleship location: ";
	cin >> k;
	getc(stdin);
	Ship battleship1 = createShip(battleship, k+1, 4);
	//place ship in gameBoard
	GBoard11.set_ship(k+1, 4);
	//create a cruiser
	cout << "Enter Cruiser location: ";
	cin >> k;
	getc(stdin);
	Ship cruiser1 = createShip(cruiser, k+1, 2);
	//place ship in gameBoard
	GBoard11.set_ship(k+1, 2);
	//create a submarine
	cout << "Enter Submarine location: ";
	cin >> k;
	getc(stdin);
	Ship submarine1 = createShip(submarine, k+1, 3);
	//place ship in gameBoard
	GBoard11.set_ship(k+1, 3);
	//create a destroyer
	cout << "Enter Destroyer location: ";
	cin >> k;
	getc(stdin);
	Ship destroyer1 = createShip(destroyer, k+1, 3);
	//place ship in gameBoard
	GBoard11.set_ship(k+1, 3);

	//print player's gameBoard
	GBoard1.print_gameBoard();
	//create hit_array()
	GBoard11.create_hitArray();	/*now we have an array with the index 
					  * locations of all player2's ships */
	//GBoard11.printHit_array();

	getc(stdin);
	shouter();

	//this we do for player 2
	//create a player object
	Player player2 = createPlayer(2);
	getc(stdin);
	//create a gameBoard object
	gameBoard GBoard2 = create_gameBoard();
	//create shadow gameBoard object
	gameBoard GBoard22 = create_gameBoard();
	//create several ships
	//create a carrier
	cout << "Enter Carrier location: ";
	cin >> k;
	getc(stdin);
	Ship carrier2 = createShip(carrier, k+1, 5);
	//place ship in gameBoard
	GBoard22.set_ship(k+1, 5);
	//create a battleship
	cout << "Enter Battleship location: ";
	cin >> k;
	getc(stdin);
	Ship battleship2 = createShip(battleship, k+1, 4);
	//place ship in gameBoard
	GBoard22.set_ship(k+1, 4);
	//create a cruiser
	cout << "Enter Cruiser location: ";
	cin >> k;
	getc(stdin);
	Ship cruiser2 = createShip(cruiser, k+1, 2);
	//place ship in gameBoard
	GBoard22.set_ship(k+1, 2);
	//create a submarine
	cout << "Enter Submarine location: ";
	cin >> k;
	getc(stdin);
	Ship submarine2 = createShip(submarine, k+1, 3);
	//place ship in gameBoard
	GBoard22.set_ship(k+1, 3);
		//create a destroyer
	cout << "Enter Destroyer location: ";
	cin >> k;
	getc(stdin);
	Ship destroyer2 = createShip(destroyer, k+1, 3);
		//place ship in gameBoard
	GBoard22.set_ship(k+1, 3);

	//print player's gameBoard
	GBoard2.print_gameBoard();
	//create hit_array()
	GBoard22.create_hitArray();/*now we have an array with the index 
					  * locations of all player2's ships */
	//GBoard22.printHit_array();

	getc(stdin);

	//let the games begin
	shouter();
    	int hit = 1;
	int target = 0;
	int attempt1 = 0, attempt2 = 0;
	int strike1 = 0, strike2 = 0;
	float rate = 0;
	//the idea is to loop (game loop) until all of either player's positions are hit
	while((player1.get_EnShipSunk() < 5)&&(player2.get_EnShipSunk() < 5))
	{	/*once a position is hit, it's changed to X on the original gameBoard, 
		i.e, gameBoard1 or gameBoard2
		players operate on the other's gameBoard
		inside the game loop(see above), are two loops one for each player,
		 that cycle until the particular player misses */

		//player1's "play loop"
		cout << "Player One" << endl;
		while((hit == 1)&&(player1.get_EnShipSunk() < 5))
		{	//get strike coordinate from player
			cout << "Enter target coordinate: ";
			cin >> target;
			getc(stdin);
			attempt1 += 1;
			
			if(GBoard22.searchHit_array(target) == 1)
			{	//remove target location from possible hits
				//check which ship was hit
				if(carrier2.isShipHit(target) == 1)
				{	hit = 1;
					strike1 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard2.set_boardMember(target, 'X');
					carrier2.set_hits(1);	
					cout 	<< "That did massive damage to the enemy's aircraft carrier." 
						<< endl;
					getc(stdin);
					//check if the carrier was sunk
					player1.set_EnShipSunk(carrier2.isShipSunk(1));	}//end if
				if(battleship2.isShipHit(target) == 1)
				{	hit = 1;
					strike1 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard2.set_boardMember(target, 'X');
					battleship2.set_hits(1);
					cout << "Major damage to the enemy's battleship." << endl;
					getc(stdin);
					player1.set_EnShipSunk(battleship2.isShipSunk(2));	
				}//end if
				if(cruiser2.isShipHit(target) == 1)
				{	hit = 1;
					strike1 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard2.set_boardMember(target, 'X');
					cruiser2.set_hits(1);	
					cout << "That enemy cruiser's going down!!!" << endl;
					getc(stdin);
					player1.set_EnShipSunk(cruiser2.isShipSunk(3));		
				}//end if
				if(submarine2.isShipHit(target) == 1)
				{	hit = 1;
					strike1 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard2.set_boardMember(target, 'X');
					submarine2.set_hits(1);	
					cout << "That enemy sub took a hit!!!" << endl;
					getc(stdin);
					player1.set_EnShipSunk(submarine2.isShipSunk(4));	
				}//end if
				if(destroyer2.isShipHit(target) == 1)
				{	hit = 1;
					strike1 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard2.set_boardMember(target, 'X');
					destroyer2.set_hits(1);	
					cout << "The enemy destroyer will soon be on the ocean floor." << endl;
					getc(stdin);
					player1.set_EnShipSunk(destroyer2.isShipSunk(5));	
				}//end if

				//give player another turn
				cout << endl << "Press ENTER to try another target." << endl;
				getc(stdin);
			}
			else if(GBoard22.searchHit_array(target) == 2)
			{	hit = 0;
				cout << "\aYou have hit that position before !" << endl; }
			else if(GBoard22.searchHit_array(target) == 0)
			{	hit = 0;
				cout << endl << "MISS! Seems you're only a threat to the fishes." << endl;
				//populate gameboard with misses
				GBoard2.set_boardMember(target, 'O');
			}//end if-else

			rate = (float)strike1/attempt1;
			player1.set_score(strike1*rate*100);
		}//end while
		//end player1's turn

		//print player1's info
		GBoard2.print_gameBoard();
		cout << "You have sunk " << player1.get_EnShipSunk() << " enemy ships." << endl;
		getc(stdin);
		


		//start player2's turn
		hit = 1;

		cout << "Player Two" << endl;
		while((hit == 1)&&(player2.get_EnShipSunk() < 5))
		{	//get strike coordinate from player
			cout << "Enter target coordinate: ";
			cin >> target;
			getc(stdin);
			attempt2 += 1;
			
			if(GBoard11.searchHit_array(target) == 1)
			{	//check which ship was hit
				if(carrier1.isShipHit(target) == 1)
				{	hit = 1;
					strike2 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard1.set_boardMember(target, 'X');
					carrier1.set_hits(1);	
					cout 	<< "That did massive damage to the enemy's aircraft carrier." 
						<< endl;
					getc(stdin);
					player2.set_EnShipSunk(carrier1.isShipSunk(1));	}//end if
				if(battleship1.isShipHit(target) == 1)
				{	hit = 1;
					strike2 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard1.set_boardMember(target, 'X');battleship1.set_hits(1);
					cout << "Major damage to the enemy's battleship." << endl;
					getc(stdin);
					player2.set_EnShipSunk(battleship1.isShipSunk(2));	
				}//end if
				if(cruiser1.isShipHit(target) == 1)
				{	hit = 1;
					strike2 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard1.set_boardMember(target, 'X');
					cruiser1.set_hits(1);	
					cout << "That enemy cruiser's going down!!!" << endl;
					getc(stdin);
					player2.set_EnShipSunk(cruiser1.isShipSunk(3));		
				}//end if
				if(submarine1.isShipHit(target) == 1)
				{	hit = 1;
					strike2 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard1.set_boardMember(target, 'X');
					submarine1.set_hits(1);	
					cout << "That enemy sub took a hit!!!" << endl;
					getc(stdin);
					player2.set_EnShipSunk(submarine1.isShipSunk(4));	
				}//end if
				if(destroyer1.isShipHit(target) == 1)
				{	hit = 1;
					strike2 += 1;
					cout << endl << "HIT! HIT! HIT!" << endl;
					//populate gameboard with hits
					GBoard1.set_boardMember(target, 'X');
					destroyer1.set_hits(1);	
					cout << "The enemy destroyer will soon be on the ocean floor." << endl;
					getc(stdin);
					player2.set_EnShipSunk(destroyer1.isShipSunk(5));	
				}//end if

				//give player another turn
				cout << endl << "Press ENTER to try another target." << endl;
				getc(stdin);
			}
			else if(GBoard11.searchHit_array(target) == 2)
			{	hit = 0;
				cout << "\aYou have hit that position before !" << endl; }
			else if(GBoard11.searchHit_array(target) == 0)
			{	hit = 0;
				cout << endl << "MISS! Seems you're only a threat to the fishes." << endl;
				//populate gameboard with misses
				GBoard1.set_boardMember(target, 'O');
			}//end if-else

			rate = (float)strike2/attempt2;
			player2.set_score(strike2*rate*100);
		}//end while
		//end player2's turn
			
		GBoard1.print_gameBoard();
		cout << "You have sunk " << player2.get_EnShipSunk() << " enemy ships." << endl;
		getc(stdin);
		hit = 1;
	}//end while
	//took a while to figure out how to do that

	//determine winner
	if(player1.get_EnShipSunk() == 5)
	{	//player1 won
		cout << "CONGRATULATIONS " << player1.get_name() << " !!!" << endl
			 << "You have sunk ALL the enemy vessels." << endl;
		getc(stdin);
	}else
	{	//player2 won
		cout << "CONGRATULATIONS " << player2.get_name() << " !!!" << endl
			 << "You have sunk ALL the enemy vessels." << endl;
		getc(stdin);
	}
	//end game
	return 0;
}//end gamePlay()

//end gamePlay.h

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 15.03.09				//
//	Mod 16.03.09				//
