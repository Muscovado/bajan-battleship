//gameBoardClass.h

class gameBoard
{	//data members
	private:
		char board[71];
		int hit_array[17];
		int miss_array[17];
	public:
		//constructor function
		gameBoard(int);
		//messenger function
		void printHit_array();
		//set function
		void set_ship(int, int);//receives ship's offset location and ship length, sets Os representing ship
		int set_boardMember(int, char);//gets integer pointing to location of board member to be changed
		//get function
		char get_boardMember(int);
		//messenger function
		void print_gameBoard(void);
		//other functions
		void create_hitArray();
		int searchHit_array(int);
		int searchMiss_array(int);
		int check(int, int);
};//end gameBoard class
//end gameBoardClass.h

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 07.03.09				//
//	Mod 16.03.09				//
