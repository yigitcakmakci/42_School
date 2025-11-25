NAME = fractol

SRC = fractol.c fractol_utils.c fractol_events.c ft_strncmp.c ft_atof.c main.c

OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux

LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c fractol.h minilibx-linux/mlx.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re