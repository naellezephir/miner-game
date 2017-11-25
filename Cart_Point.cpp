#include "Cart_Point.h"
#include <cmath>
#include <iostream>

using namespace std;

//constructors
//default cart_point constructor
Cart_Point::Cart_Point() {
	this->x = 0;
	this->y = 0;
}

//constructor that takes in both an x and y input
Cart_Point::Cart_Point(double inputx, double inputy) {
	this->x = inputx;
	this->y = inputy;
}

//overloads the cout opperator to return cartpoints in a specific way
ostream& operator<<(ostream& answer, const Cart_Point &p1)
{
	answer << "(" << p1.x << ", " << p1.y << ")";
	return answer;
}
	
//gives functionality of adding cartpoints	
Cart_Point operator+(const Cart_Point &p1, const Cart_Vector &v1)
{
	double x = p1.x + v1.x;
	double y = p1.y + v1.y;
	Cart_Point p(x,y);

	return p;	
}

//gives functionality of subtracting cartpoints and returns a cart vector
Cart_Vector operator-(const Cart_Point &p1, const Cart_Point &p2)
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	Cart_Vector v(x,y);

	return v;	
}

//function to find distance between cart points
double cart_distance(Cart_Point p1, Cart_Point p2)
{
	double tempx = p2.x - p1.x; //find the difference in the x values
	double tempy = p2.y - p1.y; //find difference in y values
	double a = pow(tempx, 2); //square the x value and y value
	double b = pow(tempy, 2);
			
	double distance = sqrt(a + b); //sqrt that its just the formula you gave us

	return distance;
}
