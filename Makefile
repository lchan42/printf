# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 20:57:58 by lchan             #+#    #+#              #
#    Updated: 2022/01/14 17:57:25 by lchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c

NAME		= libftprintf.a

INC			= ft_printf.h

OBJS		= ${SRCS:.c=.o}

OBJSBONUS	= ${SRCSBONUS:.c=.o}

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

AR			= ar

ARFLAGS		= rcs

RAN			= ranlib

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS} ${INC}

bonus:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

cleanb:		clean
			${RM} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		re clean fclean all bonus
