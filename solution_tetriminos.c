#include "fillit.h"

char **
backtracking(t_tetriminos *tetris, char **array, int line, int column)
{
	t_tetriminos *tetris_tmp;
	int size_array;
	char **array_tmp;

	tetris_tmp = tetris;
	size_array = get_size_array(array);
	array_tmp = complete_array(array, tetris_tmp, line, column);
	if (array_tmp != NULL)
		return array;
	array = set_array_full_dots(array);
	if (array[line][column] != '\0')
	{
		free_array(array);
		array = expand_array(size_array + 1);
		return backtracking(tetris, array, 0, 0);
	}
	else if (array[line][column] != '\0')
		return backtracking(tetris, array, line, column + 1);
	else
		return backtracking(tetris, array, line + 1, 0);
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

int check_collision(char **array, t_tetriminos *tetris, int line, int column)
{
	int line_tetris;
	int column_tetris;
	int tmp_column_array;

	tmp_column_array = column;
	line_tetris = tetris->start_y;
	while (array[line] && line_tetris < tetris->end_y)
	{
		column_tetris = tetris->start_x;
		while (array[line][column] && column_tetris < tetris->end_x)
		{
			if (array[line][column] != '.' &&
					tetris->tetriminos[line_tetris][column_tetris] != '.')
				return (-1);
			column++;
			column_tetris++;
		}
		if (array[line][column] == '\0' &&
				column_tetris < tetris->end_x)
			return (-1);
		line++;
		line_tetris++;
		column = tmp_column_array;
	}
	if (array[line] == NULL && line_tetris < tetris->end_y)
		return (-1);
	return (1);
}