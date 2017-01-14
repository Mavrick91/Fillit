#include <stdbool.h>
#include "fillit.h"

int insert_tetris(char **array_final, t_tetriminos *tetris, int line_array, int column_array);

char **real_insert(char **array_final, t_tetriminos *tetris, int line_array, int column_array);

char **solution_tetriminos(t_tetriminos *tetris, char **array_final)
{

	if (tetris == NULL)
		return (array_final);
	initialize_struct_coordonne(tetris);
	get_coordonne_tetriminos(tetris);
	if ((array_final = insert_tetriminos_in(array_final, tetris, 0, 0)) != NULL)
		return solution_tetriminos(tetris->tetris_next, array_final);
}

void get_coordonne_tetriminos(t_tetriminos *tetris)
{
	get_coordonne_start_x(&tetris);
	get_coordonne_end_x(&tetris);
	get_coordonne_start_y(&tetris);
	get_coordonne_end_y(&tetris);
}

char **insert_tetriminos_in(char **array_final, t_tetriminos *tetris, int line_array, int column_array)
{
	int res;

	if (!array_final[line_array])
	{
		array_final = expand_size_array(array_final);
		return insert_tetriminos_in(array_final, tetris, 0, 0);
	}
	if (array_final[line_array][column_array] == '\0')
		return insert_tetriminos_in(array_final, tetris, line_array + 1, 0);
	res = insert_tetris(array_final, tetris, line_array, column_array);
	if (res == 1)
		return (real_insert(array_final, tetris, line_array, column_array));
	else if (res == -2)
	{
		array_final = expand_size_array(array_final);
		return insert_tetriminos_in(array_final, tetris, 0, 0);
	}
	else if (res == -1)
		return insert_tetriminos_in(array_final, tetris, line_array, column_array + 1);
	return (array_final);
}

char **real_insert(char **array_final, t_tetriminos *tetris, int line_array, int column_array)
{
	int 	line_tetris;
	int 	column_tetris;
	int 	tmp;

	tmp = column_array;
	line_tetris = tetris->start_y;
	while (line_tetris < tetris->end_y)
	{
		column_tetris = tetris->start_x;
		column_array = tmp;
		while (column_tetris < tetris->end_x)
		{
			if (tetris->tetriminos[line_tetris][column_tetris] != '.')
				array_final[line_array][column_array] = tetris->tetriminos[line_tetris][column_tetris];
			column_tetris++;
			column_array++;
		}
		line_tetris++;
		line_array++;
	}
	return (array_final);
}

int insert_tetris(char **array_final, t_tetriminos *tetris, int line_array, int column_array)
{
	int 	column_tetris;
	int 	line_tetris;
	int 	tmp;

	tmp = column_array;
	line_tetris = tetris->start_y;
	while (line_tetris < tetris->end_y)
	{
		column_tetris = tetris->start_x;
		column_array = tmp;
		while (column_tetris < tetris->end_x && array_final[line_array][column_array] && (column_array + (tetris->end_x - tetris->start_x)) != '\0')
		{
			if(tetris->tetriminos[line_tetris][column_tetris] != '.' && array_final[line_array][column_array] != '.')
				return (-1);
			column_tetris++;
			column_array++;
		}
		line_tetris++;
		line_array++;
		if ((!array_final[line_array] && line_tetris < tetris->end_y))
			return (-2);
		if ((!array_final[line_array - 1][column_array] && column_tetris < tetris->end_x))
			return (-1);
	}
	return (1);
}