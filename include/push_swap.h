/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:00:31 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/04 14:35:13 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>

# define BUFEER_SIZE 4096
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

void    rotate(t_arr *stack);
void    rrotate(t_arr *stack);
void    swap(t_arr *stack);
void    push(t_arr *stack1, t_arr *stack2);
void    init_stack1(t_arr *stack,int argc, char **argv);
void    init_stack2(t_arr *stack,int argc);
void    ss(t_arr *stack1, t_arr *stack2);
void    rr(t_arr *stack1, t_arr *stack2);
void    rrr(t_arr *stack1, t_arr *stack2);
void    free_function(t_arr *stack);
void    mini_sort_3(t_arr *stack1);
void	mini_sort_4(t_arr *stack1, t_arr *stack2);
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


