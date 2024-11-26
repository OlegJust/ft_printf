# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 02:08:37 by opidhorn          #+#    #+#              #
#    Updated: 2024/11/26 02:27:43 by opidhorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
RM = rm -rf
NAME = libftprintf.a

SRCS = ft_printf.c srcs/ft_utils.c srcs/ft_convert.c srcs/ft_handle_pointer.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re

.SILENT:
