#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:49:09 by bcolossu          #+#    #+#              #
#    Updated: 2019/11/21 19:42:55 by rczarfun         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC =  ft_printf.c bzero_struct.c ft_int.c ft_output.c ft_analysis.c ft_char.c\
ft_unsigned_n.c modifers.c

OBJ = $(SRC:.c=.o)

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRCS=$(addprefix $(SRC_DIR)/,$(SRC))

OBJS=$(addprefix $(OBJ_DIR)/,$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rcs $@ $^
	@ranlib $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@


clean:
	@make clean -C libft
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
