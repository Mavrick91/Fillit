#include "fillit.h"

int tetriminos_valid(char *tetriminos)
{
	if ((how_many('#', tetriminos)) != 4 || (how_many('.', tetriminos)) != 12 ||
			(how_many('\n', tetriminos)) != 4)
	{
		free(tetriminos);
		return (-1);
	}

	free(tetriminos);
	return (1);
}

int is_good_piece(char *tetriminos, int index, int hashtag)
{
	if (tetriminos[index] == '\0')
		return (0);
	if (hashtag == 4)
		return (1);
	if (tetriminos[index] != '#' && hashtag > 0)
		return is_good_piece(tetriminos, index + 3, hashtag);
	if (tetriminos[index] != '#')
		return is_good_piece(tetriminos, index + 1, hashtag);
	if (tetriminos[index] == '#')
		if (is_good_piece(tetriminos, index + 1, hashtag + 1))
			return (1);
	return (0);
}

int how_many(char character, char *tetriminos)
{
	int index;
	int count_character;

	count_character = 0;
	index = 0;
	while (tetriminos[index])
	{
		if (tetriminos[index] == character)
			count_character++;
		index++;
	}
	return (count_character);
}