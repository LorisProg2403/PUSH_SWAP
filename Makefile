# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 08:24:40 by lgaume            #+#    #+#              #
#    Updated: 2023/11/30 11:48:18 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BONUS	=	checker

cc 		=	gcc
FLAGS	=	-Wall -Werror -Wextra -I
RM		=	rm -f


SRC_PATH		= 	src/
OBJ_PATH		= 	obj/
BONUS_PATH		=	bonus/
BONUS_OBJ_PATH	=	bonus_obj/
LIBFT			=	libft/libft.a
INC				=	inc/

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

BONUS_DIR		=	$(BONUS_PATH)checker.c \
					$(SRC_PATH)initialization/initialization.c \
					$(SRC_PATH)initialization/input_check.c \
					$(SRC_PATH)initialization/input_check_utils.c \
					$(SRC_PATH)initialization/stacks.c \
					$(SRC_PATH)Operations/push.c \
					$(SRC_PATH)Operations/reverse_rotate.c \
					$(SRC_PATH)Operations/rotate.c \
					$(SRC_PATH)Operations/swap.c \
					$(SRC_PATH)Utils/split.c \
					$(SRC_PATH)Utils/utils.c

SRCS			=	$(COST_DIR) $(INI_DIR) $(MOVE_DIR) $(OPERATIONS_DIR) $(SORT_DIR) $(UTILS_DIR) $(MAIN_DIR)
OBJS 			= 	$(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

SRCS_BONUS		=	$(BONUS_DIR)
OBJS_BONUS		= 	$(patsubst $(BONUS_PATH)%.c,$(BONUS_OBJ_PATH)%.o,$(SRCS_BONUS))

# Rules

all :						$(NAME)

both :						$(NAME) bonus

$(NAME): 					$(OBJS) $(LIBFT)
							@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

bonus:						$(OBJS_BONUS) $(LIBFT)
							@$(CC) $(FLAGS) $(INC) $(OBJS_BONUS) $(LIBFT) -o $(BONUS)

$(LIBFT):
							@make -C ./libft

$(OBJ_PATH)%.o:				$(SRC_PATH)%.c 
							@mkdir -p $(@D)
							@$(CC) $(FLAGS) $(INC) -c $< -o $@
				
$(BONUS_OBJ_PATH)%.o:		$(BONUS_PATH)%.c 
							@mkdir -p $(@D)
							@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
							@$(RM) -r $(OBJ_PATH)
							@$(RM) -r $(BONUS_OBJ_PATH)
							@make clean -C ./libft

fclean: 					clean
							@$(RM) $(NAME)
							@$(RM) $(BONUS)
							@make fclean -C ./libft
					
re: 						fclean all bonus

.PHONY: 					all clean fclean re bonus both
	