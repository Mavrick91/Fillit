#include "fillit.h"

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
