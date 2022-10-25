# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:57:01 by zakariyaham       #+#    #+#              #
#    Updated: 2022/10/25 19:13:24 by zakariyaham      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_PATH = ./srcs/
SRC = main.c
SRCS = $(addprefix ${SRC_PATH}, ${SRC})
		
OBJ_PATH	= obj/
OBJ = ${SRC:.c=.o}
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

DEPS = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

INC = -I./includes/

lib = -L./libs/libft -lft -L./libs/printf -lprintf -L./libs/minilibx-linux -lmlx -lXext -lX11 -lm -lz

FLAGS = -Wall -Werror -Wextra -MMD -MP -g3

${NAME} : ${OBJS}
	make -c ./libs/libft/
	make -c ./libs/printf/
	make -c ./libs/minilibx-linux/
	gcc ${FLAGS} $(OBJS) $(lib) -o ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	gcc ${FLAGS} ${INC} -o $@ -c $<
	
all : ${NAME}

clean :
	rm -rf ${OBJ_PATH}

fclean : clean
	rm -rf ${NAME}
	
re : fclean all

-include ${DEPS}

.SECONDARY : $(OBJS)

.PHONY: all clean fclean re