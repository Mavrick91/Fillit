#include "fillit.h"

int is_column_contain_letter(char **tetriminos, int column) {
  int line;

  line = 0;
  while (tetriminos[line]) {
    if (tetriminos[line][column] != '.' && tetriminos[line][column] != '\0')
      return (1);
    line++;
  }
  return (0);
}

void get_coordonne_start_x(char **tetriminos, t_coordonne **coordonne_tetriminos) {
  int column;

  column = 0;
  while (tetriminos[0][column] && (*coordonne_tetriminos)->start_x == -1) {
    if (is_column_contain_letter(tetriminos, column))
      (*coordonne_tetriminos)->start_x = column;
    column++;
  }
}

void get_coordonne_end_x(char **tetriminos, t_coordonne **coordonne_tetriminos) {
  int column;

  column = (*coordonne_tetriminos)->start_x;
  while (is_column_contain_letter(tetriminos, column))
    column++;
  (*coordonne_tetriminos)->end_x = column;
}
