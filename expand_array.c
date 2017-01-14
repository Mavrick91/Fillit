#include "fillit.h"

char **copy_array_final(char **array_final, char **tmp_array);

char **expand_size_array(char **array_final)
{
	int 	i;
	int 	j;
	char 	**tmp_array;

	i = 0;
	while (array_final[i])
		i++;
	j = i + 1;
	i = 0;
	tmp_array = (char **) malloc(sizeof(char *) * j);
	while (i < j)
	{
		tmp_array[i] = (char *) malloc(sizeof(char) * j + 1);
		tmp_array[i] = fill_in_row(j);
		i++;
	}
	tmp_array[i] = NULL;
	tmp_array = copy_array_final(array_final, tmp_array);
	return (tmp_array);
}

char *fill_in_row(int size)
{
	int 	i;
	char	*tmp_row;
	i = 0;

	tmp_row = (char*)malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		tmp_row[i] = '.';
		i++;
	}
	tmp_row[i] = '\0';
	return tmp_row;
}

char **copy_array_final(char **array_final, char **tmp_array)
{
	int 	i;
	int 	j;

	i = 0;
	while (array_final[i])
	{
		j = 0;
		while (array_final[i][j])
		{
			tmp_array[i][j] = array_final[i][j];
			j++;
		}
		i++;
	}
	return tmp_array;
}
