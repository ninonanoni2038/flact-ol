NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx_mms_beta
MLX = $(MLX_DIR)/libmlx.dylib
FRAMEWORKS = -framework OpenGL -framework AppKit
RPATH = -Wl,-rpath,$(MLX_DIR)

SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(FRAMEWORKS) $(RPATH)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_DIR) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
