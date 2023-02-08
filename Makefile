# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 16:45:37 by sutku             #+#    #+#              #
#    Updated: 2023/02/08 09:50:24 by Cutku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

PS_SRC		=	error_control.c find_data.c find_index.c long_atoi.c linkedlist_utils.c push_swap.c \
				push.c rev_rotate.c rotate.c swap.c utils2.c ps_conditions.c algorithm.c
PS_OBJ		=	$(PS_SRC:.c=.o)

PS_MAIN		=	ps_main.c
PS_MAIN_OBJ	= 	$(PS_MAIN:.c=.o)

BONUS_SRC	=	push_swap_bonus/checker.c 
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

GNL_SRC		=	gnl/get_next_line_utils.c gnl/get_next_line.c
GNL_OBJ		=	$(GNL_SRC:.c=.o)

LIBFT		=	libft/
LIBFT_LIB	=	libft/libft.a

PRINTF		=	ftprintf/
PRINTF_LIB	=	ftprintf/libftprintf.a

CC		= 	gcc
RM		=   rm -f
CFLAGS	=	#-I. -Wall -Werror -Wextra

NAME	=	push_swap
NAME_B	=	checker

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;32m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:	$(NAME)

$(NAME): $(PS_OBJ) $(LIBFT_LIB) $(PRINTF_LIB) $(PS_MAIN_OBJ)
	$(CC) $(CFLAGS) $(PS_OBJ) $(LIBFT_LIB) $(PRINTF_LIB) $(PS_MAIN_OBJ) -o $(NAME)
	echo "Push_Swap compiled successfully"

$(NAME_B): $(BONUS_OBJ) $(PS_OBJ) $(GNL_OBJ) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(PS_OBJ) $(GNL_OBJ) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME_B)
	echo "Push_Swap_Bonus compiled successfully"

$(LIBFT_LIB):
	make bonus -C $(LIBFT) && make clean -C $(LIBFT)
	echo "$(GREEN)LIBFT compiled successfully"

$(PRINTF_LIB):
	make -C $(PRINTF) && make clean -C $(PRINTF)
	echo "Printf compiled successfully"

clean:
	$(RM) $(PS_OBJ) $(PS_MAIN_OBJ)
	$(RM) $(GNL_OBJ) $(BONUS_OBJ)
	$(RM) $(LIBFT_LIB) $(PRINTF_LIB)
	echo "$(MAGENTA)Object-Files are cleaned!"

fclean: clean
	$(RM) $(NAME) 
	$(RM) $(NAME_B)
	echo "$(MAGENTA)Programs / Libraries are cleaned!"

bonus: all $(NAME_B)
	
re: fclean all 

.PHONY: all clean fclean re