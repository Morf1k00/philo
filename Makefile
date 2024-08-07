# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 13:57:56 by rkrechun          #+#    #+#              #
#    Updated: 2024/07/31 14:08:16 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosophers
CC		= gcc #-g -fsanitize=address
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

HEADER	= philosophers.h

M_PATH	= philosophers.c\
			ft_atoi.c\
			parse_file.c\
			utils.c\
			routine.c\
			checker.c


OBJ_M	= $(M_PATH:.c=.o)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_M)
	@$(CC) $(FLAGS) $(OBJ_M) -o $(NAME)

all:	$(NAME)

clean:
	@$(RM) $(OBJ_M)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 