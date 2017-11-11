#ifndef CART_VECTOR_H
#define CART_VECTOR_H

class Cart_Vector{
public: 
	double x;
	double y;
	Cart_Vector();
	Cart_Vector(double, double);
};

#endif

Cart_Vector operator* (Cart_Vector&, double d);
Cart_Vector operator/ (Cart_Vector&, double d);
std::ostream &operator<< (std::ostream&, Cart_Vector&);
