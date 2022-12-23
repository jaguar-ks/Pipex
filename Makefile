# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 19:50:24 by deman_wolf        #+#    #+#              #
#    Updated: 2022/12/23 20:23:32 by deman_wolf       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MD = src/main.c\
	utl/utils.c\

BN = bns/main.c\
	utl/get_next_line.c\
	utl/get_next_line_utils.c\
	utl/utils.c\

OBJ_MD = ${MD:.c=.o}

OBJ_BN = ${BN:.c=.o}

FLAGS = -Wall -Wextra -Werror

INC = inc/pipex.h

RM = rm -rf

NAME = pipex

NAME_BN = pipex_bn

all: ${NAME}

${NAME}: ${OBJ_MD}
	make -C libtool
	cc ${FLAGS} $^ libtool/libft.a -o $@

bonus: ${NAME_BN}

${NAME_BN}: ${OBJ_BN}
	make -C libtool 
	cc ${FLAGS} $^ libtool/libft.a -o $@

%.o: %.c ${INC}
	@cc ${FLAGS} -c $< -o $@

clean:
	${RM} src/*.o bns/*.o utl/*.o libtool/*.o

fclean: clean
	${RM} ${NAME} ${NAME_BN} libtool/libft.a

re: fclean all

.PHONY: all bonus clean fclean re

.SILENT: ${NAME} ${NAME_BN} clean fclean re