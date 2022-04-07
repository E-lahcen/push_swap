/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:59:22 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/07 09:28:38 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_arr	stack_1;
	t_arr	stack_2;

	if (argc > 2)
	{
		init_stack1(&stack_1, argc, argv);
		init_stack2(&stack_2, argc);
		if (argc == 4)
			mini_sort_3(&stack_1);
		else
			quick_sort_a(&stack_1, &stack_2, stack_1.len);
		free_function(&stack_1);
		free_function(&stack_2);
	}
	return (0);
}
