NAME = libftprintf.a

LIBFT_DIR = libft/
//LIBFT_NAME = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
RM = rm -rf

# Mandatory sources
SRC = 	ft_printf.c \
		ft_uitoa.c \
		ft_printf_hexadecimal.c \
		ft_printf_csdiu.c

OBJ = $(SRC:.c=.o)

# Default (mandatory)
all: compile_libft $(NAME)

compile_libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re compile_libft