#include <iostream>
#include "Gold_Mine.h"

using namespace std;

//create gold mine constructor with initial variable values
Gold_Mine::Gold_Mine() : Game_Object(display_code, id_num)
{
	id_num = 0;
	display_code = 'G';
	location = Cart_Point();
	amount = 100;
	state = 'f';
	cout << "Gold_Mine default constructed." << endl;
}

//create a constructor that takes in an id number and location
Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc) : Game_Object(display_code, inputId, inputLoc)
{
	display_code = 'G';
	amount = 100;
	state = 'f';
	this -> id_num = inputId;
	this -> location = inputLoc;
	cout << "Gold_Mine constructed." << endl;
}

//gold mine destructor
Gold_Mine::~Gold_Mine()
{
	cout << "Gold_Mine destructed." << endl;
}


//gets location of a gold mine
Cart_Point Gold_Mine::get_location()
{
	return location;
}

//gets the id number of a gold mine
int Gold_Mine::get_id()
{
	return id_num;
}

//function checks to see if the gold mine is empty by the amount of gold
bool Gold_Mine::is_empty()
{
	if(amount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//function to dig gold
double Gold_Mine::dig_gold(double amount_to_dig)
{
	if(amount >= amount_to_dig)
	{
		amount = amount - amount_to_dig;  //if amout is more than the default amount you subtract the amount of gold in the gold mine by the default
		return amount_to_dig; //how much gold was dug
	}
	else
	{
		double newamount = amount; //second variable to return the amount of gold dug and set amount to zero
		amount = 0.0; //set amount to zero
		return newamount; 
	}
}

bool Gold_Mine::update()
{
	if (amount == 0 && state != 'e') //by checking for both condition update doesnt continually return true if the gold mine isempty
	{
		state = 'e';
		display_code = 'g';
		cout << "Gold_Mine " << get_id() << " has been depleted" << endl;
		return true;
	}
	else
	{
		return false; 
	}
}

void Gold_Mine::show_status()
{
	cout << "Gold Mine status: "; 
	Game_Object::show_status();	//goldmine status just adds necessary parts to show status
	cout << " contains " << amount << "." << endl;
}
