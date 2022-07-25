# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:09:53 by hyna              #+#    #+#              #
#    Updated: 2022/07/17 20:04:59 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CCFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
INC_LINK = -I./inc
LIBS = -L./lib/libft -lft\

SRCS_NAME = main.c\
			stack_utils.c\
			init_stack_a.c\
			is_in_order.c\
			handle_three_elements.c\
			handle_five_elements.c\
			rules_util.c\
			rules_swap.c\
			rules_push.c\
			rules_rotate.c\
			rules_rrotate.c\
			rules_print.c\
			sorting_processor.c\
			get_idx.c\
			algo_divide.c\
			algo_get_chunks.c\
			algo_push_back_to_a.c\
			etc_free_all.c\
			

SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

all : $(NAME)

$(NAME) : $(OBJS) 
	@$(MAKE) -C ./lib/libft all
	$(CC) $(CCFLAGS) $(LIBS) -o $(NAME) $(OBJS)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(INC_LINK) $(CCFLAGS) -c $< -o $@

clean :
	@$(MAKE) -C ./lib/libft clean
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf ./lib/libft/libft.a
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean
