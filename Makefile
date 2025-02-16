NAME = fractol

# Source files
SRC = main.c string_utils.c init.c

# Minilibx path
MLX_DIR = minilibx_opengl_20191021
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Frameworks for macOS
FRAMEWORKS = -framework OpenGL -framework AppKit

# Object files
OBJ = $(SRC:.c=.o)

# Commands
RM = rm -f

# Compilation rules
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

# Build executable
$(NAME): $(OBJ)
	@make -C $(MLX_DIR)  # Compile Minilibx
	$(CC) $(OBJ) $(MLX_LIB) $(MLX_INC) $(FRAMEWORKS) -o $(NAME)

all: $(NAME)

clean:
	@make clean -C $(MLX_DIR)  # Clean Minilibx
	$(RM) $(OBJ)

fclean: clean
	@make clean -C $(MLX_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


# NAME = fractol
# MLX_DIR = minilibx_opengl_20191021
# SRC = $(wildcard $(MLX_DIR)/*.c) main.c
# CC = cc 
# CFLAGS = -Wall -Wextra -Werror
# OBJ = $(SRC:.c=.o)
# RM = rm -f

# %.o: %.c
# 	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

# $(NAME): $(OBJ)
# 	@make -C $(MLX_DIR)
# 	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -lm -lX11 -lXext -o $(NAME)

# all: $(NAME)

# clean:
# 	@make clean -C $(MLX_DIR)
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

# cc main.c minilibx_opengl_20191021/libmlx.a -Iminilibx_opengl_20191021 -framework OpenGL -framework AppKit -o fractol
