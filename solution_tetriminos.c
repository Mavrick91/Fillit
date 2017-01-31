#include "fillit.h"

int get_size_array(char **array);

char **set_array_full_dots(char **array);


char **
solution_tetriminos(t_tetriminos *tetris, char **array, int line, int column)
{
	t_tetriminos *tetris_tmp;
	int size_array;
	char **array_tmp;


	tetris_tmp = tetris;
	size_array = get_size_array(array);
	array_tmp = complete_array(array, tetris_tmp, line, column);
	if (array_tmp == NULL)
	{
		array = set_array_full_dots(array);
		if (array[line] == NULL)
		{
			array = expand_array(size_array + 1);
			return solution_tetriminos(tetris, array, 0, 0);
		}
		else if (array[line][column] != '\0')
			return solution_tetriminos(tetris, array, line, column + 1);
		else
			return solution_tetriminos(tetris, array, line + 1, 0);
	}
	else
		return array;
}

char **set_array_full_dots(char **array)
{
	int line;
	int column;

	line = 0;
	while (array[line])
	{
		column = 0;
		while (array[line][column])
		{
			array[line][column] = '.';
			column++;
		}
		array[line][column] = '\0';
		line++;
	}
	array[line] = NULL;
	return array;
}

int get_size_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char **complete_array(char **array, t_tetriminos *tetris, int line, int column)
{
	if (tetris == NULL)
		return array;
	if (array[line] == NULL)
		return NULL;
	initialize_struct_coordonne(tetris);
	get_coordonne_tetriminos(tetris);
	if (check_collision(array, tetris, line, column) == -1 && array[line] != NULL)
	{
		if (array[line][column] == '\0')
			return complete_array(array, tetris, line + 1, 0);
		if (array[line][column] != '\0')
			return complete_array(array, tetris, line, column + 1);
	}
	else
	{
		array = insert_tetris(array, tetris, line, column);
		tetris = tetris->tetris_next;
		if (complete_array(array, tetris, 0, 0))
			return array;
		tetris = tetris->tetris_prev;
		array = remove_tetris(array, tetris);
		return complete_array(array, tetris, line, column + 1);
	}
	return NULL;
}


void get_coordonne_tetriminos(t_tetriminos *tetris)
{
	get_coordonne_start_x(&tetris);
	get_coordonne_end_x(&tetris);
	get_coordonne_start_y(&tetris);
	get_coordonne_end_y(&tetris);
}

char **insert_tetris(char **array, t_tetriminos *tetris, int i, int j)
{
	int k;
	int l;
	int tmp;

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

int check_collision(char **array, t_tetriminos *tetris, int line_array,
										int column_array)
{
	int line_tetris;
	int column_tetris;
	int tmp_column_array;

	tmp_column_array = column_array;
	line_tetris = tetris->start_y;
	while (array[line_array] && line_tetris < tetris->end_y)
	{
		column_tetris = tetris->start_x;
		while (array[line_array][column_array] && column_tetris < tetris->end_x)
		{
			if (array[line_array][column_array] != '.' &&
					tetris->tetriminos[line_tetris][column_tetris] != '.')
				return (-1);
			column_array++;
			column_tetris++;
		}
		if (array[line_array][column_array] == '\0' &&
				column_tetris < tetris->end_x)
			return (-1);
		line_array++;
		line_tetris++;
		column_array = tmp_column_array;
	}
	if (array[line_array] == NULL && line_tetris < tetris->end_y)
		return (-1);
	return (1);
}