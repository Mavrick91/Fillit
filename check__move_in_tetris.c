#include "fillit.h"

int move_bottom(char **tetris, int *index)
{
	if ((*tetris)[*index + 5] == '#')
		return 1;
	return 0;
}

int move_right(char **tetris, int *index)
{

	if ((*tetris)[*index + 1] == '#')
		return 1;
	return 0;
}

int move_left(char **tetris, int *index)
{
	if ((*tetris)[*index -1] == '#')
		return 1;
	return 0;
}
