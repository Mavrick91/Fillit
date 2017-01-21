#include "fillit.h"

void free_list(t_double_list *li)
{
	t_tetriminos *tmp;
	int i = 0;

	while (li->begin)
	{
		tmp = li->begin;
		li->begin = li->begin->tetris_next;
		i = 0;
		while (tmp->tetriminos[i])
		{
			free(tmp->tetriminos[i]);
			i++;
		}
		free(tmp->tetriminos);
		free(tmp);
	}
	free(li);
}

void free_array(char **array_tmp)
{
	int j;

	j = 0;
	while (array_tmp[j])
	{
		free(array_tmp[j]);
		j++;
	}
	free(array_tmp);
}