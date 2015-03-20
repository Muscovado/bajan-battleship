//PlayerClass.h

#include<string>
using std::string;

class Player
{	//data members
	private:
		string name;
		float score;
		float bestScore;
		int numOfOppShipsSunk;

	//member functions
	public:
		//constructor function to initialise values of Player objects
		Player(string);
		//set functions for each data member
		void set_name(string);
		void set_score(float);
		void set_bestScore(float);
		void set_EnShipSunk(int);
		//get functions for each data member
		string get_name(void);
		float get_score(void);
		float get_bestScore(void);
		int get_EnShipSunk(void);
};//end Player class
//end PlayerClass.h

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 07.03.09				//
//	Mod 08.03.09				//
