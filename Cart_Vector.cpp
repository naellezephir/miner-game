#include <iostream>
#include "Cart_Vector.h"

using namespace std;

//Default construction initializes both to 0
Cart_Vector::Cart_Vector()
{
	x = 0.0;
	y = 0.0;
}

//Constructor for input values
Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
}

Cart_Vector operator* (Cart_Vector &v1, double d)
{
	Cart_Vector new_vector;
	new_vector.x = v1.x*d;
	new_vector.y = v1.y*d;
	return new_vector;
}

Cart_Vector operator/ (Cart_Vector &v1, double d)
{
	Cart_Vector new_vector;
	if (d == 0)
	{
		new_vector.x = v1.x;
		new_vector.y = v1.y;
	}
	else
	{
		new_vector.x = v1.x / d;
		new_vector.y = v1.y / d;
	}
	return new_vector;
}

ostream &operator<< (ostream &output, Cart_Vector &v1)
{
	output<<"<"<<v1.x<<", "<<v1.y<<">";
	return output;
}
