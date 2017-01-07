#include "fillit.h"

int is_line_contain_letter(char **tetriminos, int line) {
  int column;

  column = 0;
  while ( line < 4 && tetriminos[line][column]) {
    if (tetriminos[line][column] != '.' && tetriminos[line][column] != '\0')
      return (1);
    column++;
  }
  return (0);
}

void get_coordonne_start_y(char **tetriminos, t_coordonne **coordonne_tetriminos) {
  int line;

  line = 0;
  while ((*coordonne_tetriminos)->start_y == -1 && tetriminos[line][0]) {
    if (is_line_contain_letter(tetriminos, line))
      (*coordonne_tetriminos)->start_y = line;
    line++;
  }
}

void get_coordonne_end_y(char **tetriminos, t_coordonne **coordonne_tetriminos) {
  int line;

  line = (*coordonne_tetriminos)->start_y;
  while (is_line_contain_letter(tetriminos, line))
    line++;
  (*coordonne_tetriminos)->end_y = line;
}