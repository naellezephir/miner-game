#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

using namespace std;

class Miner : public Person
{
	private:
		char display_code;
		int id_num;
		char state;
		double amount;
		Cart_Point location;
		Gold_Mine* mine;
		Town_Hall* home;

	public:
		Miner()
		{
			Person('M');
			amount = 0;
			mine = NULL;
			home = NULL;

			cout << "Miner default constructed." << endl;
		}

		Miner(int in_id, Cart_Point in_loc)
		{
			Person('M', in_id, in_loc);
			amount = 0;
			mine = 0;
			home = 0;

			cout << "Miner constructed." << endl;
		}

		bool update()
		{
			switch(state)
			{
				case 's':
					return false;

				case 'm':
					if (update_location())
					{
						state = 's';
						return true;
					}
					else
					{
						return false;
					}

				case 'o':
					if (update_location())
					{
						state = 'g';
						return true;
					}

					else
					{
						return false;
					}

				case 'g':
					mine.dig_gold();
					cout << display_code << id_num << ": Got " << amount << " gold." << endl;
					setup_destination() //need destination
					state = 'i';
					return true;

				case 'i' :
					if (update_location())
					{
						state = 'd';
						return true;
					}
					else
					{
						return false;
					}

				case 'd':
					cout << display_code << id_num << ": Deposit " << amount << " of gold." << endl;
					home.deposit_gold();
					amount = 0;
					if(mine.status == 'e')
					{
						state = 's';
						cout << display_code << id_num << ": More work?" << endl;
						return true;
					}
					else
					{
						state = 'o';
						cout << display_code << id_num << ": Going back for more." << endl;
						return true;
					}
			}
		}

		void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
		{
			//figure out how to move gold from mine to home
			this -> mine = inputMine;
			this -> home = inputHome;
			
			setup_destination(home.location); //this is probably wrong need destination
			state = 'o';
			cout << "Miner " << id_num << " mining at Gold_Mine " << mine << " and depositing at Town_Hall " << home << endl;
			cout << display_code << id_num << ": Yes, my lord." << endl;
		}

		Cart_Point get_location()
		{
			return location;
			cout << "Miner status: " << Person::show_status() <<;
			switch(state)
			{
				case 's':
					cout << "Stopped." << endl;

				case 'm':
					//this is probably wrong bc i dont know destination
					cout << "Moving at speed " << speed << " to " << destination;

				case 'o':
					cout << "Outbound to a mine." << endl;

				case 'g':
					cout << "Getting gold from mine." << endl;

				case 'i' :
					cout << "Inbound to home with load: " << amount << endl;

				case 'd':
					cout << "Depositing gold." << endl;
			}

		}
}