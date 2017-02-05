#include "fillit.h"

void initialize_struct_coordonne(t_tetriminos *tetris)
{
	tetris->start_x = -1;
	tetris->end_x = -1;
	tetris->start_y = -1;
	tetris->end_y = -1;
}

int 	*initialize_array_position()
{
	int 	*array;

	if ((array = malloc(sizeof(int) * 5)) == NULL)
		return (NULL);
	array[0] = -1;
	array[1] = -1;
	array[2] = -1;
	array[3] = -1;
	return array;
}
