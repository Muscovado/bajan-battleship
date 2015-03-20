//gameBoardClass.cpp

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "gameBoardClass.h"

//constructor function
gameBoard::gameBoard(int i)
{	for(i = 1; i < 71; i++)
	{	set_boardMember(i, '-');	}
}//end gameBoard()
//end constructor function

void gameBoard::printHit_array()
{	for(int i =0; i < 17; i++)
	{	cout << hit_array[i] << " " ;	}
	cout << "   " << endl;
}
//set function
void gameBoard::set_ship(int locale, int length)
{	char chID = 'O';
	if(check(locale, length) == 1)
	{	if((locale > 0)&&((locale + length) < 71))
		{	for(int i = locale; i < (locale + length); i++)
			{	set_boardMember(i, chID);	}
		}
		else
		{	while((locale < 0)||((locale + length) >= 71))
			{	cout << endl << "Enter a location between 0 and 65: ";
				cin >> locale;
				set_ship(locale, length);
			}
		}
	}
	else
	{	cout << endl << "Enter another location for your ship." << endl;
		cin >> locale;
		set_ship(locale, length);
	}
}

//receives an integer pointing to location of board member to be changed
int gameBoard::set_boardMember(int i, char ch)
{	if((i > 0)&&(i < 71))
	{	board[i] = ch;	
		return 1;//successful allocation
	}else
	{	return 0;	}//failure to allocate
}//end set_boardMember()

//get function
char gameBoard::get_boardMember(int i)
{	if((i > 0)&&(i < 71))
	{	return board[i];	}
	else
	{	return -1;	}
}//end get_boardMember()

//messenger function
void gameBoard::print_gameBoard(void)
{	for(int i = 0; i < 71; i++)
	{	cout << get_boardMember(i);
	}
	cout << endl;
}//end print_gameBoard()

//other functions
void gameBoard::create_hitArray()
{	int j = 0;
	for(int i = 0; i < 71; i++)
	{	if((get_boardMember(i)) == 'O')
		{	//store that occupied position in array
			hit_array[j] = i;
			j++;
		}
	}
}//end create_hitArray()

int gameBoard::searchMiss_array(int k)
{	for(int i = 0; i <= 16; i++)
	{	if(miss_array[i] == k)//position was hit before
		{	return 2;	}
	}
	return 1;
}
int gameBoard::searchHit_array(int k)
{	if(searchMiss_array(k) == 2)
	{	return 2;	}//position was hit before
	for(int i = 0; i <= 16; i++)
	{	if(hit_array[i] == k)
		{	miss_array[i] = k;//add location to array of former hit points
			hit_array[i] = -1;//remove location from possible hit points 
			return 1;
		}
	}
	return 0;
}

int gameBoard::check(int locale, int length)
{	for(int j = locale; j < (locale + length); j++)
	{	if(get_boardMember(j) == 'O')
		{	return 0;	}//cannot set ship in location
	}
	return 1;//can set ship in this location
}
//end gameBoard class
//end gameBoardClass.cpp

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 07.03.09				//
//	Mod 16.03.09				//
