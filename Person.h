#ifndef PERSON_H
#define PERSON_H
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

class Person : public Game_Object
{
	public:
		Person();
		Person(char in_code);
		Person(char in_code, int in_id, Cart_Point in_loc);
		~Person();
		void start_moving(Cart_Point dest);
		void stop();
		virtual void show_status();
		virtual void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);

	protected:
		bool update_location();
		void setup_destination(Cart_Point dest);

	private:
		double speed;
		Cart_Point destination;
		Cart_Vector delta;
};

#endif
