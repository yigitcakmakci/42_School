NAME = pipex

SRC = ft_split.c pipex_utils.c pipex.c libft.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

CC = cc
CFLAGS = -Wall -Wextra -Werror
OUT = pipex

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re