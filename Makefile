CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
INCLUDES		=	-I $(LIB_PATH) -I ./includes
SRCS			=     check__scan_buff.c \
                      check__move_in_tetris.c \
                      check__utils_array.c \
                      check__validation_piece.c \
                      coordonne__start_end_x_tetriminos.c \
                      coordonne__start_end_y_tetriminos.c \
                      coordonne__tetriminos.c \
                      display.c \
                      expand_array.c \
                      fillit_algo.c \
                      initialization.c \
                      insert_tetris.c \
                      main.c \
                      permutation_tetriminos.c \
                      remove_tetris.c \
                      set_array.c \
                      solution_tetriminos.c \
                      utils_free.c \
                      utils_list.c \
                      utils_tetriminos.c \

OBJS			=	$(SRCS:%.c=%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[34m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	[ $(C_GOOD)OK$(C_NO) ]
OK				=	[ $(C_OK)OK$(C_NO) ]


all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj/%.o: srcs/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@make -C libft clean
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
