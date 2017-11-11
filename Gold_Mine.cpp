#include <iostream>
#include "Gold_Mine.h"
#include "Game_Object.h"

using namespace std;

class Gold_Mine : public Game_Object
{
private:
	char diplay_code;
	int id_num;
	char state;
	double amount;
	Cart_Point location;

public:
	Gold_Mine()
	{
		diplay_code = 'G';
		id_num = 0;
		state = 'f';
		amount = 100;
		location = Cart_Point();

		cout << "Gold_Mine default constructed" << endl;
	}

	Gold_Mine(int inputId, Cart_Point inputLoc)
	{
		this id_num -> inputId;
		this location -> inputLoc;
		diplay_code = 'G';
		state = 'f';
		amount = 100;

		cout << "Gold_Mine constructed" << endl;
	}

	Cart_Point get_location()
	{
		return location;
	}

	int get_id()
	{
		return id_num;
	}

	bool is_empty()
	{
		if(amount == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	double dig_gold(double amount_to_dig = 35.0)
	{
		if(amount >= amount_to_dig)
		{
			amount = amount - amount_to_dig;
			return amount;
		}
		else
		{
			return amount;
			amount = 0;
		}
	}

	bool update()
	{
		if (state = 'e')
		{
			return false;
		}

		else if (amount = 0)
		{
			state = 'e';
			display_code = 'g'
			cout << "Gold_Mine (" << id_num << ") has been depleted" << endl;
			return true;
		}
	}

	void show_status()
	{
		cout << "Gold Mine status: " << display_code << id_num << " at location " << location << " Contains " << amount << "." << endl;
	}
}