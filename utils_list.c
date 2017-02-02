#include "fillit.h"

t_double_list *push_back_dlist(t_double_list *li, char **data)
{
	t_tetriminos *elem;

	if (!(elem = malloc(sizeof(*elem))))
		return (NULL);
	elem->tetriminos = data;
	elem->tetris_next = NULL;
	elem->tetris_prev = NULL;
	if (li == NULL)
	{
		if (!(li = malloc(sizeof(*li))))
			return (NULL);
		li->begin = elem;
		li->end = elem;
	}
	else
	{
		li->end->tetris_next = elem;
		elem->tetris_prev = li->end;
		li->end = elem;
	}
	return (li);
}
