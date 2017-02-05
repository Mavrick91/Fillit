#include "fillit.h"

int is_tetriminos_valid(char *buff);

int is_valid(char *buff)
{
	if (buff == NULL)
		return (-1);
	if ((scan_buff(buff)) == 1)
		if ((is_tetriminos_valid(buff)) == 1)
			return (1);
	free(buff);
	return error_file();
}

int scan_buff(char *buff)
{
	int 	index;
	int 	length;

	index = 0;
	length = ft_strlen(buff);
	if (length == 0)
		return (-1);
	while (index < length)
	{
		if (buff[index + 19] == '\n' && buff[index + 20] == '\0')
			return (1);
		if (buff[index + 19] == '\n' && buff[index + 20] != '\n')
			return (-1);
		if (buff[index + 20] == '\n' && buff[index + 21] == '\n')
			return (-1);
		if (buff[index + 20] == '\n' && buff[index + 21] == '\0')
			return (-1);
		index += 21;
	}
	return 1;
}

int error_file()
{
	ft_putstr("error");
	return (-1);
}

int is_tetriminos_valid(char *buff)
{
	int index;
	char *tetriminos;
	int length;

	index = 0;
	length = ft_strlen(buff);
	while (index < length)
	{
		tetriminos = get_tetriminos(buff, index, index + 19);
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
