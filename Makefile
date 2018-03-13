NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_NAME = srcs/ft_printf.c \
		srcs/parser/parse_arg.c \
		srcs/parser/get_specifier.c \
		srcs/printer/print_signed_integer.c \

OBJ_NAME = ft_printf.o \
		parse_arg.o \
		get_specifier.o \
		print_signed_integer.o \

LDLIBS = ./libft/libft.a

CPPFLAGS = -I./incs/ \
		   -I./libft/ \

all: $(NAME)

$(NAME): $(OBJ_NAME)
		make -C libft
		ar -rc $(NAME) $(OBJ_NAME) $(O_DIR) $(LDLIBS)

%.o: %.c
	    $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
		make -C libft clean
	    $(RM) $(OBJ_NAME)

fclean: clean
		make -C libft fclean
	    $(RM) $(NAME)

re: fclean all
	make -C libft re