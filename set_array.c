#include "fillit.h"

char **set_array_with_dots()
{
	char **array_final;

	int i = 0, j;
	array_final = malloc(sizeof(char *) * 2);
	while (i < 1)
	{
		array_final[i] = malloc(sizeof(char) * 1 + 1);
		j = 0;
		while (j < 1)
		{
			array_final[i][j] = '.';
			j++;
		}
		array_final[i][j] = '\0';
		i++;
	}
	array_final[i] = NULL;
	return array_final;
}
