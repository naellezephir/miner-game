#ifndef MODEL_H
#define MODEL_H
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Person.h"
#include "Miner.h"
#include "Town_Hall.h"
#include "View.h"

class Model
{
	private:
		int tick;
		Game_Object* object_ptrs[10];
		int num_objects;
		Person* person_ptrs[10];
		int num_persons;
		Gold_Mine* mine_ptrs[10];
		int num_mines;
		Town_Hall* hall_ptrs[10];
		int num_halls;
		Model(const Model&);

	public:
		Model();
		~Model();
		Person* get_Person_ptr(int id);
		Gold_Mine* get_Gold_Mine_ptr(int id);
		Town_Hall* get_Town_Hall_ptr(int id);
		bool update();
		void display(View& );
		void show_status();

};

#endif
