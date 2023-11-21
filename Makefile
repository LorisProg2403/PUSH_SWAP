# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 08:24:40 by lgaume            #+#    #+#              #
#    Updated: 2023/11/21 15:09:29 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

cc 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I $(INC)
RM		=	rm -f


SRC_PATH	= 	src/
OBJ_PATH	= 	obj/
LIBFT		=	libft/libft.a
INC			=	inc/

# Source files
COST_DIR		=	$(SRC_PATH)cost/cost.c

INI_DIR			=	$(SRC_PATH)Initialization/initialization.c \
					$(SRC_PATH)Initialization/input_check_utils.c \
					$(SRC_PATH)Initialization/input_check.c \
					$(SRC_PATH)Initialization/stacks.c

MOVE_DIR		=	$(SRC_PATH)move/do_move.c \
					$(SRC_PATH)move/position.c

OPERATIONS_DIR	=	$(SRC_PATH)Operations/push.c \
					$(SRC_PATH)Operations/reverse_rotate.c \
					$(SRC_PATH)Operations/rotate.c \
					$(SRC_PATH)Operations/swap.c

SORT_DIR		=	$(SRC_PATH)Sorting_algo/sort_tiny.c \
					$(SRC_PATH)Sorting_algo/sort.c

UTILS_DIR		=	$(SRC_PATH)utils/split.c \
					$(SRC_PATH)utils/utils.c

MAIN_DIR		=	$(SRC_PATH)main.c


SRCS			=	$(COST_DIR) $(INI_DIR) $(MOVE_DIR) $(OPERATIONS_DIR) $(SORT_DIR) $(UTILS_DIR) $(MAIN_DIR)

OBJS 			= 	$(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

# Rules

all :				$(NAME)

$(NAME): 			$(OBJS) $(LIBFT)
					@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
					@make -C ./libft

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_PATH)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@make fclean -C ./libft
					
re: 				fclean all

.PHONY: 			all clean fclean re
