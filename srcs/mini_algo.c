/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:10:56 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/01 20:27:56 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    mini_sort_3(t_arr *stack1)
{
        if (stack1->arr[1] < stack1->arr[0] && stack1->arr[0] < stack1->arr[2])
            swap(stack1);
        else if (stack1->arr[1] < stack1->arr[2] && stack1->arr[2] < stack1->arr[0])
            rotate(stack1);
        else if (stack1->arr[2] < stack1->arr[0] && stack1->arr[0] < stack1->arr[1])
            rrotate(stack1);
        else if (stack1->arr[2] < stack1->arr[1] && stack1->arr[1] < stack1->arr[0])
        {
            swap(stack1);
            rrotate(stack1);
        }
        else if (stack1->arr[0] < stack1->arr[2] && stack1->arr[2] < stack1->arr[1])
        {
            swap(stack1);
            rotate(stack1);
        }
}

void    mini_sort_5(t_arr *stack1, t_arr *stack2)
{
    int min;
    int i;

    i = 1;
    while (stack1->len && i)
    {
        if (is_sorted(stack1))
            i = 0;
        else
        {
            min = pick_min(stack1);
            grab_min(stack1, min);
            push(stack1, stack2);
        }
    }
    while (stack2->len)
        push(stack2, stack1);
}

int    pick_min(t_arr *stack)
{
    int cnt;
    int min;
    
    cnt = 0;
    min = stack->arr[0];
    while (cnt < stack->len)
    {
        if (stack->arr[cnt] < min)
        {
            min = stack->arr[cnt];
            stack->index_min = cnt;
        }
        cnt++;
    }
    return (min);
}

void    grab_min(t_arr *stack1, int min)
{
    int i;

    i = stack1->len / 2;
    while (stack1->arr[0] != min)
    {
        if (stack1->index_min <= i)
            rotate(stack1);
        else
            rrotate(stack1);
    }
}

int    is_sorted(t_arr *stack)
{
    int i;
    
    i = -1;
    while (++i + 1 < stack->len)
    {
        if (stack->arr[i] > stack->arr[i + 1])
            return (0);
    }
    return (1);
}
