#ifndef
#define

class Gold_Mine : public Game_Object
{
	private:
		char diplay_code;
		int id_num;
		char state;
		double amount;
		Cart_Point location;

	public:

		Cart_Point get_location();
		int get_id();
		bool is_empty();
		double dig_gold(double amount_to_dig = 35.0);
		bool update();
		void show_status();


		Gold_Mine();
		Gold_Mine(int inputId, Cart_Point inputLoc);
}