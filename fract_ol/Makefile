NAME = fract_ol

SRC = fract_ol.c fract_ol_utils.c fract_ol_events.c ft_strnstr.c ft_atof.c main.c

OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux

LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c fract_ol.h minilibx-linux/mlx.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re