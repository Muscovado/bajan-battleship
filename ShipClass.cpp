//ShipClass.cpp

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "ShipClass.h"

//constructor function to initialise values of Ship objects
Ship::Ship(string vessel_type, int locale, int length)
{	set_vesselType(vessel_type);
	set_location(locale);
	set_size(length);
	set_locationArray(locale, length);
}
//set functions for each data member
void Ship::set_vesselType(string vesselType)
{	vesselDescription = vesselType;	}

void Ship::set_location(int location)
{	offsetLocation = location;	}

void Ship::set_size(int shipLength)
{	size = shipLength;	}

void Ship::set_hits(int strikes)
{	hits += strikes;	}
//get functions for each data member
string Ship::get_vesselType(void)
{	return vesselDescription;	}
int Ship::get_location(void)
{	return offsetLocation;	}
int Ship::get_size(void)
{	return size;	}
int Ship::get_hits(void)
{	return hits;	}
//other functions
int Ship::isShipHit(int k)
{	//searches location_array for target coordinate, and returns 1 if found
	for(int i = 0; i < 5; i++)
	{	if(location_array[i] == k)
		{	location_array[i] = -1;//remove location from possible hit points 
			return 1;	}
	}
	return 0;
}

int Ship::isShipSunk(int q)
{	if((q == 1)&&(get_hits() == 5))//carrier was sunk
	{	cout << "No more air attacks. That carrier is SUNK !!!" << endl;
		return 1;	}
	if((q == 2)&&(get_hits() == 4))//battleship was sunk
	{	cout << "No more heavy artillery. That battleship is SUNK !!!" << endl;	
		return 1;	}
	if((q == 3)&&(get_hits() == 2))//cruiser was sunk
	{	cout << "No more light artillery. That cruiser is SUNK !!!" << endl;	
		return 1;	}
	if((q == 4)&&(get_hits() == 3))//submarine was sunk
	{	cout << "No more torpedo attacks. That submarine is SUNK !!!" << endl;
		return 1;	}
	if((q == 5)&&(get_hits() == 3))//destroyer was sunk
	{	cout << "No more missile attacks. That destroyer is SUNK !!!" << endl;	
		return 1;	}
}

void Ship::set_locationArray(int bow, int length)
{	int j = bow;
	for(int i = 0; i < length; i++)
	{	location_array[i] = j;	
		j++;	}
	if(length < 5)
	{	while(i < 5)
		{	location_array[i] = -1;
			i++;
		}
	}
}

//end ShipClass.cpp

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 07.03.09				//
//	Mod 15.03.09				// 
