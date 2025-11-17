# Programın adı
NAME = fract_ol

# Sadece senin .c dosyaların
SRC = main.c
OBJS = $(SRC:.c=.o)

# Kütüphane yolları (KLASÖR yolları)
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

# Libft.a'nın tam yolu
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

# .h dosyalarının aranacağı KLASÖRLER
INCLUDES = -I./includes -I$(LIBFT_DIR) -I$(MLX_DIR)

# .a dosyalarının aranacağı KLASÖRLER
LIBS = -L$(LIBFT_DIR) -lft \
       -L$(MLX_DIR) -lmlx \
       -lXext -lX11 -lm

# Ana kural
all: $(NAME)

# $(NAME), $(LIBFT_A) ve $(OBJS)'e bağımlı
$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

# libft.a'yı derleme kuralı
$(LIBFT_A):
	make -C $(LIBFT_DIR)

# .o dosyalarını derleme kuralı
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Temizleme kuralları
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re