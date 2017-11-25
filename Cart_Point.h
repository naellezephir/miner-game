#ifndef CART_POINT_H
#define CART_POINT_H
#include <iostream>
#include "Cart_Vector.h"
class Cart_Point
{
public:
	double x; 
	double y;
	Cart_Point();
	Cart_Point(double , double );
};


std::ostream &operator<<(std::ostream& answer,const Cart_Point& p);
Cart_Point operator+ (const Cart_Point& p1, const Cart_Vector& v1);
Cart_Vector operator- (const Cart_Point& p1, const Cart_Point& p2);

double cart_distance(Cart_Point, Cart_Point);


#endif
