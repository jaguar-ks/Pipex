# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 19:50:24 by deman_wolf        #+#    #+#              #
#    Updated: 2022/12/25 22:40:29 by faksouss         ###   ########.fr        #
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
	@echo "\033[33m----Compiling lib----"
	make -C libtool
	cc ${FLAGS} $^ libtool/libft.a -o $@
	@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"


bonus: ${NAME_BN}

${NAME_BN}: ${OBJ_BN}
	@echo "\033[33m----Compiling lib----"
	make -C libtool 
	cc ${FLAGS} $^ libtool/libft.a -o $@
	@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

%.o: %.c ${INC}
	@cc ${FLAGS} -c $< -o $@

clean:
	${RM} src/*.o bns/*.o utl/*.o libtool/*.o

fclean: clean
	${RM} ${NAME} ${NAME_BN} libtool/libft.a
	echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re: fclean all

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all bonus clean fclean re

.SILENT: ${NAME} ${NAME_BN} clean fclean re party