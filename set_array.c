#include "fillit.h"

char **set_array_with_dots()
{
	char **array;

	int i = 0, j;
	array = malloc(sizeof(char *) * 3);
	while (i < 2)
	{
		array[i] = malloc(sizeof(char) * 2 + 1);
		j = 0;
		while (j < 2)
		{
			array[i][j] = '.';
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return array;
}
