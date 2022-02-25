/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:15:05 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/25 19:16:59 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    rotate(t_arr *stack)
{
    int tmp;
    int len;

    len = 0;
    tmp = stack->arr[0];
    while (len < stack->len - 1)
    {
        stack->arr[len] = stack->arr[len + 1];
        len++;
    }
    stack->arr[len] = tmp;
}

void    rrotate(t_arr *stack)
{
    int tmp;
    int len;

    len = stack->len - 1;
    tmp = stack->arr[len];
    while (len)
    {
        stack->arr[len] = stack->arr[len - 1];
        len--;
    }
    stack->arr[0] = tmp;
}

void    swap(t_arr *stack)
{
    int tmp;

    if (stack->len < 2)
        return (0);
    tmp = stack->arr[0];
    stack->arr[0] = stack->arr[1];
    stack->arr[1] = tmp;
}

void    push(t_arr *stack1, t_arr *stack2)
{
    int tmp;
    int len;
    
    if (!stack1->len)
        return (0);
    len = 0;
    tmp = stack1->arr[0];
    while (len < stack1->len - 1)
    {
        stack1->arr[len] = stack1->arr[len + 1];
        len++;
    }
    stack1->len--;
    len = stack2->len - 1;
    while (len)
    {
        stack2->arr[len] = stack2->arr[len - 1];
        len--;
    }
    stack2->arr[0] = tmp;
    stack2->len++;
}

void    ss(t_arr *stack1, t_arr *stack2)
{
    swap(stack1);
    swap(stack2);
}

void    rr(t_arr *stack1, t_arr *stack2)
{
    rotate(stack1);
    rotate(stack2);
}

void    rrr(t_arr *stack1, t_arr *stack2)
{
    rrotate(stack1);
    rrotate(stack2);
}