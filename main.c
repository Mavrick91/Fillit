#include "fillit.h"

void display_array(char **array_final);

int main(int argc, char *argv[])
{
	int fd;
	char *buff;
	char **array_final;
	t_double_list *li;

	li = NULL;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit <file>\n");
		return (EXIT_FAILURE);
	}
	if ((fd = get_fd(argv[1])) == -1)
		return (EXIT_FAILURE);
	if ((buff = get_content_file(fd)) == NULL)
		return (EXIT_FAILURE);
	li = get_list_tetriminos(li, buff);
	array_final = set_array_with_dots();
	array_final = solution_tetriminos(li->begin, array_final);
	display_array(array_final);
	return (EXIT_SUCCESS);
}

void display_array(char **array_final)
{
	int 	line;

	line = 0;
	while(array_final[line])
	{
		ft_putstr(array_final[line]);
		ft_putstr("\n");
		line++;
	}
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

	if (!(buff = (char *) malloc(sizeof(char) * BUFF_SIZE + 1)))
	{
		ft_putstr("Problem malloc\n");
		return (NULL);
	}
	if ((read(fd, buff, BUFF_SIZE)) == -1)
	{
		ft_putstr("Error during function read\n");
		return (NULL);
	}
	return (buff);
}

char **set_array_with_dots()
{
	char **array_final;

	int i = 0, j;
	array_final = (char **) malloc(sizeof(char *) * 3);
	while (i < 2) {
		array_final[i] = (char *) malloc(sizeof(char) * 2 + 1);
		j = 0;
		while (j < 2)
		{
			array_final[i][j] = '.';
			j++;
		}
		array_final[i][j] = '\0';
		i++;
	}
	return array_final;
}

void initialize_struct_coordonne(t_tetriminos *tetris)
{
	tetris->start_x = -1;
	tetris->end_x = -1;
	tetris->start_y = -1;
	tetris->end_y = -1;
}
