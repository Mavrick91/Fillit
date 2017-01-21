#include "fillit.h"

char **get_solution(t_tetriminos *tetris)
{
	int 	count_tetriminos;
	char 	**array;

	array = NULL;
	count_tetriminos = get_total_tetriminos(tetris);
	array = permute_algo(tetris, 0, count_tetriminos - 1, array);
	return array;
}


int get_total_tetriminos(t_tetriminos *tetris)
{
	int 	count;

	count = 0;
	while (tetris)
	{
		count++;
		tetris = tetris->tetris_next;
	}
	return count;
}

char **permute_algo(t_tetriminos *tetris, int l, int r, char **array)
{
	int i;
	char **array_tmp;

	if (l == r)
	{
		array_tmp = set_array_with_dots();
		if (array == NULL)
			return solution_tetriminos(tetris, array_tmp);
		else
		{
			array_tmp = solution_tetriminos(tetris, array_tmp);
			if (ft_strlen(array_tmp[0]) < ft_strlen(array[0]))
				return array_tmp;
			free_array(array_tmp);
		}
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap_tetriminos(move_in(tetris, l), move_in(tetris, i));
			array = permute_algo(tetris, l + 1, r, array);
			swap_tetriminos(move_in(tetris, l), move_in(tetris, i));
		}
	}
	return (array);
}

t_tetriminos *move_in(t_tetriminos *tetris, int l)
{
	while (l)
	{
		tetris = tetris->tetris_next;
		l--;
	}
	return tetris;
}

void swap_tetriminos(t_tetriminos *x, t_tetriminos *y)
{
	t_tetriminos temp;

	if (x->tetriminos == y->tetriminos)
		return;
	temp.start_x = x->start_x;
	temp.start_y = x->start_y;
	temp.end_x = x->end_x;
	temp.end_y = x->end_y;
	temp.tetriminos = x->tetriminos;

	x->start_x = y->start_x;
	x->start_y = y->start_y;
	x->end_x = y->end_x;
	x->end_y = y->end_y;
	x->tetriminos = y->tetriminos;

	y->start_x = temp.start_x;
	y->start_y = temp.start_y;
	y->end_x = temp.end_x;
	y->end_y = temp.end_y;
	y->tetriminos = temp.tetriminos;
}
