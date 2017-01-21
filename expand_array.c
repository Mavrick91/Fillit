#include "fillit.h"

char **copy_array_final(char **array_final, char **array_tmp);

char **expand_size_array(char **array_final)
{
	int i;
	int j;
	char **array_tmp;

	i = 0;
	while (array_final[i])
		i++;
	j = i + 1;
	i = 0;
	array_tmp = malloc(sizeof(char *) * (j + 1));
	while (i < j)
	{
		array_tmp[i] = fill_in_row(j);
		i++;
	}
	array_tmp[i]= NULL;
	array_tmp = copy_array_final(array_final, array_tmp);
	free_array(array_final);
	return array_tmp;
}

char *fill_in_row(int size)
{
	int 	i;
	char	*tmp_row;
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

char **copy_array_final(char **array_final, char **array_tmp)
{
	int 	i;
	int 	j;

	i = 0;
	while (array_final[i])
	{
		j = 0;
		while (array_final[i][j])
		{
			array_tmp[i][j] = array_final[i][j];
			j++;
		}
		i++;
	}
	return array_tmp;
}
