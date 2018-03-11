NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -c -Wall -Werror -Wextra
FILES = srcs/ft_printf.c
O_DIR = ft_printf.o
all: $(NAME)

$(NAME):
		make -C libft
		$(CC) $(CFLAGS) $(FILES)
		ar rc $(NAME) $(O_DIR)

clean:
		make -C libft clean
	    $(RM) $(O_DIR)

fclean: clean
		make -C libft fclean
	    $(RM) $(NAME)

re: fclean all
