/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:00:31 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/07 09:21:10 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../include/libft/libft.h"
# include <stdio.h>

# define BUFEER_SIZE 4096

typedef struct s_arr
{
	int		*arr;
	int		len;
	char	who;
}	t_arr;

void	rotate(t_arr *stack, int print);
void	rrotate(t_arr *stack, int print);
void	swap(t_arr *stack, int print);
void	push(t_arr *stack1, t_arr *stack2, int print);
void	init_stack1(t_arr *stack, int argc, char **argv);
void	init_stack2(t_arr *stack, int argc);
void	ss(t_arr *stack1, t_arr *stack2);
void	rr(t_arr *stack1, t_arr *stack2);
void	rrr(t_arr *stack1, t_arr *stack2);
void	free_function(t_arr *stack);
void	mini_sort_3(t_arr *stack1);
void	grab_min(t_arr *stack1, int min);
int		pick_min(t_arr *stack);
int		is_sorted(t_arr *stack);
void	quick_sort_a(t_arr *stack1, t_arr *stack2, int len);
void	writestack(t_arr *stack_1);
void	quick_sort_b(t_arr *stack1, t_arr *stack2, int len);
void	sort_3(t_arr *stack1, t_arr *stack2, int len);
void	push_sort_3(t_arr *stack1, t_arr *stack2, int len);
void	quick_sort_it(int *arr, int len);
int		is_sorted_descend(t_arr *stack);
int		check_int_limits(char *str);
int		check_argv(char *argv);
void	check_doubles(t_arr *stack1);

#endif