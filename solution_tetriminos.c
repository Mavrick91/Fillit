#include "fillit.h"

char **solution_tetriminos(t_tetriminos *tetris, char **array)
{
	if (tetris == NULL)
		return (array);
	initialize_struct_coordonne(tetris);
	get_coordonne_tetriminos(tetris);
	array = complete_array(tetris, array, 0, 0);
	return solution_tetriminos(tetris->tetris_next, array);
}

void get_coordonne_tetriminos(t_tetriminos *tetris)
{
	get_coordonne_start_x(&tetris);
	get_coordonne_end_x(&tetris);
	get_coordonne_start_y(&tetris);
	get_coordonne_end_y(&tetris);
}

char **complete_array(t_tetriminos *tetris, char **array, int line, int column)
{
	int res;

	if (!array[line])
	{
		array = expand_size_array(array);
		return complete_array(tetris, array, 0, 0);
	}
	if (array[line][column] == '\0')
		return complete_array(tetris, array, line + 1, 0);
	res = check_collision(array, tetris, line, column);
	if (res == 1)
		return (insert_tetris(array, tetris, line, column));
	else if (res == -2)
	{
		array = expand_size_array(array);
		return complete_array(tetris, array, 0, 0);
	}
	else if (res == -1)
		return complete_array(tetris, array, line, column + 1);
	return (array);
}

char **insert_tetris(char **array, t_tetriminos *tetris, int i, int j)
{
	int 	k;
	int 	l;
	int 	tmp;

	tmp = j;
	k = tetris->start_y;
	while (k < tetris->end_y)
	{
		l = tetris->start_x;
		j = tmp;
		while (l < tetris->end_x)
		{
			if (tetris->tetriminos[k][l] != '.')
				array[i][j] = tetris->tetriminos[k][l];
			l++;
			j++;
		}
		k++;
		i++;
	}
	return (array);
}

int check_collision(char **array, t_tetriminos *tetris, int i, int j)
{
	int 	k;
	int 	l;
	int 	tmp;

	tmp = j;
	l = tetris->start_y;
	while (l < tetris->end_y)
	{
		k = tetris->start_x;
		j = tmp;
		while (k < tetris->end_x && array[i][j])
		{
			if(tetris->tetriminos[l][k] != '.' && array[i][j] != '.')
				return (-1);
			k++;
			j++;
		}
		l++;
		i++;
		if ((!array[i] && l < tetris->end_y))
			return (-2);
		if ((!array[i - 1][j] && k < tetris->end_x))
			return (-1);
	}
	return (1);
}