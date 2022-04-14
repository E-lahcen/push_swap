/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:14 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/13 12:32:00 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap.h"

void	init_stack1(t_arr *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc)
	{
		while (++i < argc)
		{
			if (!check_argv(argv[i]))
			{
				write(2, "Error\n", 6);
				exit(0);
			}
		}
		stack->arr = (int *)malloc(sizeof(int) * argc - 1);
		if (!stack->arr)
			return ((void)write(1, "Issue in array initialisation!", 25));
	}
	i = -1;
	while (++i < argc - 1)
		stack->arr[i] = ft_atoi(argv[i + 1]);
	stack->len = argc - 1;
	stack->who = 'A';
	check_doubles(stack);
}

void	init_stack2(t_arr *stack, int argc)
{
	int	i;

	i = -1;
	if (argc)
	{
		stack->arr = (int *)malloc(sizeof(int) * argc - 1);
		if (!stack->arr)
			return ((void)write(1, "Issue in array initialisation!", 25));
	}
	while (++i < argc - 1)
		stack->arr[i] = 0;
	stack->len = 0;
	stack->who = 'B';
}
