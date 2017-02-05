#include "fillit.h"

int main(int argc, char *argv[])
{
	int fd;
	char *buff;
	char **array;
	t_double_list *li;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit <file>\n");
		return (EXIT_FAILURE);
	}
	if ((fd = get_fd(argv[1])) == -1)
		return (EXIT_FAILURE);
	if ((buff = get_content_file(fd)) == NULL)
		return (EXIT_FAILURE);
	if ((is_a_valid_file(buff)) != 1)
		return (EXIT_FAILURE);
	li = get_list_tetriminos(buff);
	free(buff);
	array = get_solution(li->begin);
	display_array(array);
	free_list(li);
	free_array(array);
	return (EXIT_SUCCESS);
}

int get_fd(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr("File descriptor invalid\n");
	return (fd);
}

char *get_content_file(int fd)
{
	char *buff;

	if (!(buff = malloc(sizeof(char) * BUFF_SIZE + 1)))
	{
		ft_putstr("Problem malloc\n");
		return (NULL);
	}
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	if ((read(fd, buff, BUFF_SIZE)) == -1)
	{
		ft_putstr("Error during function read\n");
		return (NULL);
	}
	return (buff);
}
