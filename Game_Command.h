#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include "Model.h"


void do_move_command(Model*, View& view);
void do_go_command(Model*, View& view);
void do_run_command(Model* , View& view);
void do_list_command(Model* );
void do_work_command(Model*, View& view);
void do_stop_command(Model*, View& view);
void do_quit_command(Model* );
void game_command(Model*, char&, View&);

#endif
