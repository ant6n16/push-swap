# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 19:39:00 by antdelga          #+#    #+#              #
#    Updated: 2023/02/24 21:31:06 by antdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./src/push_swap.a

LIBFT_R = ./libft
LIBFT = ${LIBFT_R}/libft.a

SRCS	=	./src/input_and_stacks.c \
			./src/stacks_utils.c \
			./src/main.c \
			./src/instructions.c \
			./src/instructions_rot_a.c \
			./src/instructions_rot_b.c \
			./src/bits_utils.c \
			./src/plot_bits_utils.c \
			./src/game_basic.c \
			./src/game_improved.c \
			

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=   -Wall -Wextra -Werror

.c.o:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${LIBFT_R}

all:	${LIBFT} ${NAME}

${LIBFT}:	${LIBFT_R}/*.c
	make -C ${LIBFT_R}

${NAME}:	${OBJS}
	cp ${LIBFT} ${NAME}
	ar crs ${NAME} ${OBJS}
	${CC} ${CFLAGS} ./src/push_swap.a ./src/main.c -o push_swap

clean:
	make clean -C ${LIBFT_R}
	rm -f ${OBJS} ${BONUS_OBJS}

fclean:	clean
	rm -f ${NAME}
	rm -f push_swap
	make fclean -C ${LIBFT_R}

re:	fclean all

.PHONY:	all clean fclean re libft
