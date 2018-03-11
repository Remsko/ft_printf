# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 11:21:04 by rpinoit           #+#    #+#              #
#    Updated: 2018/03/11 11:46:36 by rpinoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_PATH = srcs
SRC_NAME = ft_printf.c
OBJ_PATH = obj
CPPFLAGS = -Iincs \
		   -Ilibft

LDFLAGS = -L./libft
LDLIBS = ./libft/libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: dir libs $(NAME)

libs:
	make -C libft

dir:
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ) $(LDLIBS)
	ar -rc $(NAME) $(OBJ) $(LDLIBS)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make -C libft clean
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: clean all
