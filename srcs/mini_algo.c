/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:10:56 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/16 14:56:24 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    mini_sort_3(t_arr *stack1)
{
    // if (stack1->arr[1] < stack1->arr[0] && stack1->arr[0] < stack1->arr[2])
    //     swap(stack1);
    // else if (stack1->arr[1] < stack1->arr[2] && stack1->arr[2] < stack1->arr[0])
    //     rotate(stack1);
    // else if (stack1->arr[2] < stack1->arr[0] && stack1->arr[0] < stack1->arr[1])
    //     rrotate(stack1);
    // else if (stack1->arr[2] < stack1->arr[1] && stack1->arr[1] < stack1->arr[0])
    // {
    //     swap(stack1);
    //     rrotate(stack1);
    // }
    // else if (stack1->arr[0] < stack1->arr[2] && stack1->arr[2] < stack1->arr[1])
    // {
    //     swap(stack1);
    //     rotate(stack1);
    // }
    if (stack1->arr[0] > stack1->arr[1] && stack1->arr[0] > stack1->arr[2])
        rotate(stack1);
    else if (stack1->arr[1] > stack1->arr[0] && stack1->arr[1] > stack1->arr[2])
        rrotate(stack1);
    if (!is_sorted(stack1))
        swap(stack1);
}

void		sort_3(t_arr *stack1, t_arr *stack2, int len)
{
	if (len == 3 && stack1->len == 3)
		mini_sort_3(stack1);
	else if (len == 2)
	{
		if (stack1->arr[0] > stack1->arr[1])
			swap(stack1);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack1->arr[0] < stack1->arr[1]
					&& stack1->arr[1] < stack1->arr[2]))
			if (len == 3 && stack1->arr[0] > stack1->arr[1] && stack1->arr[2])
                swap(stack1);
			else if (len == 3 && !(stack1->arr[2] > stack1->arr[0]
						&& stack1->arr[2] > stack1->arr[1]))
			{
                push(stack1, stack2);
				len--;
			}
			else if (stack1->arr[0] > stack1->arr[1])
                swap(stack1);
			else if (len++)
                push(stack2, stack1);
	}
}

void    mini_push_3(t_arr *stack1, t_arr *stack2, int len)
{
    while (len)
    {
        push(stack2, stack1);
        len--;
    }
    sort_3(stack1, stack2, len);
}

void		push_sort_3(t_arr *stack1, t_arr *stack2 ,int len)
{
	if (len == 1)
		push(stack2, stack1);
	else if (len == 2)
	{
		if (stack2->arr[0] < stack2->arr[1])
			swap(stack2);
		push(stack2, stack1);
		push(stack2, stack1);
	}
	else if (len == 3)
	{
		while (len)
			if (len == 1 && stack1->arr[0] > stack1->arr[1])
				swap(stack1);
			else if (len == 1 || (len >= 2 && stack2->arr[0] > stack2->arr[1])
					|| (len == 3 && stack2->arr[0] > stack2->arr[2]))
			{
                push(stack2, stack1);
				len--;
			}
			else
                swap(stack2);
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
    while (++i < stack->len - 1)
    {
        if (stack->arr[i] > stack->arr[i + 1])
            return (0);
    }
    return (1);
}
