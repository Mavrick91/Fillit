#include "fillit.h"

t_double_list *get_list_tetriminos(char *buff)
{
	t_double_list *li;
	char **array;
	int tmp;

	tmp = 0;
	li = NULL;
	array = ft_strsplit(buff, '\n');
	while (array[tmp])
	{
		li = push_tetriminos_to(li, array, tmp);
		tmp += 4;
	}
	free_array(array);
	li = change_hash_into_alpha(li);
	return (li);
}

t_double_list *
push_tetriminos_to(t_double_list *li, char **array, int tmp)
{
	char **array_tmp;

	array_tmp = malloc(sizeof(char *) * (5 + 1));
	array_tmp = split_array_tetriminos(array_tmp, array, tmp);
	li = push_back_dlist(li, array_tmp);
	return (li);
}

char **
split_array_tetriminos(char **array_tmp, char **array_tetris, int tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		array_tmp[i] = ft_strdup(array_tetris[tmp]);
		i++;
		tmp++;
	}
	array_tmp[i] = NULL;
	return (array_tmp);
}