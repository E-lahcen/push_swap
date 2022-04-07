/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:58:45 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/07 09:55:31 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_arr *stack1, t_arr *stack2, int print)
{
	swap(stack1, print);
	swap(stack2, print);
	if (print)
		write(1, "ss1\n", 3);
}

void	rr(t_arr *stack1, t_arr *stack2, int print)
{
	rotate(stack1, print);
	rotate(stack2, print);
	if (print)
		write(1, "rr\n", 3);
}

void	rrr(t_arr *stack1, t_arr *stack2, int print)
{
	rrotate(stack1, print);
	rrotate(stack2, print);
	if (print)
		write(1, "rrr\n", 4);
}
