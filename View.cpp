#include <iostream>
#include "View.h"

using namespace std;


View::View()
{
	size = 11;
	scale = 2;
	origin = Cart_Point();
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	ix = (location.x - origin.x) / scale;
	iy = (location.y - origin.y) / scale;
	if(ix <= view_maxsize && iy <= view_maxsize)
	{
		return true;
	}
	else
	{
		cout << "An object is outside the display." << endl;
		return false;
	}
}

void View::clear()
{
	for(int yaxis = 0; yaxis < view_maxsize; yaxis++)
	{
		for(int xaxis = 0; xaxis < view_maxsize; xaxis++)
		{
			grid[yaxis][xaxis][0] = '.';
			grid[yaxis][xaxis][1] = ' ';
		}
	} 
}

void View::plot(Game_Object* ptr)
{
	int ix = 0;
	int iy = 0;
	Cart_Point location = ptr -> get_location();
	bool valid = get_subscripts(ix, iy, location);
	if(valid)
	{
		if(grid[iy][ix][0] == ' ')
		{
			grid[iy][ix][0] = '*';
			grid[iy][ix][1] = ' ';
		}
		else
		{
			ptr -> drawself(grid[iy][ix]);
		}
	}
}

void View::draw()
{
	int counter = view_maxsize;
	for(int yaxis = size - 1; yaxis > -1; yaxis--)
	{
		if(yaxis % 2 == 0)	//if the line number is even for the y axis there are conditions that take place
		{
			cout << counter; //prints out labels on y axis going down every 4
			counter = counter - 4; //
			if (counter < 10)
			{ 
				cout << " ";
				//need to add space when there start to be single digits
			}
		}
		else
		{
			cout << "  "; //if the yaxis line is odd add a space to make the grid spaced out like the sample output, it basically skipps a line
		}
	
		for (int xaxis = 0; xaxis < size; xaxis++)
		{
			cout << grid[yaxis][xaxis][0] << grid[yaxis][xaxis][1]; //draw a grid iterating through our yaxis and xaxis values
			if(xaxis == 10)
			{
				cout << endl;  //if we reach the end of grid finally return a line
			}
		}
	}
	cout << "  0   4   8   12  16  20" << endl; //print out the markers at bottom of grid, im totally guessin ghow many spaces inbetween each number guess its just trial and error
}






