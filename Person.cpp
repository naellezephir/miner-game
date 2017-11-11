#include <iostream>
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

class Person : public Game_Object
{
	private:
		double speed;
		Cart_Point destination;
		Cart_Vector delta;

	public:
		Person();
		Person(char in_code)
		{
			speed = 5;
			cout << "Person constructed" << endl;
		}

		Person(char in_code, int in_id, Cart_Point in_loc)
		{
			Game_Object(in_code, in_id, in_loc);
			cout << "Person constructed" << endl;
		}

		void start_moving(Cart_Point dest)
		{
			//Tells person to start moving??
			setup_destination();
			state = 'm';
			cout << "Moving " << id_num << " to " << destination << "." << endl;
			cout << display_code << id_num << ": On my way." << endl;
		}

		void stop()
		{
			state = 's';
			cout << "Stopping " << id_num << "." << endl;
			cout << display_code << id_num << ": All right."
		}

		void show_status()
		{
			Game_Object::show_status();
			cout << "Person status: " << display_code << id_num << " at " << location << " moving at a speed of " << speed << " towards" << destination << " at each step of " << delta << endl;
		}

	protected:
		bool update_location()
		{
			location = location + delta;

			if (location == destination)
			{
				cout << display_code << id_num << ": I'm there!" << endl;
				return true;
			}

			else
			{
				cout << display_code << id_num << ": step..." << endl;
				return false;
			}
		}

		void setup_destination(Cart_Point dest)
		{
			delta = (destination - location) * (speed / cart_distance(destination, location));
		}
}