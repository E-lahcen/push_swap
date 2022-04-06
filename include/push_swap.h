/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:00:31 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/05 15:51:42 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../include/libft/libft.h"
#include <stdio.h>

# define BUFEER_SIZE 4096
# define N1(a) (a == '1' || a == '2' || a == '3' || a == '4' || a == '5')
# define N2(a) (a == '6' || a == '7' || a == '8' || a == '9' || a == '0')
# define NUM(a) (N1(a) || N2(a))

typedef struct s_arr
{
    int *arr;
    int len;
    int index_min;
    char who;
} t_arr;

typedef struct s_instructions
{
    char **arr;
    int len;
} t_instructions;

void    rotate(t_arr *stack, int print);
void    rrotate(t_arr *stack, int print);
void    swap(t_arr *stack, int print);
void    push(t_arr *stack1, t_arr *stack2, int print);
void    init_stack1(t_arr *stack,int argc, char **argv);
void    init_stack2(t_arr *stack,int argc);
void    ss(t_arr *stack1, t_arr *stack2, int print);
void    rr(t_arr *stack1, t_arr *stack2, int print);
void    rrr(t_arr *stack1, t_arr *stack2, int print);
void    free_function(t_arr *stack);
void    mini_sort_3(t_arr *stack1);
void    grab_min(t_arr *stack1, int min);
int     pick_min(t_arr *stack);
int     is_sorted(t_arr *stack);
void    quick_sort_a(t_arr *stack1, t_arr *stack2, int len);
void    writestack(t_arr *stack_1);
void    quick_sort_b(t_arr *stack1, t_arr *stack2, int len);
void	sort_3(t_arr *stack1, t_arr *stack2, int len);
void	push_sort_3(t_arr *stack1, t_arr *stack2 ,int len);
void    free_inst(t_instructions *inst);
void	quick_sort_it(int *arr, int len);


