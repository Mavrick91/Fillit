#include "fillit.h"

void add_to_array_position(int **array_position, int *index)
{
	int 	i;

	i = 0;
	while (*(*array_position + i) != -1)
		i++;
	*(*array_position + i) = *index;
}

int array_contains(int *index, int **buffer, int j)
{
	int 	i;

	i = 0;
	while (i < 4)
	{
		if(*(*buffer + i) == *index + j)
			return 1;
		i++;
	}
	return 0;
}
