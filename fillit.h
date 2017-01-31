#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stdlib.h>
# include "Libft/libft.h"

# define BUFF_SIZE 1024

typedef struct s_tetriminos
{
	char **tetriminos;
	int start_x;
	int end_x;
	int start_y;
	int end_y;
	struct s_tetriminos *tetris_next;
	struct s_tetriminos *tetris_prev;
} t_tetriminos;

typedef struct s_double_list
{
	struct s_tetriminos *begin;
	struct s_tetriminos *end;
} t_double_list;


/*------------   MAIN.C   ------------*/
int get_fd(char *file);
char *get_content_file(int fd);

/*------------   TETRIMINOS_UTILS.C   ------------*/
t_double_list *get_list_tetriminos(char *buff);
t_double_list *
push_tetriminos_to(t_double_list *li, char **array_tetriminos, int tmp);

char **
split_array_tetriminos(char **array_tmp, char **array_tetriminos, int tmp);

/*------------   LIST_UTILS.C   ------------*/
t_double_list *push_back_dlist(t_double_list *li, char **data);

/*------------   FILLIT_ALGO.C   ------------*/
t_double_list *change_hash_into_alpha(t_double_list *li);

char convert_hash(t_tetriminos *tmp, char alpha, int i, int j);

/*------------   COORDONNE_START_END_X_TETRIMINOS.C   ------------*/
void get_coordonne_start_x(t_tetriminos **tetris);
void get_coordonne_end_x(t_tetriminos **tetris);
int is_column_contain_letter(char **tetriminos, int column);

/*------------   COORDONNE_START_END_Y_TETRIMINOS.C   ------------*/
void get_coordonne_start_y(t_tetriminos **tetris);
void get_coordonne_end_y(t_tetriminos **tetris);
int is_line_contain_letter(char **tetriminos, int line);

/*------------   SOLUTION_TETRIMINOS.C   ------------*/
char **
solution_tetriminos(t_tetriminos *tetris, char **array, int line, int column);
void get_coordonne_tetriminos(t_tetriminos *tetris);

char **
complete_array(char **array, t_tetriminos *tetriminos, int line, int column);
int check_collision(char **array, t_tetriminos *tetris, int line_array, int column_array);
char **insert_tetris(char **array, t_tetriminos *tetris, int i, int j);

/*------------   EXPAND_ARRAY.C   ------------*/
char **expand_array(int size);
char *fill_in_row(int size);

/*------------   PERMUTATION_TETRIMINOS.C   ------------*/
char **get_solution(t_tetriminos *tetris);

/*------------   DISPLAY.C   ------------*/
void display_array(char **array);

/*------------   FREE_UTILS.C   ------------*/
void free_list(t_double_list *li);
void free_array(char **array_tmp);

/*------------   SET_ARRAY.C   ------------*/
char **set_array_with_dots();

/*------------   INITIALIZE_STRUCT.C   ------------*/
char **set_array_with_dots();
void initialize_struct_coordonne(t_tetriminos *tetris);

/*------------   VALID_FILE.C   ------------*/
int valid_file(char *buff);
int scan_buff(char *buff);

char *get_tetriminos(char *buff, int start, int end);
int error_file();
int tetriminos_valid(char *tetriminos);

/*------------   REMOVE_TETRIS.C   ------------*/
char **remove_tetris(char **array, t_tetriminos *tetris);
char get_letter(t_tetriminos *tetris);
char **remove_letter(char letter, char **array);

#endif
