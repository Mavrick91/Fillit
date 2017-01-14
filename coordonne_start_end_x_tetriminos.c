#include "fillit.h"

void get_coordonne_start_x(t_tetriminos **tetris)
{
  int column;

  column = 0;
  while ((*tetris)->tetriminos[0][column] && (*tetris)->start_x == -1)
  {
    if (is_column_contain_letter((*tetris)->tetriminos, column))
      (*tetris)->start_x = column;
    column++;
  }
}

void get_coordonne_end_x(t_tetriminos **tetris)
{
  int column;

  column = (*tetris)->start_x;
  while (is_column_contain_letter((*tetris)->tetriminos, column))
    column++;
  (*tetris)->end_x = column;
}

int is_column_contain_letter(char **tetriminos, int column)
{
  int line;

  line = 0;
  while (tetriminos[line])
  {
    if (tetriminos[line][column] != '.' && tetriminos[line][column] != '\0')
      return (1);
    line++;
  }
  return (0);
}