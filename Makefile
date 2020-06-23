# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 08:09:21 by aahizi-e          #+#    #+#              #
#    Updated: 2019/11/28 01:43:48 by aahizi-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -O2 -Wall -Wextra

SRCS =	ft_arg_sxp.c\
		ft_arg.c\
		ft_control_spec_cs.c\
		ft_control_spec_dou.c\
		ft_control_spec_xp.c\
		ft_control.c\
		ft_diou_spec.c\
		ft_csxp_spec.c\
		ft_flags.c\
		ft_init.c\
		ft_libft_function.c\
		ft_number.c\
		ft_printf.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	@gcc $(CFLAGS) -c $(SRCS)
	@ar rcs $@ $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

PHONY: $(NAME) all clean fclean re libft
