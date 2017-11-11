#ifndef
#define

class Town_Hall : public Game_Object
{
	private:
		char display_code;
		int id_num;
		char state;
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
}