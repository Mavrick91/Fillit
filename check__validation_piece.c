#include "fillit.h"

int tetriminos_valid(char *tetris)
{
	if ((how_many('#', tetris)) != 4 || (how_many('.', tetris)) != 12 ||
			(how_many('\n', tetris)) != 4 || is_good_piece(tetris) == -1)
	{
		free(tetris);
		return (-1);
	}
	free(tetris);
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

int is_good_piece(char *tetris)
{
	int 	index;
	int 	nb_hashtag;
	int 	*array_position;
	int 	i;

	i = 0;
	nb_hashtag = 1;
	array_position = initialize_array_position();
	index = get_first_hashtag(tetris);
	add_to_array_position(&array_position, &index);
	while (i < 5)
	{
		inspect_piece(&tetris, &index, &array_position, &nb_hashtag);
		i++;
	}
	free(array_position);
	if(nb_hashtag == 4)
		return (1);
	return (-1);
}

void inspect_piece(char **tetris, int *index, int **buffer, int *nb_hashtag)
{
	if (move_right(tetris, index) && !array_contains(index, buffer, 1))
	{
		*index += 1;
		*nb_hashtag += 1;
		add_to_array_position(buffer, index);
	}
	else if (move_bottom(tetris, index)
					 && !array_contains(index, buffer, 5))
	{
		*index += 5;
		*nb_hashtag += 1;
		add_to_array_position(buffer, index);
	}
	else if (move_left(tetris, index))
	{
		*index -= 1;
		if (!array_contains(index, buffer, 0)){
			*nb_hashtag += 1;
			add_to_array_position(buffer, index);
		}
	}
}


int get_first_hashtag(char *tetris)
{
	int 	i;

	i = 0;
	while (tetris[i] != '#')
		i++;
	return i;
}
