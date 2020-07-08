# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 17:38:51 by qdang             #+#    #+#              #
#    Updated: 2020/05/28 17:51:24 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HED = libft.h

SRC = ft_memset.c ft_memalloc.c ft_bzero.c ft_strnew.c ft_strlen.c ft_strcmp.c \
	 	ft_strcpy.c ft_strncpy.c ft_nbrlen.c ft_putchar_fd.c ft_putchar.c \
		ft_putnchar.c ft_putstr_fd.c ft_putstr.c ft_putnbr_fd.c ft_putnbr.c \
		ft_strnbr.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(HED)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f libft.h.gch
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re