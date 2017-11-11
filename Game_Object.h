#ifndef "GAME_OBJECT_H"
#define 
#include "Cart_Point.h"

class Game_Object
{
	private:
		int id_num;

	protected:
		Cart_Point location;
		char display_code;
		char state;

	public:
		Game_Object(char in_code, int in_id);
		Game_Object(char in_code, int in_id, Cart_Point in_loc);

		Cart_Point get_location();

		int get_id();

		void show_status();
}