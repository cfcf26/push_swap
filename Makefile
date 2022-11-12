# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 21:10:54 by ekwak             #+#    #+#              #
#    Updated: 2022/11/12 19:22:00 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
DFLAGS = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
SRCS =  ./src/push_swap.a \
		./src/lib_push_swap.a

all : $(NAME)

$(SRCS) :
	make -C ./src all

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) push_swap.c $(SRCS)

debug :
	$(CC) $(CFLAGS) $(DFLAGS) -o $(NAME) push_swap.c $(SRCS)

clean :
	make -C ./src clean

fclean : clean
	make -C ./src fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re debug