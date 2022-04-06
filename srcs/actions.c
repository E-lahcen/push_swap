/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:15:05 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/05 15:01:29 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    rotate(t_arr *stack, int print)
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
    if (stack->who == 'A' && print)
        write(1, "ra\n", 3);
    else if (print)
        write(1, "rb\n", 3);
}

void    rrotate(t_arr *stack, int print)
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
    if (stack->who == 'A' && print)
        write(1, "rra\n", 4);
    else if (print)
        write(1, "rrb\n", 4);
}

void    swap(t_arr *stack, int print)
{
    int tmp;

    if (stack->len < 2)
        return;
    tmp = stack->arr[0];
    stack->arr[0] = stack->arr[1];
    stack->arr[1] = tmp;
    if (stack->who == 'A' && print)
        write(1, "sa\n", 3);
    else if (print)
        write(1, "sb\n", 3);
}

void    push(t_arr *stack1, t_arr *stack2, int print)
{
    int tmp;
    int len;
    
    if (!stack1->len)
        return;
    len = 0;
    tmp = stack1->arr[0];
    while (len < stack1->len - 1)
    {
        stack1->arr[len] = stack1->arr[len + 1];
        len++;
    }
    stack1->len--;
    if (!stack2->len)
        len = stack1->len - 1;
    else
        len = stack2->len;
    while (len)
    {
        stack2->arr[len] = stack2->arr[len - 1];
        len--;
    }
    stack2->arr[0] = tmp;
    stack2->len++;
    if (stack1->who == 'A' && print)
        write(1, "pb\n", 3);
    else if (print)
        write(1, "pa\n", 3);
}

void    ss(t_arr *stack1, t_arr *stack2, int print)
{
    swap(stack1, print);
    swap(stack2, print);
}

void    rr(t_arr *stack1, t_arr *stack2, int print)
{
    rotate(stack1, print);
    rotate(stack2, print);
}

void    rrr(t_arr *stack1, t_arr *stack2, int print)
{
    rrotate(stack1, print);
    rrotate(stack2, print);
}