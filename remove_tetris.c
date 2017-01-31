#include "fillit.h"

char **remove_tetris(char **array, t_tetriminos *tetris)
{
	char letter;

	letter = get_letter(tetris);
	array = remove_letter(letter, array);
	return array;
}

char **remove_letter(char letter, char **array)
{
	int i;
	int j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == letter)
				array[i][j] = '.';
			j++;
		}
		i++;
	}
	return array;
}

char get_letter(t_tetriminos *tetris)
{
	int i;
	int j;

	i = 0;
	while (tetris->tetriminos[i])
	{
		j = 0;
		while (tetris->tetriminos[i][j])
		{
			if (tetris->tetriminos[i][j] != '.')
				return tetris->tetriminos[i][j];
			j++;
		}
		i++;
	}
	return 0;
}