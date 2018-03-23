NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_NAME = libft/ft_intmax.c \
		   libft/ft_nblen.c \
		   libft/ft_unblen.c \
		   libft/ft_putchar.c \
		   libft/ft_atoi.c \
		   libft/ft_isdigit.c \
		   libft/ft_bzero.c \
		   libft/ft_memcpy.c \
		   libft/ft_memset.c \
		   libft/ft_strlen.c \
		   srcs/parser/parse_arg.c \
		   srcs/parser/get_flags.c \
		   srcs/parser/get_width.c \
		   srcs/parser/get_precision.c \
		   srcs/parser/get_length.c \
		   srcs/parser/get_specifier.c \
		   srcs/conv/conv_nb.c \
		   srcs/conv/conv_unsigned_nb.c \
		   srcs/conv/conv_str.c \
		   srcs/conv/conv_char.c \
		   srcs/conv/conv_ptr.c \
		   srcs/conv/conv_pourcent.c \
		   srcs/buffer/fill_buff.c \
		   srcs/buffer/add_char.c \
		   srcs/cast/chose_cast_nb.c \
		   srcs/cast/chose_cast_unsigned_nb.c \
		   srcs/ft_printf.c \

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
