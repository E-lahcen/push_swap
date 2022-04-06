# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 14:38:34 by lelhlami          #+#    #+#              #
#    Updated: 2022/04/06 15:34:33 by lelhlami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNS = checker

SRC_PATH  = srcs

OBJ_PATH  = objs

LIBFT_SRC = include/libft

SOURCES = 	main.c \
			init.c \
			utils.c \
			big_algo.c \
			actions.c \
			actions2.c \
			mini_algo.c
			
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
	@echo "$(GREEN)Creating libft files$(CYAN)"
	@make -C $(LIBFT_SRC)
	
$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(LIBFT_SRC)/libft.a $(OBJS) -o $@ 
	@echo "$(GREEN)Project successfully compiled"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c include/$(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

tmp:
	@mkdir -p objs
	
%.o : %.c
	@$(CC) $(FLAGS) -c $<

bonus: all
	$(CC) $(FLAGS) bonus/main.c include/get_next_line/*.c srcs/actions.c  srcs/actions2.c \
	srcs/big_algo.c srcs/init.c srcs/mini_algo.c include/libft/ft_strncmp.c \
	include/libft/ft_atoi.c srcs/utils.c -o $(BNS)

clean:
	@echo "$(VIOLET)Deleting Libft library files$(CYAN)"
	@make clean -C $(LIBFT_SRC)
	@echo "$(VIOLET)Deleting push_swap library files$(CYAN)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNS)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LIBFT_SRC)

re: fclean all

.PHONY: tmp, re, fclean, clean, bonus, lib, all