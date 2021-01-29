# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 09:24:53 by lspazzin          #+#    #+#              #
#    Updated: 2021/01/29 13:27:23 by lspazzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  -*- Makefile -*-

SRCS		=	ft_printf.c

UTILS		=	ft_flags.c\
				ft_precision.c\
				ft_widht.c

LIBFT_FNCT	=	ft_bzero.c\
				ft_calloc.c\
				ft_isdigit.c\
				ft_itoa.c\
				ft_putchar_fd.c\
				ft_strlen.c

LIBFT_S		=	libft_fnct

UTILS_S		=	utils

FLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

NAME		=	libftprintf.a

RM			=	/bin/rm -f

OBJCS		=	$(SRCS:.c=.o)

LIBFT_OBJCS	=	$(LIBFT_FNCT:%.c=$(LIBFT_S)/%.o)

UTILS_OBJCS	=	$(UTILS:%.c=$(UTILS_S)/%.o)

#$(LIBFT_S)/%.o:	$(LIBFT_S)/%.c
#				$(CC) $(FLAGS) -c $<

#$(UTILS_S)/%.o:	$(UTILS_S)/%.c
#				$(CC) $(FLAGS) -c $<

#%.o:			%.c
#				$(CC) $(FLAGS) -c $<

$(NAME):		$(OBJCS) $(LIBFT_OBJCS) $(UTILS_OBJCS)
				ar -rc $(NAME) $(OBJCS) $(LIBFT_OBJCS) $(UTILS_OBJCS)
				ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJCS) $(LIBFT_OBJCS) $(UTILS_OBJCS)

karen:
				@ norminette *.c
				@ norminette *.h

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			clean all objects karen re fclean bonus
