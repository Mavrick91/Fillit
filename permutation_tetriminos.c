#include "fillit.h"

char **get_solution(t_tetriminos *tetris)
{
	char **array;

	array = set_array_with_dots();
	return solution_tetriminos(tetris, array, 0, 0);
}
