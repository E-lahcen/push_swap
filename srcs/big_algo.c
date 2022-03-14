/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:09:41 by lelhlami          #+#    #+#             */
/*   Updated: 2022/03/14 22:36:23 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int    is_sorted_descend(t_arr *stack)
{
    int i;
    
    i = -1;
    while (++i < stack->len - 1)
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
 
void		quick_sort_it(int *arr, int len)
{
	int		i;

	if (len < 2)
		return ;
	i = part(arr, len);
	if (i)
		quick_sort_it(arr, i);
	if (i != len - 1)
		quick_sort_it(arr + i + 1, len - i - 1);
}

int mediane(int *arr, int stack_len, int current_len, int opt)
{
    int tmp[current_len];
    int i ,j;

    i = -1;
    while (++i < current_len - opt)
        tmp[current_len - opt -1 - i] = arr[i];
    j = -1;
    while (++j < opt)
        tmp[i++] = arr[stack_len - j - 1];
    quick_sort_it(tmp, current_len);
    return (tmp[(current_len) / 2]);
}

int     optimize_rotation(t_arr *stack, int len1, int len2)
{
    int tmp[len1];
    int i, j;
    int opt = 0;
    int med;
    i = -1;
    j = -1;
    if (len1 < 4)
        return 0;
    if (!len2)
        return (0);
    while (++i < len1 - len2)
        tmp[len1 - len2 - 1 - i] = stack->arr[i];
    while (++j < len2)
        tmp[i++] = stack->arr[stack->len - (j + 1)];
    i = -1;
    med = mediane(tmp, stack->len, len1, 0);
    printf("sub_med = %d\n",med);
    i = -1;
    while (++i < len1)
        if (tmp[len1 - (i + 1)] < med)
            return opt;
        else
            opt++;
    return opt;
}

void    quick_sort_a(t_arr *stack1, t_arr *stack2, int len, int opt)
{
    int med;
    int cnt1;
    int cnt2;
    int n_r;
    int i = -1;

    if (is_sorted(stack1))
        return;
    if (len <= 3)
    {
        sort_3(stack1, stack2, len);
        return;
    }
    cnt1 = len;  
    cnt2 = 0;
    med = mediane(stack1->arr, stack1->len, len, opt);
    printf("med = %d\n", med);
    while (len != cnt1 / 2 + cnt1 % 2)
        if (stack1->arr[0] < med && len--)
            push(stack1, stack2);
        else if (++cnt2)
            rotate(stack1);
    opt = optimize_rotation(stack1, cnt1 / 2 + cnt1 % 2, cnt2);
    printf("len1 = %d | len2 = %d | opt = %d\n", cnt1 / 2 + cnt1 % 2, cnt2, opt);
    // cnt2 = abs(cnt2 - opt);
    while (cnt1 / 2 + cnt1 % 2 != stack1->len && cnt2--)
        rrotate(stack1);
    quick_sort_a(stack1, stack2, cnt1 / 2 + cnt1 % 2, 0);
    quick_sort_b(stack1, stack2, cnt1 / 2);
}

void    quick_sort_b(t_arr *stack1, t_arr *stack2, int len)
{
    int med;
    int cnt1;
    int cnt2;
    
    if (is_sorted_descend(stack2))
    {
        while (len--)
            push(stack2, stack1);
        return;
    }
    if (len <= 3)
    {
        push_sort_3(stack1, stack2, len);
        return;
    }
    cnt1 = len;  
    cnt2 = 0;
    med = mediane(stack2->arr, stack2->len, len, 0);
    while (len != cnt1 / 2)
        if (stack2->arr[0] >= med && len--)
            push(stack2, stack1);
        else if (++cnt2)
            rotate(stack2);
    while (cnt1 / 2 != stack2->len && cnt2--)
        rrotate(stack2);
    quick_sort_a(stack1, stack2, cnt1 / 2 + cnt1 % 2, 0);
    quick_sort_b(stack1, stack2, cnt1 / 2);
}
