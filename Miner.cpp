#include <iostream>
#include "Miner.h"

using namespace std;

//default miner constructor
Miner::Miner() : Person('M')
{
	amount = 0;
	state = 's'; //initialize variables values
	mine = NULL;
	home = NULL;

	cout << "Miner default constructed." << endl;
}

//miner constructor
Miner::Miner(int in_id, Cart_Point in_loc) : Person('M', in_id, in_loc)
{
	amount = 0;
	state = 's';
	mine = NULL;
	home = NULL;

	cout << "Miner constructed." << endl;
}

//miner destructor
Miner::~Miner()
{
	cout << "Miner destructed." << endl;
}

//update for miner
bool Miner::update()
{
	switch(state) //giant switch statement depending on state, each case causes different chages to different states and outputs a different result
	{
		case 's':
			return false;
			break;

		case 'm':
			if (update_location() == true)
			{
				state = 's'; //changes state
				return true;
				break;
			}
			else
			{
				return false;
				break;
			}

		case 'o':
			if (update_location() == true)
			{
				state = 'g'; //changes state
				return true;
				break;
			}

			else
			{
				return false;
				break;
			}

		case 'g':
			amount = mine -> dig_gold(); //digs gold and adds it to miner amount
			cout << display_code << get_id() << ": Got " << amount << " gold." << endl;
			setup_destination(home -> get_location());  //sets new destination so that miner can move there after
			state = 'i';
			return true;
			break;

		case 'i' :
			if (update_location())
			{
				state = 'd'; //changes state
				return true;
				break;
			}
			else
			{
				return false;
				break;
			}

		case 'd':
			cout << display_code << get_id() << ": Deposit " << amount << " gold." << endl;
			home -> deposit_gold(amount); //adds amount to town hall amount
			amount = 0; //sets it to 0 so miner can get more gold
			if(mine -> is_empty()) //if mines are empty the miner's just chillin
			{
				state = 's'; //change state
				cout << display_code << get_id() << ": More work?" << endl;
				return true;
				break;
			}
			else //if not send the miner back to the mine to get more gold
			{
				state = 'o'; //change state
				setup_destination(mine -> get_location()); //make destination the mine
				cout << display_code << get_id() << ": Going back for more." << endl;
				return true;
				break;
			}
	}
}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome) //start mining function
{
	mine = inputMine;
	home = inputHome;
	setup_destination(mine -> get_location());  //set location to mine so the miner can move there
	state = 'o'; //change state
	cout << "Miner " << get_id() << " mining at Gold_Mine " << mine -> get_id() << " and depositing at Town_Hall " << home -> get_id() << endl;
	cout << display_code << get_id() << ": Yes, my lord." << endl;
}

//returns location of miner
Cart_Point Miner::get_location()
{
	Person::show_status();	
	return location;	
}

//THIS TOOK ME FOREVER TO THINK OF BUT ITS AN EASY FIX idk if this is right but since show status is a vitrual function i just made one for miner and in it calls person status. it adds the amount of gold the miner has to the end of the show status for person when the mine is inbound since amount is a private variable for miner and the show status switch statement is in person the base class. 
void Miner::show_status()
{
	Person::show_status();
	if(state == 'i')
	{
		cout << amount << endl;
	}
}
