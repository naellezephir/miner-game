#include <iostream>
#include "Town_Hall.h"

using namespace std;

//default town hall constructor
Town_Hall::Town_Hall() : Game_Object('t', 1)
{
	display_code = 't';
	id_num = 1;
	state = 'o';
	amount = 0;
	Cart_Point location = Cart_Point();

	cout << "Town_Hall default constructed." << endl;
}

//constructor that takes in id input and a location
Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc) : Game_Object(display_code, id_num, location)
{
	this -> id_num = inputId;
	this -> location = inputLoc; 
	display_code = 't';
	state = 'o';
	amount = 0;

	cout << "Town_Hall constructed." << endl;
}

//townhall destructor
Town_Hall::~Town_Hall()
{
	cout << "Town_Hall destructed." << endl;
}

//returns location of the town hall
Cart_Point Town_Hall::get_location()
{
	return location;
}

//returns id of town hall
int Town_Hall::get_id()
{
	return id_num;
}

//function to deposit gold to town hall
void Town_Hall::deposit_gold(double deposit_amount)
{
	amount = amount + deposit_amount; //adds amount depositied to the amount of gold in town hall
}

//updates townhall
bool Town_Hall::update()
{
	if (state == 'u') //if the state is u doest continually tell you its been updated
	{
		return false;
	}

	else if(amount >= 50) //returns true if the amount in town hall if 50 or more
	{
		state = 'u'; //changes state
		display_code = 'T';
		cout << display_code << id_num << " has been upgraded." << endl;
		return true;
	}
}

void Town_Hall::show_status() //shows status lol
{
	cout << "Town Hall status: ";
	Game_Object::show_status(); //calls on game object show status becuase it is also an object
	cout << " contains " << amount << " of gold. ";
		
	if (state == 'u') //different endings depending on its state
	{
		cout << "Upgraded." << endl;
	}

	else
	{
		cout << "Not yet upgraded." << endl;
	}
}
