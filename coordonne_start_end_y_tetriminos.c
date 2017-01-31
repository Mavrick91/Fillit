#include "fillit.h"

void get_coordonne_start_y(t_tetriminos **tetris)
{
	int line;

	line = 0;
	while ((*tetris)->start_y == -1 && (*tetris)->tetriminos[line][0])
	{
		if (is_line_contain_letter((*tetris)->tetriminos, line))
			(*tetris)->start_y = line;
		line++;
	}
}

void get_coordonne_end_y(t_tetriminos **tetris)
{
	int line;

	line = (*tetris)->start_y;
	while (is_line_contain_letter((*tetris)->tetriminos, line))
		line++;
	(*tetris)->end_y = line;
}

int is_line_contain_letter(char **tetriminos, int line)
{
	int column;

	column = 0;
	while (line < 4 && tetriminos[line][column])
	{
		if (tetriminos[line][column] != '.' && tetriminos[line][column] != '\0')
			return (1);
		column++;
	}
	return (0);
}