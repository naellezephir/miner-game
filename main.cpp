#include <iostream>
#include "View.h"
#include "Game_Command.h"

using namespace std;

int main()
{
	cout<<"EC327: Introduction to Software Engineering"<<endl;
	cout<<"Fall 2016"<<endl;
	cout<<"Programming Assignment 3"<<endl;

	Model * model = new Model();
	View view;
	model->show_status();
	model->display(view);

	char command = 'z';
	do
	{
		game_command(model, command, view);
	} while(command != 'q');
	return 0;
}
