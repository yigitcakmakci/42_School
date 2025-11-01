NAME = push_swap

SRC = push_swap_push.c push_swap_reverse_rotate.c push_swap_rotate.c push_swap_swap.c \
push_swap_utils.c push_swap.c ft_split.c push_swap_check_input.c push_swap_atois.c set_tmp.c push_swap_free_management.c \
sort_hard_coded.c sort_selection.c choose_sorting_stralegy.c sort_chunk_based.c sort_chunk_based_utils.c main.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

CC = cc
CFLAGS = -Wall -Wextra -Werror
OUT = push_swap

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap_lib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re