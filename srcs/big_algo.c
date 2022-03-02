/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:09:41 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/02 16:47:56 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int    is_sorted_descend(t_arr *stack)
{
    int i;
    
    i = -1;
    while (++i + 1 < stack->len)
    {
        if (stack->arr[i] < stack->arr[i + 1])
            return (0);
    }
    return (1);
}


static int	part(int *array, int len)
{
	int		iinf;
	int		isup;
	int		tmp[len];
	int		i;

	iinf = 0;
	isup = len - 1;
	i = -1;
	while (++i < len - 1)
		if (array[i] > array[len - 1])
			tmp[isup--] = array[i];
		else
			tmp[iinf++] = array[i];
	tmp[iinf] = array[len - 1];
	i = -1;
	while (++i < len)
		array[i] = tmp[i];
	return (iinf);
}
 
void		reg_quick_sort(int *arr, int len)
{
	int		i;

	if (len < 2)
		return ;
	i = part(arr, len);
	if (i)
		reg_quick_sort(arr, i);
	if (i != len - 1)
		reg_quick_sort(arr + i + 1, len - i - 1);
}

void    quick_sort_a(t_arr *stack1, t_arr *stack2, int len)
{
    int med;
    int cnt1;
    int cnt2;
    
    if (is_sorted_descend(stack1))
        return;
    if (len <= 3)
    {
        mini_sort_3(stack1);
        return;
    }
    cnt1 = len;  
    cnt2 = 0;
    //mediane
    med = stack1->arr[len / 2];
    reg_quick_sort(stack1->arr, len);
    writestack(stack1);
    
    while (len != cnt1 / 2 + cnt1 % 2)
        if (stack1->arr[0] < med && len--)
            push(stack1, stack2);
        else if (++cnt2)
            rotate(stack2);
    while (cnt2--)
        rrotate(stack1);
    quick_sort_a(stack1, stack2, cnt1 / 2 + cnt1 % 2);
    quick_sort_b(stack1, stack2, cnt1 / 2);
}

