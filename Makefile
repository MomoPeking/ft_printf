# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 18:03:37 by qdang             #+#    #+#              #
#    Updated: 2020/07/06 21:00:31 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c deal_input.c deal_c.c deal_p.c deal_s.c deal_u.c deal_x.c \
		deal_di.c deal_di_2.c nbr_put.c nbr_trans.c 
SOURCE_B = deal_input_bonus.c deal_f_bonus.c output_bonus.c

LIB_PATH = ./libft

HED = ./include/ft_printf.h

SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/,$(SOURCE))
SRC_B = $(addprefix $(SRC_PATH)/,$(SOURCE_B))

OBJ = $(SOURCE:.c=.o)
OBJ_B = $(SOURCE_B:.c=.o)

$(NAME):
	@sed -i "" "s|BONUS		1|BONUS		0|" ./include/ft_printf.h
	@make re -C $(LIB_PATH)
	@gcc $(FLAGS) -c $(SRC) -I $(HED)
	@ar rcs $(NAME) $(OBJ) $(LIB_PATH)/*.o

all: $(NAME)

clean: 
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all

bonus:
	@sed -i "" "s|BONUS		0|BONUS		1|" ./include/ft_printf.h
	@make re -C $(LIB_PATH)
	@gcc $(FLAGS) -c $(SRC) $(SRC_B) -I $(HED)
	@ar rcs $(NAME) $(OBJ) $(OBJ_B) $(LIB_PATH)/*.o

test:
	@gcc main.c $(NAME)

.PHONY: all clean fclean re bonus test
