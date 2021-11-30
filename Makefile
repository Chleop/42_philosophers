# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 13:58:56 by cproesch          #+#    #+#              #
#    Updated: 2021/11/30 11:05:39 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	sources/main.c sources/utils.c sources/init.c sources/close.c \
				sources/life.c sources/eat_sleep_think.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	philo

CC			=	gcc

IFLAGS		=	-I.

CFLAGS		=	-Wall -Wextra -Werror -pthread -D_REENTRANT -g $(IFLAGS) 

LFLAGS		=	-lpthread

RM			=	rm -rf

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

all:			$(NAME)

clean:	
				$(RM) $(OBJS) $(OBJS_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re