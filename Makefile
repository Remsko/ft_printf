NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_NAME = libft/ft_putchar.c \
		   libft/ft_putnbr.c \
		   libft/ft_isdigit.c \
		   srcs/ft_printf.c \
		   srcs/parser/parse_arg.c \
		   srcs/parser/get_specifier.c \
		   srcs/parser/get_flag.c \
		   srcs/printer/print_signed_integer.c \

OBJ_NAME = libft/ft_putchar.o \
		   libft/ft_putnbr.o \
		   libft/ft_isdigit.o \
		   srcs/ft_printf.o \
		   srcs/parser/parse_arg.o \
		   srcs/parser/get_specifier.o \
		   srcs/parser/get_flag.o \
		   srcs/printer/print_signed_integer.o \

LDLIBS =

CPPFLAGS = -I./incs \
		   -I./libft \

all: $(NAME)

$(NAME): $(OBJ_NAME)
	ar -rc $(NAME) $(OBJ_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft
	$(RM) $(OBJ_NAME)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all
