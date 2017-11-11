#include <iostream>
#include "Town_Hall.h"
#include "Cart_Point.h"

using namespace std;

class Town_Hall : public Game_Object
{
private:
	char display_code;
	int id_num;
	char state;
	double amount;
	Cart_Point location;

public:
	Town_Hall()
	{
		display_code = 't';
		id_num = 0;
		state = 'o';
		amount = 0;
		Cart_Point location = Cart_Point();

		cout << "Town_Hall default constructed" << endl;
	}

	Town_Hall(int inputId, Cart_Point inputLoc)
	{
		this -> id_num = inputId;
		this -> location = inputLoc;
		display_code = 't';
		state = 'o';
		amount = 0;

		cout << "Town_Hall constructed" << endl;
	}

	Cart_Point get_location()
	{
		return location;
	}

	int get_id()
	{
		return id_num;
	}

	void deposit_gold(double deposit_amount)
	{
		amount = amount + deposit_amount;
	}

	bool update()
	{
		if (state == 'u')
		{
			return false;
		}

		else if(amount >= 50)
		{
			state = 'u';
			display_code = 'T';
			cout << "Town_Hall (" << id_num << ") has been upgraded." << endl;
			return true;
		}
	}

	void show_status()
	{
		cout << "Town Hall status: " << display_code << id_num << " at " << location << " constains " << amount << " of gold. " <<;

		if (state == 'u')
		{
			cout << "Upgraded." << endl;
		}

		else
		{
			cout << "Not yet upgraded." << endl;
		}
	}

}