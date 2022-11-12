# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 01:44:30 by ekwak             #+#    #+#              #
#    Updated: 2022/11/09 20:51:08 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = lib_push_swap.a
NAME2 = push_swap.a
AR = ar
ARFLAGS = -crs
RM = rm
RMFLAGS = -f
SRCS =  instructions.c \
		instructions2.c \
		instructions3.c \
		lib_push_swap.c \
		lib_push_swap2.c \
		ft_err.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_itoa_f.c \
		ft_print_cs.c \
		ft_strlen.c \
		ft_strdup.c \
		lib_push_swap3.c \
		
SRCS2 = set_stack.c \
		sort_b.c \
		sort.c \
		small_sort.c \
		
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

$(NAME)	: $(OBJS)
				$(CC) $(CFLAGS) -c $(SRCS) $(SRCS2) -I./
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(NAME2)	: $(OBJS2)
				$(CC) $(CFLAGS) -c $(SRCS2) -I./
				$(AR) $(ARFLAGS) $(NAME2) $(OBJS2)

all : $(NAME) $(NAME2)

clean :
				$(RM) $(RMFLAGS) $(OBJS) $(OBJS2)

fclean : clean
				$(RM) $(RMFLAGS) $(NAME) $(NAME2)

re : fclean all

.PHONY : all clean fclean re bonus
