/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:53:57 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/07 10:01:37 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/get_next_line/get_next_line.h"

void	exec_commands(char *line, t_arr *stack1, t_arr *stack2)
{
	if (!(ft_strncmp(line, "sa\n", 3)))
		swap(stack1, 0);
	else if (!(ft_strncmp(line, "sb\n", 3)))
		swap(stack2, 0);
	else if (!(ft_strncmp(line, "ss\n", 3)))
		ss(stack1, stack2, 0);
	else if (!(ft_strncmp(line, "pa\n", 3)))
		push(stack2, stack1, 0);
	else if (!(ft_strncmp(line, "pb\n", 3)))
		push(stack1, stack2, 0);
	else if (!(ft_strncmp(line, "ra\n", 3)))
		rotate(stack1, 0);
	else if (!(ft_strncmp(line, "rb\n", 3)))
		rotate(stack2, 0);
	else if (!(ft_strncmp(line, "rr\n", 3)))
		rr(stack1, stack2, 0);
	else if (!(ft_strncmp(line, "rra\n", 4)))
		rrotate(stack1, 0);
	else if (!(ft_strncmp(line, "rrb\n", 4)))
		rrotate(stack2, 0);
	else if (!(ft_strncmp(line, "rrr\n", 4)))
		rrr(stack1, stack2, 0);
	else
		free_and_exit(stack1, stack2);
}

int	main(int argc, char **argv)
{
	t_arr	stack1;
	t_arr	stack2;
	char	*line;
	int		i;

	if (argc >= 2)
	{
		init_stack1(&stack1, argc, argv);
		init_stack2(&stack2, argc);
		i = -1;
		line = get_next_line(0);
		while (line && line[0] != '\n')
		{
			exec_commands(line, &stack1, &stack2);
			line = NULL;
			line = get_next_line(0);
		}
		check_stack(&stack1, &stack2);
		free_function(&stack1);
		free_function(&stack2);
	}
	return (0);
}
