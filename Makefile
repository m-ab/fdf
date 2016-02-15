# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/12 02:53:45 by maboukra          #+#    #+#              #
#    Updated: 2016/02/12 02:55:05 by maboukra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJDIR = ./obj/
SRCDIR = ./src/
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c parse.c init.c draw.c color.c display.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = -Ilibft/ -Iinclude
SRC = $(addprefix $(SRCDIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJDIR), $(OBJ_NAME))

all: depend $(NAME)

$(NAME): $(OBJ) libft/libft.a
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft -lmlx -framework OpenGL -framework AppKit

$(OBJDIR)%.o : $(SRCDIR)%.c
		mkdir $(OBJDIR) 2> /dev/null || true
		$(CC) $(CFLAGS) $(INC_NAME) -o $@ -c $<

depend:
	make -C libft

clean:
		make clean -C libft
		rm -rf $(OBJ)

fclean: clean
		@make fclean -C libft
		rm -rf $(NAME)
		rm -rf $(OBJDIR)

re: fclean all

.PHONY: clean fclean re all
