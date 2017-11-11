#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Game_Object
{
	private:
		int id_num;

	protected:
		Cart_Point location;
		char display_code;
		char state;
		
	public:
		Game_Object(char in_code, int in_id)
		{
			this -> display_code = in_code;
			this -> id_num = in_id;
			this -> location = Cart_Point();
			
			cout << "Game_Object default constructed" << endl;
		}
		Game_Object(char in_code, int in_id, Cart_Point in_loc)
		{
			this -> display_code = in_code;
			this -> id_num = in_id;
			this -> location = in_loc;
		}

		Cart_Point get_location()
		{
			return location;
		}

		int get_id()
		{
			return id_num;
		}

		void show_status()
		{
			cout << display_code << "with ID " << id_num << " at location " << location << endl;
		}
}