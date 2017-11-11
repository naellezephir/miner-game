#include <iostream>
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

Cart_Point::Cart_Point()
{
	x = 0.0;
	y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2)
{
	double dist = sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
	return dist;
}

ostream &operator<< (ostream &output, Cart_Point &p1)
{
	output<<"("<<p1.x<<", "<<p1.y<<")"<<endl;
	return output;
}

Cart_Point operator+ (Cart_Point &p, Cart_Vector &v) 
{
	
	double x = p.x + v.x;
	double y = p.y + v.y;
	Cart_Point new_point(x,y);
	return new_point;
}

Cart_Vector operator- (Cart_Point &p1, Cart_Point &p2)
{
	Cart_Vector new_vector;
	new_vector.x = p1.x - p2.x;
	new_vector.y = p1.y - p2.y;
	return new_vector;
}
