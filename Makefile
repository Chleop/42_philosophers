# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 13:58:56 by cproesch          #+#    #+#              #
#    Updated: 2021/12/02 13:09:05 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	sources/main.c sources/utils.c sources/time.c sources/close.c \
				sources/philo.c sources/eat_sleep_think.c sources/mutex.c 

OBJS		=	$(SRCS:.c=.o)

NAME		=	philo

CC			=	gcc

IFLAGS		=	-I.

CFLAGS		=	-Wall -Wextra -Werror -pthread $(IFLAGS) 

LFLAGS		=	-lpthread

RM			=	rm -rf

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(LFLAGS) $(CFLAGS) -o $(NAME)

all:			$(NAME)

clean:	
				$(RM) $(OBJS) $(OBJS_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
