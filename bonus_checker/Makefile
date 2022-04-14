# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 14:38:34 by lelhlami          #+#    #+#              #
#    Updated: 2022/04/13 12:30:26 by lelhlami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC_PATH  = srcs_bonus

OBJ_PATH  = objs

LIBFT_SRC = include_bonus/libft

SOURCES = 	main_bonus.c \
			init_bonus.c \
			utils_bonus.c \
			utils2_bonus.c \
			big_algo_bonus.c \
			actions_bonus.c \
			actions2_bonus.c \
			mini_algo_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c
			
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))

OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all : lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating bonus libft files$(CYAN)"
	@make -C $(LIBFT_SRC)
	
$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(LIBFT_SRC)/libft.a $(OBJS) -o $@ 
	@echo "$(GREEN)Project successfully compiled"
	@cp checker ..

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c include_bonus/$(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating bonus object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

tmp:
	@mkdir -p objs
	
%.o : %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@echo "$(VIOLET)Deleting Libft library files$(CYAN)"
	@make clean -C $(LIBFT_SRC)
	@echo "$(VIOLET)Deleting bonus push_swap library files$(CYAN)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LIBFT_SRC)

re: fclean all

.PHONY: tmp, re, fclean, clean, lib, all