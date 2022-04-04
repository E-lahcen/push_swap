/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:10:56 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/04 14:37:12 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    mini_sort_3(t_arr *stack1)
{
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
