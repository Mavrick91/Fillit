#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stdlib.h>

# define BUFF_SIZE 1024

# include "Libft/libft.h"

typedef struct        s_tetriminos
{
  char                **tetriminos;
	int             		start_x;
	int           			end_x;
	int           			start_y;
	int           			end_y;
  struct s_tetriminos *tetris_next;
  struct s_tetriminos *tetris_prev;
}                     t_tetriminos;

typedef struct s_double_list
{
  struct s_tetriminos *begin;
  struct s_tetriminos *end;
} t_double_list;

/*------------   MAIN.C   ------------*/
int								get_fd(char *file);
char 							*get_content_file(int fd);
char 							**set_array_with_dots();
void 							initialize_struct_coordonne(t_tetriminos *tetris);

/*------------   TETRIMINOS_UTILS.C   ------------*/
t_double_list 		*get_list_tetriminos(t_double_list *li, char *buff);
t_double_list 		*push_tetriminos_to(t_double_list *li, char **array_tetriminos, int tmp);
char 							**split_array_tetriminos(char **array_tmp, char **array_tetriminos, int tmp);

/*------------   LIST_UTILS.C   ------------*/
t_double_list 		*push_back_dlist(t_double_list *li, char **data);

/*------------   FILLIT_ALGO.C   ------------*/
t_double_list 		*change_hash_into_alpha(t_double_list *li);
char 							convert_hash(t_tetriminos *tmp, char alpha, int i, int j);

/*------------   COORDONNE_START_END_X_TETRIMINOS.C   ------------*/
void get_coordonne_start_x(t_tetriminos **tetris);
void get_coordonne_end_x(t_tetriminos **tetris);
int								is_column_contain_letter(char **tetriminos, int column);

/*------------   COORDONNE_START_END_Y_TETRIMINOS.C   ------------*/
void get_coordonne_start_y(t_tetriminos **tetris);
void get_coordonne_end_y(t_tetriminos **tetris);
int 							is_line_contain_letter(char **tetriminos, int line);

/*------------   SOLUTION_TETRIMINOS.C   ------------*/
char **solution_tetriminos(struct s_tetriminos *tetris, char **array_final);
void get_coordonne_tetriminos(t_tetriminos *tetris);
char **insert_tetriminos_in(char **array_final, t_tetriminos *tetriminos, int line_array, int column_array);

/*------------   EXPAND_ARRAY.C   ------------*/
char 							**expand_size_array(char **array_final);
char 							*fill_in_row(int size);

#endif
