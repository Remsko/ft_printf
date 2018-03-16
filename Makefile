NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_NAME = libft/ft_putchar.c \
		   libft/ft_putnbr.c \
		   libft/ft_atoi.c \
		   libft/ft_isdigit.c \
		   libft/ft_bzero.c \
		   libft/ft_memcpy.c \
		   libft/ft_memset.c \
		   srcs/parser/parse_arg.c \
		   srcs/parser/get_flags.c \
		   srcs/parser/get_width.c \
		   srcs/parser/get_precision.c \
		   srcs/parser/get_length.c \
		   srcs/parser/get_specifier.c \
		   srcs/conv/conv_integer.c \
		   srcs/ft_printf.c \
		   srcs/fill_buff.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

LDLIBS =

CPPFLAGS = -I./incs \
		   -I./libft \

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@ar -rc $(NAME) $(OBJ_NAME)
	@echo $(NAME) "\x1b[32m✔\x1b[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C libft
	@$(RM) $(OBJ_NAME)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean all
