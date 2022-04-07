/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 06:36:25 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/07 09:21:50 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_int_limits(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int	check_argv(char *argv)
{
	int	i;
	int	len;

	i = 0;
	if ((argv[i] == '-' && !(argv[i + 1] <= '9' \
		&& argv[i + 1] >= '0')) || !argv[i])
		return (0);
	if (argv[i] == '-' && (argv[i + 1] <= '9' && argv[i + 1] >= '0'))
		i++;
	len = ft_strlen(&argv[i]);
	if (len > 10)
		return (0);
	while (argv[i])
	{
		if (!(argv[i] <= '9' && argv[i] >= '0'))
			return (0);
		i++;
	}
	if (len == 10 && check_int_limits(argv))
		return (0);
	return (1);
}

void	check_doubles(t_arr *stack1)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *)malloc(stack1->len * (sizeof(int)));
	if (!tmp)
		return ;
	while (++i < stack1->len)
		tmp[i] = stack1->arr[i];
	quick_sort_it(tmp, stack1->len);
	i = -1;
	while (++i < stack1->len - 1)
	{
		if (stack1->arr[i] == stack1->arr[i + 1])
		{
			write(2, "Error\n", 6);
			free_function(stack1);
			free(tmp);
			exit(0);
		}
	}
	free(tmp);
}

void	free_function(t_arr *stack)
{
	free(stack->arr);
}
