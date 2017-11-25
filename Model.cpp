#include <iostream>
#include "Model.h"

using namespace std;


//create a default constructor
Model::Model()
{
	tick = 0;
	//creates a person pointer and stores it in the person ptr aray
	person_ptrs[0] = new Miner(1, Cart_Point(5,1));
	object_ptrs[0] = person_ptrs[0]; //have the first object ptr point at the first person ptr
	
	person_ptrs[1] = new Miner(2, Cart_Point(10,1));
	object_ptrs[1] = person_ptrs[1];

	mine_ptrs[0] = new Gold_Mine(1, Cart_Point(1,20)); //same thing for mine
	object_ptrs[2] = mine_ptrs[0];

	mine_ptrs[1] = new Gold_Mine(2, Cart_Point(10,20));
	object_ptrs[3] = mine_ptrs[1];
	
	hall_ptrs[0] = new Town_Hall(); //and town hall
	object_ptrs[4] = hall_ptrs[0];

	num_objects = 5; //set num of ... to fill into future functions
	num_persons = 2;
	num_mines = 2;
	num_halls = 1;

	cout << "Model default constructed." << endl;

}

//make destructor for model
Model::~Model()
{
	for(int i = 0; i < num_objects; i++)  //iterates through object ptr and deletes each, subsequently calling the destructor for each object
	{
		delete object_ptrs[i];
	}
	cout << "Model destructed." << endl;
}

//find person id
Person* Model::get_Person_ptr(int id) //finds person ptr in the array w the same id
{
	for(int i = 0; i < num_persons; i++) //iterates through the person ptr array and gets the id for each person
	{
		if(person_ptrs[i] -> get_id() == id) //if theyre equal return the object person w the person id
		{
			return person_ptrs[i];
		}
	}
	return 0; //if not return 0;
}

//find gold mine id
Gold_Mine* Model::get_Gold_Mine_ptr(int id)
{
	for(int i = 0; i < num_mines; i++) //same thing as person
	{
		if(mine_ptrs[i] -> get_id() == id)
		{
			return mine_ptrs[i];
		}
		
	}
	return 0;
}

//find townhall id
Town_Hall* Model::get_Town_Hall_ptr(int id) //same thing as the other two
{
	for(int i = 0; i < num_halls; i++) //iterates through the hall ptr array
	{
		if(hall_ptrs[i] -> get_id() == id)
		{
			return hall_ptrs[i];
		}
	}
	return 0;
}

//function to update everything in model
bool Model::update()
{
	tick++;
	bool checker = false; //make a bool set to false
	for(int i = 0; i < num_objects; i++) //iterate through object ptr array
	{
		if(object_ptrs[i] -> update())
		{
			checker = true; //if update is true then change boolean to true
		}
	}
	return checker;
}

//fucntion for display
void Model::display(View &view)
{
	view.clear();
	for(int i = 0; i < num_objects; i++) //iterates through object array and plots each object
	{
		view.plot(object_ptrs[i]);
	}
	view.draw();
}

//shows status
void Model::show_status()
{
	cout << "Time: " << tick << endl; //outputs the time
	for(int i = 0; i < num_objects; i++)
	{
		object_ptrs[i] -> show_status();  //iterates through object ptr and shows status for each object
	}
}
