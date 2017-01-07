#include "fillit.h"

int main(int argc, char *argv[]) {
  int fd;
  (void) argc;
  t_double_list *li;
  char **array_final;
  t_coordonne *coordonne_tetriminos;

  li = NULL;
  coordonne_tetriminos = (t_coordonne*)malloc(sizeof(t_coordonne));
  if ((fd = open_tetriminos_file(argv[1])) == (-1))
  return (-1);
  li = read_tetriminos_file(fd, li);
  array_final = initialize_array_with_dots();
  array_final = solution_tetriminos(li->begin, array_final, coordonne_tetriminos);
  // display_solution(array_final);
  return (0);
}


int open_tetriminos_file(char *file) {
  int fd;

  // fd = open(file, O_RDONLY);
  return (fd);
}

t_double_list *read_tetriminos_file(int fd, t_double_list *li) {
  char *buff;

  if (!(buff = (char *) malloc(sizeof(char) * BUFF_SIZE + 1)))
    return (NULL);
  if ((read(fd, buff, BUFF_SIZE)) == (-1))
    return (NULL);
  li = get_list_tetriminos(li, buff);
    return (li);
}

char **initialize_array_with_dots() {
  char **array_final;
  int i = 0, j;
  array_final = (char **) malloc(sizeof(char *) * 7);
  while (i < 6) {
    array_final[i] = (char *) malloc(sizeof(char) * 20 + 1);
    j = 0;
    while (j < 20)
    {
      array_final[i][j] = '.';
      j++;
    }
    array_final[i][j] = '\0';
    i++;
  }
  return array_final;
}


void initialize_struct_coordonne(t_coordonne *coordonne) {
  coordonne->start_x = -1;
  coordonne->end_x = -1;
  coordonne->start_y = -1;
  coordonne->end_y = -1;
}
