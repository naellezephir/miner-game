#include <iostream>
#include "Game_Command.h"
#include "Model.h"
#include "View.h"

using namespace std;

//make a function to call in main to start game commands
void game_command(Model* model1, char &command, View& view)
{
	cout << "Enter command: ";
	cin >> command;
	switch(command)  //switch statment to take commands and return the proper funtion 
	{
		case 'm' :
			do_move_command(model1, view);
			break;

		case 'w' :
			do_work_command(model1, view);
			break;

		case 's' :
			do_stop_command(model1, view);
			break;

		case 'g' :
			do_go_command(model1, view);
			break;

		case 'r' :
			do_run_command(model1, view);
			break;

		case 'q' :
			do_quit_command(model1);
			break;

		case 'l' :
			do_list_command(model1);
			break;
	}
}

//lists the statuses for all objects
void do_list_command(Model* model)
{
	model -> show_status();
	//model -> display(view);
}

//runs program through time
void do_run_command(Model* model, View& view)
{
	cout << "Advancing to next event." << endl;

	int counter = 0; //make a counter
	while(counter < 5) // a while loop to continuously call update until it returns true or it runs 5 times
	{
		bool checker = model -> update();
		counter++; //increment counter
		if(checker == true)
		{
			break;
		}
	} 
	
	model -> show_status();
	model -> display(view);
}

//runs update only once and moves one time tick
void do_go_command(Model* model, View& view)
{
	cout << "Advancing one tick." << endl;
	model -> update();
	model -> show_status();
	model -> display(view);
}

//moves miners
void do_move_command(Model* model, View& view)
{
	int id; //initialize variables
	int x;
	int y;
	cin >> id >> x >> y; //assigns other inputs to respective variables
	Person* p1 = model -> get_Person_ptr(id); //creates pointer for a person object w/ a specific id
	Cart_Point loc = Cart_Point(x,y); //makes location from inputs

	p1 -> start_moving(loc); //runs move function on person object
	model -> display(view);
}

//starts mining process
void do_work_command(Model* model, View& view)
{
	int id1; //initialize variables
	int id2;
	int id3;
	cin >> id1 >> id2 >> id3; //assign inputs
	Person* p1 = model -> get_Person_ptr(id1); //make a pointer for person object
	Gold_Mine* mine = model -> get_Gold_Mine_ptr(id2);
	Town_Hall* home = model -> get_Town_Hall_ptr(id3);
	
	p1 -> start_mining(mine, home); //runs mining function of person object
	model -> display(view);
}

//stops miners
void do_stop_command(Model* model, View& view)
{
	int id; //initialize varible
	cin >> id;
	Person* p1 = model -> get_Person_ptr(id);

	p1 -> stop(); //runs stop function on person object
	model -> display(view);
}

//quits program
void do_quit_command(Model* model)
{
	cout << "Terminating Program" << endl;
	model -> ~Model(); //call constructor for all game objects
}
