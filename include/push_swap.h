/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:00:31 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/14 13:42:36 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>

typedef struct s_arr
{
    int *arr;
    int len;
    int index_min;
    char who;
} t_arr;

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
void    mini_sort_5(t_arr *stack1, t_arr *stack2);
void    grab_min(t_arr *stack1, int min);
int     pick_min(t_arr *stack);
int     is_sorted(t_arr *stack);
// void    quick_sort_a(t_arr *stack1, t_arr *stack2, int len);
void    quick_sort_a(t_arr *stack1, t_arr *stack2, int len, int opt);
void    writestack(t_arr *stack_1);
void    mini_push_3(t_arr *stack1, t_arr *stack2, int len);
void    quick_sort_b(t_arr *stack1, t_arr *stack2, int len);
void		sort_3(t_arr *stack1, t_arr *stack2, int len);
void		push_sort_3(t_arr *stack1, t_arr *stack2 ,int len);
int     optimize_rotation(t_arr *stack, int len1, int len2);


