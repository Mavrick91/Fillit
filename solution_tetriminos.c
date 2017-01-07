#include "fillit.h"

int dont_have_collision(char **array_final, struct s_tetriminos *tetris, t_coordonne *coordonne_tetriminos);

char **solution_tetriminos(struct s_tetriminos *tetris, char **array_final, t_coordonne *coordonne_tetriminos) {
  if (tetris == NULL)
    return (array_final);
  initialize_struct_coordonne(coordonne_tetriminos);
  get_coordonne_tetriminos(tetris->tetriminos, &coordonne_tetriminos);
  if (dont_have_collision(array_final, tetris, coordonne_tetriminos))
    array_final = insert_tetriminos_in(array_final, tetris, coordonne_tetriminos);
//  display_solution(array_final);
  return solution_tetriminos(tetris->tetris_next, array_final, coordonne_tetriminos);
}

int dont_have_collision(char **array_final, struct s_tetriminos *tetris, t_coordonne *coordonne_tetriminos) {
  int line_array = 0, begin = 0;
  int column_array;
  int i, j;

  column_array = begin;
  while (array_final[line_array])
  {
    while(array_final[line_array][column_array])
    {
      i = coordonne_tetriminos->start_y;
      while(i < coordonne_tetriminos->end_y)
      {
        j = coordonne_tetriminos->start_x;
        column_array = begin;
        while(j < coordonne_tetriminos->end_x)
        {

          if(array_final[line_array][column_array] != '.' && tetris->tetriminos[i][j] != '.')
          {
            line_array++;
            column_array = begin;
          } else {
            j++;
            column_array++;
          }
        }
        i++;
        line_array++;
        if (i == coordonne_tetriminos->end_y)
          return (1);
        if (array_final[line_array] == NULL){
          line_array = 0;
          begin++;
          column_array = begin;
          i = coordonne_tetriminos->start_y;
          j = coordonne_tetriminos->start_x;
        }
      }
    }

  }
  return 0;
}

void get_coordonne_tetriminos(char **tetriminos, t_coordonne **coordonne_tetriminos) {
  get_coordonne_start_x(tetriminos, coordonne_tetriminos);
  get_coordonne_end_x(tetriminos, coordonne_tetriminos);
  get_coordonne_start_y(tetriminos, coordonne_tetriminos);
  get_coordonne_end_y(tetriminos, coordonne_tetriminos);
}

char **insert_tetriminos_in(char **array_final, struct s_tetriminos *tetriminos, t_coordonne *coordonne_tetriminos)
{
  
  int tetris_line;
  int tetris_column;
  int array_line;
  int array_column;
  char **array_tmp;

  array_tmp = array_final;
  tetris_line = coordonne_tetriminos->start_y;
  array_line = 0;
  while(tetris_line < coordonne_tetriminos->end_y)
  {
    tetris_column = coordonne_tetriminos->start_x;
    array_column = 0;
    while(tetris_column < coordonne_tetriminos->end_x)
    {
      while (array_final[array_line][array_column] != '.' && tetriminos->tetriminos[tetris_line][tetris_column] != '.') {
        if (array_line == array_column || array_column > array_line)
          array_line++;
        else if (array_line > array_column)
          array_column++;
      }
      if (array_final[array_line][array_column] == '.' && tetriminos->tetriminos[tetris_line][tetris_column] != '.')
        array_final[array_line][array_column] = tetriminos->tetriminos[tetris_line][tetris_column];
      else if (array_final[array_line][array_column] != '.' && tetriminos->tetriminos[tetris_line][tetris_column] != '.')
        return (array_tmp);
      tetris_column++;
      array_column++;
    }
    tetris_line++;
    array_line++;
  }

  return (array_final);
}

void display_solution(char **array_final) {
  int i = 0, j = 0;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 10; j++) {
      printf("%c", array_final[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}
