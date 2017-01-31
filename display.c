#include "fillit.h"

void display_array(char **array)
{
	int line;

	line = 0;
	while (array[line])
	{
		ft_putstr(array[line]);
		ft_putstr("\n");
		line++;
	}
}