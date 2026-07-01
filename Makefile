# this is to manage flags for m1 architecture, we don't have to use this flag in linux
OS_ARCH 	:= $(shell uname -m)
ifeq ($(OS_ARCH),arm64)
	MLX_DIR := ./include/minilibx_macos/
	MLX_LIB := -lmlx -framework OpenGL -framework AppKit
	OS_NAME := Mac M1
else
	MLX_DIR := ./include/minilibx-linux/
	MLX_LIB := -lmlx -lXext -lX11
	OS_NAME := Linux
endif

# Executable name
NAME = fdf

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./include/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

# Source files for fdf
SRCS = main.c \
		ft_atoi_base.c \
		clear_list_tab.c \
		find_point.c \
		color_gradient.c \
		process_data.c \
		parsing.c \
		bresenham.c \
		projection.c \
		rotate_around_center.c \
		isometric_small_map.c \
		isometric_big_map.c \
		draw.c \
		apply_controls_operations.c \
		apply_controls.c \
		key_press_1.c \
		key_press_2.c \
		key_release.c \
		mouse_event.c \
		utils.c \
		fdf.c \

# Object files with path prefix
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Include directories
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Default rule
all: $(NAME)

# Create the fdf program
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) $(MLX_LIB) -lm -o $(NAME)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Ensure the object directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build the library (libft)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build the minilibx library
$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

# Rebuild the library and the main program
re: fclean all

# Phony targets
.PHONY: all clean fclean re
