#ifndef MINER_H
#define MINER_H
#include "Person.h"

class Miner : public Person
{
	public:
		Miner();
		Miner(int in_id, Cart_Point in_loc);
		~Miner();
		bool update();
		void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);
		Cart_Point get_location();
		double gold;
		void show_status();

	private:
		int id_num;
		double amount;
		Cart_Point location;
		Gold_Mine* mine;
		Town_Hall* home;
};

#endif
