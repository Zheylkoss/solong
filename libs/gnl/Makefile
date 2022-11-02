# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:29:25 by zhamdouc          #+#    #+#              #
#    Updated: 2022/06/16 19:51:38 by zhamdouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line_utils.c \
	get_next_line.c \
	
OBJ = ${SRC:.c=.o}

COMPIL = gcc -Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJ}
	ar rc ${NAME} ${OBJ}

%.o : %.c 
	${COMPIL} -o $@ -c $<

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re :fclean	all