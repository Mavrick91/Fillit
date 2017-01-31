#include "fillit.h"

char **expand_array(int size)
{
	int i;
	char **array_tmp;

	i = 0;
	array_tmp = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		array_tmp[i] = fill_in_row(size);
		i++;
	}
	array_tmp[i] = NULL;
	return array_tmp;
}

char *fill_in_row(int size)
{
	int i;
	char *tmp_row;
	i = 0;

	tmp_row = malloc(sizeof(char) * (size + 2));
	while (i < size)
	{
		tmp_row[i] = '.';
		i++;
	}
	tmp_row[i] = '\0';
	return tmp_row;
}