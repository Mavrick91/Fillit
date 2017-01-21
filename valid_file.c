#include <stdbool.h>
#include "fillit.h"

int how_many(char character, char *tetriminos);

int valid_file(char *buff)
{
	if (buff == NULL)
		return (-1);
	if ((scan_buff(buff)) == -1)
	{
		free(buff);
		return error_file();
	}
	return (1);
}

int error_file()
{
	ft_putstr("File invalid\n");
	ft_putstr("\n");
	return -1;
}

int scan_buff(char *buff)
{
	int index;
	char *tetriminos;
	int length;

	index = 0;
	length = ft_strlen(buff);
	while (index < length)
	{
		tetriminos = get_tetriminos(buff, index, index + 20);
		if ((tetriminos_valid(tetriminos)) == -1)
			return (-1);
		index += 21;
	}
	return false;
}

char *get_tetriminos(char *buff, int start, int end)
{
	char *tetriminos;
	int index;

	index = 0;
	if ((tetriminos = malloc(sizeof(char) * 21)) == NULL)
		return (NULL);
	while (start < end)
	{
		tetriminos[index] = buff[start];
		index++;
		start++;
	}
	tetriminos[index] = '\0';
	return tetriminos;
}

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