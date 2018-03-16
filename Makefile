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
		   srcs/ft_printf.c \
		   srcs/get_flag.c \
		   srcs/conv_integer.c \
		   srcs/fill_buff.c \
		   srcs/parser/parse_arg.c \
		   srcs/parser/get_flags.c \
		   srcs/parser/get_width.c \
		   srcs/parser/get_precision.c \
		   srcs/parser/get_length.c \
		   srcs/parser/get_specifier.c \

OBJ_NAME = libft/ft_putchar.o \
		   libft/ft_putnbr.o \
		   libft/ft_atoi.o \
		   libft/ft_bzero.o \
		   libft/ft_isdigit.o \
		   libft/ft_memset.o \
		   libft/ft_memcpy.o \
		   srcs/ft_printf.o \
		   srcs/conv_integer.o \
		   srcs/fill_buff.o \
		   srcs/parser/parse_arg.o \
		   srcs/parser/get_flags.o \
		   srcs/parser/get_width.o \
		   srcs/parser/get_precision.o \
		   srcs/parser/get_length.o \
		   srcs/parser/get_specifier.o \

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
