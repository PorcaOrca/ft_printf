# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 09:53:47 by lspazzin          #+#    #+#              #
#    Updated: 2021/01/28 15:31:55 by lspazzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  -*- Makefile -*-

SRCS		=	printf.c
				utils/ft_flags.c
				sources/ft_bzero.c

SRCS_BONUS	=	ft_lstadd_front.c \
				ft_lstadd_back.c \
				ft_lstmap.c \
				ft_lstclear.c \
				ft_lstlast.c \
				ft_lstiter.c \
				ft_lstdelone.c \
				ft_lstnew.c \
				ft_lstsize.c \

FLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

NAME		=	libft.a

RM			=	/bin/rm -f

OBJCS		=	$(SRCS:.c=.o)

OBJCS_BONUS	=	$(SRCS_BONUS:.c=.o)

%.o:			%.c
				$(CC) $(FLAGS) -c $<

$(NAME):		$(OBJCS)
				ar -rc $(NAME) $(OBJCS)
				ranlib $(NAME)

bonus:			$(NAME) $(OBJCS_BONUS)
				ar -rc $(NAME) $(OBJCS_BONUS)
				ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJCS) $(OBJCS_BONUS)

karen:
				@ norminette *.c
				@ norminette *.h

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			clean all objects karen re fclean bonus
