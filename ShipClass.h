//ShipClass.h

#include<string>
using std::string;

class Ship
{	//data members
	private:
		string vesselDescription;
		int offsetLocation;
		int size;
		int hits;
		int location_array[5];

	//member functions
	public:
		//constructor function to initialise values of Ship objects
		Ship(string, int, int);
		//set functions for each data member
		void set_vesselType(string);
		void set_location(int);
		void set_size(int);
		void set_hits(int);
		//get functions for each data member
		string get_vesselType(void);
		int get_location(void);
		int get_size(void);
		int get_hits(void);
		//other functions
		int isShipHit(int);
		int isShipSunk(int);
		void set_locationArray(int, int);
};//end Ship class
//end ShipClass.h

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 07.03.09				//
//	Mod 15.03.09				//
