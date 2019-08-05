# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yxie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 10:48:37 by yxie              #+#    #+#              #
#    Updated: 2019/07/15 12:29:09 by yxie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

FLAGS	= -Wall -Wextra -Werror -c

OBJ		= *.o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I includes/ libft/*.c ft_printf/*.c
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
