# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 09:24:53 by lspazzin          #+#    #+#              #
#    Updated: 2021/02/06 11:44:03 by lspazzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  -*- Makefile -*-

SRCS		=	ft_printf.c

UTILS		=	ft_flags.c\
				ft_precision.c\
				ft_widht.c\
				ft_discriminator.c\
				ft_start_up.c\
				ft_padding.c\
				ft_write_count.c

LIBFT_FNCT	=	ft_bzero.c\
				ft_calloc.c\
				ft_isdigit.c\
				ft_putchar_fd.c\
				ft_strlen.c\
				ft_itoa_base.c\
				ft_itoa_base_ptr.c

INDICATOR	=	ft_character.c\
				ft_string.c\
				ft_integer.c\
				ft_hexa.c\
				ft_ptr_address.c\
				ft_percent.c

LIBFT_S		=	libft_fnct

UTILS_S		=	utils

INDI_S		=	indicator

CCFLAG		=	-Wall -Wextra -Werror

CC			=	gcc

NAME		=	libftprintf.a

RM			=	/bin/rm -f

OBJCS		=	$(SRCS:.c=.o)

LIBFT_OBJCS	=	$(LIBFT_FNCT:%.c=$(LIBFT_S)/%.o)

UTILS_OBJCS	=	$(UTILS:%.c=$(UTILS_S)/%.o)

INDI_OBJCS	=	$(INDICATOR:%.c=$(INDI_S)/%.o)

#$(LIBFT_S)/%.o:	$(LIBFT_S)/%.c
#				$(CC) $(FLAGS) -c $<

#$(UTILS_S)/%.o:	$(UTILS_S)/%.c
#				$(CC) $(FLAGS) -c $<

#%.o:			%.c
#				$(CC) $(FLAGS) -c $<

$(NAME):		$(OBJCS) $(LIBFT_OBJCS) $(UTILS_OBJCS) $(INDI_OBJCS)
				ar -rc $(NAME) $(OBJCS) $(LIBFT_OBJCS) $(UTILS_OBJCS) $(INDI_OBJCS)
				ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJCS) $(LIBFT_OBJCS) $(UTILS_OBJCS) $(INDI_OBJCS)

karen:
				@ norminette *.c
				@ norminette *.h

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			clean all objects karen re fclean bonus
