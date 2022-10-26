# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:57:01 by zakariyaham       #+#    #+#              #
#    Updated: 2022/10/26 18:55:40 by zhamdouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_PATH = ./srcs/
SRC = ft_main.c
SRCS = $(addprefix ${SRC_PATH}, ${SRC})
		
OBJ_PATH	= obj/
OBJ = ${SRC:.c=.o}
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

DEPS = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

INC = -I./includes/so_long.h

LIBS = -L./libs/libft -lft -L./libs/printf -lprintf -L./libs/minilibx-linux -lmlx -lXext -lX11 -lm -lz

FLAGS = -Wall -Werror -Wextra -MMD -MP -g3

${NAME} : ${OBJS}
	make -C ./libs/libft/
	make -C ./libs/printf/
	make -C ./libs/minilibx-linux/
	gcc ${FLAGS} $(OBJS) $(LIBS) -o ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	gcc ${FLAGS} ${INC} -o $@ -c $<
	
all : ${NAME}

clean :
	make clean -C ./libs/libft/
	make clean -C ./libs/printf/
	make clean -C ./libs/minilibx-linux/
	rm -rf ${OBJ_PATH}

fclean : clean
	make fclean -C ./libs/libft/
	make fclean -C ./libs/printf/
	rm -rf ${NAME}
	
re : fclean all

-include ${DEPS}

.SECONDARY : $(OBJS)

.PHONY: all clean fclean re