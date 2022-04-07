/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:33:40 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/07 06:57:13 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted_descend(t_arr *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len - 1)
		if (stack->arr[i] < stack->arr[i + 1])
			return (0);
	return (1);
}

static int	part(int *array, int len)
{
	int	iinf;
	int	isup;
	int	*tmp;
	int	i;

	iinf = 0;
	isup = len - 1;
	i = -1;
	tmp = NULL;
	tmp = (int *)malloc(len * sizeof(int));
	if (!tmp)
		return (write(1, "Issue in array allocation!", 25));
	while (++i < len - 1)
	{
		if (array[i] > array[len - 1])
			tmp[isup--] = array[i];
		else
			tmp[iinf++] = array[i];
	}
	tmp[iinf] = array[len - 1];
	i = -1;
	while (++i < len)
		array[i] = tmp[i];
	free(tmp);
	return (iinf);
}

void	quick_sort_it(int *arr, int len)
{
	int	i;

	if (len < 2)
		return ;
	i = part(arr, len);
	if (i)
		quick_sort_it(arr, i);
	if (i != len - 1)
		quick_sort_it(arr + i + 1, len - i - 1);
}
