//createPlayer.h

//receives the player's number (1 or 2) 
Player createPlayer(int i)
{	string PName;
	cout 	<< endl
		 << "Player Number " << i 
		 << endl << "Enter Name: " ;
	cin >> PName;
	cout 	<< endl
		 << "Don't let the other player see your ship positions." << endl;
	getc(stdin);
	Player P(PName);//create player object with name supplied by user
	return P;	
}//end createPlayer()

//end createPlayer.h

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 15.03.09				//
