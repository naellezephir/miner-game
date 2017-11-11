/*
 TestCheckPoint1.cpp
 PA3 --- "The Gold Standard: Mining in C++"
 Copyright (c) 2016 Boston University. All rights reserved.
 */

#include <iostream>

#include "Cart_Vector.h"
#include "Cart_Point.h"

using namespace std;

//Students need to build on this
int main()
{
    
    // Testing Cart_Point
    Cart_Point p1 = Cart_Point(0, 0);
    if(p1.x != 0 && p1.y != 0)
    {
        cout << "Cart_Point is not working!" << endl;
        return 1;
    }
    
    Cart_Vector v1 = Cart_Vector(4,-3);
    Cart_Point p2 = p1+v1;
    cout << p2 << endl;
    p2 = p2+v1;
    cout << p2 << endl;
    cout << v1 << endl;
    
    double a = 0.0;
    double b = 3.0;
    //creating Cart_Point objects
    Cart_Point p3 (a,b);
    Cart_Point p4;
    
    //checking behavior of non-member functions of Cart_Point.cpp
    cout<<"Distance: "<< cart_distance(p3,p4)<<endl;
    
    //checking behavior of overloading operators defined in Cart_Point.cpp
    cout<<"p3= "<<p3<<endl;
    
    /* your code here: test '<<', '-', '+' overloaded operators */
   
    
    
    
    
    //creating Cart_Vector objects
    Cart_Vector v2(5.0, 10.0);
    Cart_Vector v3(15.0, 20.0);
    
    
    /*your code here: test '<<', '*','/' overloaded operators */
    
    
    
    
    
    //Add more tests...
    //YOU NEED TO CONVINCE YOURSELF THAT EVERYTHING WORKS AS EXPECTED
    //Make sure to try corner cases, negative values, v1/0, etc.
    
    // all tests passed!
    cout << "Checkpoint1 passed!" << endl;
    return 0;
}