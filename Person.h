#ifndef
#define

class Person : public Game_Object
{
	public:
		Person();
		Person(char in_code);
		Person(char in_code, int in_id, Cart_Point in_loc);
		void start_moving(Cart_Point dest);
		void stop();
		void show_status();

	protected:
		bool update_location();
		void setup_destination(Cart_Point dest);

	private:
		double speed;
		Cart_Point destination;
		Cart_Vector delta;
}