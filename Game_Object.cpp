#include <iostream>
#include "Game_Object.h"

using namespace std;

//base constructor for game object. it takes in id number, a display code, and assigns a default location
Game_Object::Game_Object(char in_code, int in_id)
{
	display_code = in_code;
	id_num = in_id;
	location = Cart_Point();
	
	cout << "Game_Object default constructed." << endl;
}

// game object constructopr that takes in all three variables
Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
	this -> display_code = in_code;
	this -> id_num = in_id;
	this -> location = in_loc;
}

//gold mine destructor
Game_Object::~Game_Object()
{
	cout << "Game_Object destructed." << endl;
}

//gets location of the game object
Cart_Point Game_Object::get_location()
{
	return location;
}

//gets id of the game object
int Game_Object::get_id()
{
	return id_num;
}

//base show status, outputs the objects status
void Game_Object::show_status()
{
	cout << display_code << get_id() << " at location " << get_location();
}

//draws pointer to put on display
void Game_Object::drawself(char* ptr)
{
	if(ptr[0] == '.' && ptr[1] == ' ') //if objects arent overlapped we do one command
	{
		ptr[0] = display_code; //the first part of the display is the display number
		char numberchar = '0' + id_num; //takes the number and turns it into a character
		ptr[1] = numberchar; //second part of display
	}
	else
	{
		ptr[0] = '*'; //if the objects overlap we use a star first so that we dont have like "MT 1" just "*"
		ptr[1] = ' '; // space so theres no number left cause *1 was an error i kept having
	}
 }	
