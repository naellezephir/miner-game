#ifndef TOWN_HALL_H
#define TOWN_HALL_H
#include "Cart_Point.h"
#include "Game_Object.h"

class Town_Hall : public Game_Object
{
	private:
		int id_num;
		//char state;
		double amount;
		Cart_Point location;

	public:
		Cart_Point get_location();
		int get_id();
		void deposit_gold(double deposite_amount);
		bool update();
		void show_status();
		Town_Hall();
		Town_Hall(int inputId, Cart_Point inputLoc);
		~Town_Hall();
};

#endif
