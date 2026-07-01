# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_PATH = ./src/
OBJ_PATH = ./bin/
HEADER = ./

# Source files and object files
SRCS =	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strndup.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_split.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_memmove.c\
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		

# List of bonus sourcs files
SRCSBONUS =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

# Adding the source path prefix to each source file
SRCS := $(addprefix $(SRC_PATH), $(SRCS))
SRCSBONUS := $(addprefix $(SRC_PATH), $(SRCSBONUS))

# Adding the object path prefix to each object file
OBJS := $(addprefix $(OBJ_PATH), $(notdir $(SRCS:.c=.o)))
OBJSBONUS := $(addprefix $(OBJ_PATH), $(notdir $(SRCSBONUS:.c=.o)))

# Default rule
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@ar rcs $@ $^

# Rules to add bonus to the lib
bonus: ${OBJS} ${OBJSBONUS}
	@ar -rcs ${NAME} ${OBJS} ${OBJSBONUS}

# Compile source files into object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ_PATH)

# Clean object files and library
fclean: clean
	rm -f $(NAME)

# Rebuild the library
re: fclean all

# Rules
.PHONY: all clean fclean re
