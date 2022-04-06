/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:09:41 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/06 16:00:04 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	mediane(int *arr, int stack_len)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = NULL;
	tmp = (int *)malloc(stack_len * sizeof(int));
	if (!tmp)
		return (write(1, "Issue in array allocation!", 25));
	while (++i < stack_len)
		tmp[i] = arr[i];
	quick_sort_it(tmp, stack_len);
	i = tmp[stack_len / 2];
	free(tmp);
	return (i);
}

void	quick_sort_a(t_arr *stack1, t_arr *stack2, int len)
{
	int	med;
	int	cnt[2];

	if (is_sorted(stack1))
		return ;
	if (len <= 3)
		return (sort_3(stack1, stack2, len));
	med = mediane(stack1->arr, len);
	cnt[0] = len;
	cnt[1] = 0;
	while (len != cnt[0] / 2 + cnt[0] % 2)
	{
		if (stack1->arr[0] < med && len--)
			push(stack1, stack2, 1);
		else if (++cnt[1])
			rotate(stack1, 1);
	}
	while (cnt[0] / 2 + cnt[0] % 2 != stack1->len && cnt[1]--)
		rrotate(stack1, 1);
	quick_sort_a(stack1, stack2, cnt[0] / 2 + cnt[0] % 2);
	quick_sort_b(stack1, stack2, cnt[0] / 2);
}

void	quick_sort_b(t_arr *stack1, t_arr *stack2, int len)
{
	int	med;
	int	cnt[2];

	if (is_sorted_descend(stack2))
	{
		while (len--)
			push(stack2, stack1, 1);
		return ;
	}
	if (len <= 3)
		return (push_sort_3(stack1, stack2, len));
	cnt[0] = len;
	cnt[1] = 0;
	med = mediane(stack2->arr, len);
	while (len != cnt[0] / 2)
	{
		if (stack2->arr[0] >= med && len--)
			push(stack2, stack1, 1);
		else if (++cnt[1])
			rotate(stack2, 1);
	}
	while (cnt[0] / 2 != stack2->len && cnt[1]--)
		rrotate(stack2, 1);
	quick_sort_a(stack1, stack2, cnt[0] / 2 + cnt[0] % 2);
	quick_sort_b(stack1, stack2, cnt[0] / 2);
}
