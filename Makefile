# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharik <hharik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 14:16:29 by hharik            #+#    #+#              #
#    Updated: 2022/02/28 17:44:56 by hharik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
SRCS =	philo.c \
		ft_atoi.c \
		timestamp.c \
		check_is_dead.c \
		ft_exit.c \
		usleep_function.c \
		init.c \
		create_thread.c \
		ft_checking.c \

NAME = philo.a
	
OBJS = ${SRCS:.c=.o}
	
all : $(NAME)

$(NAME) : $(OBJS)
	ar crs $(NAME) $(OBJS)
	$(CC) $(CFLAGS) philo.c $(NAME)  -o philo

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME) philo
re : fclean all