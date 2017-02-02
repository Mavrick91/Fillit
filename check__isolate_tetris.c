#include "fillit.h"

int is_valid(char *buff)
{
	if (buff == NULL)
		return (-1);
	if ((scan_buff(buff)) == 1)
		return (1);
	free(buff);
	return error_file();
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
	return 1;
}

char *get_tetriminos(char *buff, int start, int end)
{
	char *tetriminos;
	int index;

	index = 0;
	if ((tetriminos = malloc(sizeof(char) * 22)) == NULL)
		return (NULL);
	ft_memset(tetriminos, 0, 22);
	while (start < end)
	{
		tetriminos[index] = buff[start];
		index++;
		start++;
	}
	tetriminos[index] = '\0';
	return tetriminos;
}