#include <iostream>
#include "Person.h"
#include <math.h>

using namespace std;

//default perosn constructor
Person::Person(char in_code) : Game_Object(in_code, 0)
{
	speed = 5;
	cout << "Person default constructed." << endl;
}

//person constructor that takes in display code, id num, and location
Person::Person(char in_code, int in_id, Cart_Point in_loc) : Game_Object(in_code, in_id, in_loc)
{
	speed = 5;
	cout << "Person constructed." << endl;
}

//person destructor
Person::~Person()
{
	cout << "Person destructed." << endl;
}

//starts moving person
void Person::start_moving(Cart_Point dest)
{
	setup_destination(dest); //sets destination to the initial destination in the argument
	state = 'm'; //changes state of person object
	cout << "Moving " << display_code << get_id() << " to " << dest << "." << endl;
	if(location.x == dest.x && location.y == dest.y) //if the person object is at the destination output special statment
	{
		cout << "I'm already there. see?" << endl;
		state = 's'; //changes state back to stopped
	}
	else //if not set it on its way (woow im rlly corny my b)
	{
		cout << display_code << get_id() << ": On my way." << endl;
	}
}

//stops person from moving
void Person::stop()
{
	state = 's'; //changes state of person object
	cout << display_code << get_id() << ": Stopped." << endl;
	//cout << display_code << get_id() << ": All right." << endl;
}

//WHOO show a person objects status
void Person::show_status()
{
	cout << "Miner Status: ";
	Game_Object::show_status(); //calls upon game object status since person is a game obeject 
	switch(state) //switch statement for different cases depending on the state
	{
		case 's':
			cout << " is stopped." << endl;
			break;

		case 'm':
			
			cout << " moving at speed " << speed << " to " << destination << " at each step of " << delta << endl;
			break;

		case 'o':
			cout << " moving at speed " << speed << " to " << destination << " at each step of " << delta << " is outbound to a mine." << endl;
			break;

		case 'g':
			cout << " is getting gold from mine." << endl;
			break;

		case 'i' :
			cout << " moving at speed " << speed << " to " << destination << " at each step of " << delta << " is inbound to home with load: "; //NEEDS LOAD RIP -> fixed it stay tuned for my ~revoluntionary~ soluntion (not rlly but im pretty excited about it)
			break;

		case 'd':
			cout << " is depositing gold." << endl;
			break;
	}

	
}

//update location of person
bool Person::update_location()
{
	//cout << "DEBUG DELTA: "<<delta<<endl;
	//cout << "DEBUG MOVEX: "<<(destination.x - location.x) << endl;
	//cout << "DEBUG MOVEY: "<<(destination.y -location.y)<<endl;

	if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)) // if within a "step" of destination return true
	{
		location = destination;
		cout << display_code << get_id() << ": I'm there!" << endl;
		return true;
	}

	else
	{
		location = location + delta; //if not change location to new location
		cout << display_code << get_id() << ": step..." << endl;
		return false; //return false cause its not there
	}
}

void Person::setup_destination(Cart_Point dest) //set destinationo
{
	destination = dest; //saves the destination that was inputed
	Cart_Vector v1 = destination - location; //creates a cartvector by subtracting destination and location
	delta = v1 * (speed / cart_distance(destination, location)); //formula for delta aka the size of the "steps"
}

void Person::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome) //cause pure virtual fucntion
{
	cout << "Sorry, I can't work a mine." << endl;
}
