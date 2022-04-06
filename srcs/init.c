/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:14 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/06 20:08:27 by lelhlami         ###   ########.fr       */
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
	if ((argv[i] == '-' && !NUM(argv[i + 1])) || !argv[i])
		return (0);
	if (argv[i] == '-' && NUM(argv[i + 1]))
		i++;
	len = ft_strlen(&argv[i]);
	if (len > 10)
		return (0);
	while (argv[i])
	{
		if (!NUM(argv[i]))
			return (0);
		i++;
	}
	if (len == 10 && check_int_limits(argv))
		return (0);
	return (1);
}

void	check_doubles(t_arr *stack1)
{
	int	tmp[stack1->len];
	int	i;

	i = -1;
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
            exit(0);
	    }
	}
}

void	init_stack1(t_arr *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc)
	{
		while (++i < argc)
			if (!check_argv(argv[i]))
			{
				write(2, "Error\n", 6);
				exit(0);
			}
		stack->arr = (int *)malloc(sizeof(int) * argc - 1);
		if (!stack->arr)
		{
			write(1, "Issue in array initialisation!", 25);
			return ;
		}
	}
	i = 0;
	while (i < argc - 1)
	{
		stack->arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stack->len = argc - 1;
	stack->who = 'A';
	check_doubles(stack);
}

void	init_stack2(t_arr *stack,int argc)
{
	int	i;

	i = 0;
	if (argc)
	{
		stack->arr = (int *)malloc(sizeof(int) * argc - 1);
		if (!stack->arr)
		{
			write(1, "Issue in array initialisation!", 25);
			return ;
		}
	}
	while (i < argc - 1)
	{
		stack->arr[i] = 0;
		i++;
	}
	stack->len = 0;
	stack->who = 'B';
}

void	free_function(t_arr *stack)
{
	free(stack->arr);
}
