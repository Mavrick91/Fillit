#include "fillit.h"

void get_coordonne_tetriminos(t_tetriminos *tetris)
{
	get_coordonne_start_x(&tetris);
	get_coordonne_end_x(&tetris);
	get_coordonne_start_y(&tetris);
	get_coordonne_end_y(&tetris);
}