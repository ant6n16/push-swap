# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 19:39:00 by antdelga          #+#    #+#              #
#    Updated: 2023/02/13 18:08:24 by antdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a

LIBFT_R = ./libft
LIBFT = ${LIBFT_R}/libft.a

SRCS	=	input_and_stacks.c \
			main.c \

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
	${CC} ${CFLAGS} push_swap.a main.c -o push_swap

clean:
	make clean -C ${LIBFT_R}
	rm -f ${OBJS} ${BONUS_OBJS}

fclean:	clean
	rm -f ${NAME}
	make fclean -C ${LIBFT_R}

re:	fclean all

.PHONY:	all clean fclean re libft
