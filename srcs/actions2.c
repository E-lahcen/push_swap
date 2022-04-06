/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:58:45 by lelhlami          #+#    #+#             */
/*   Updated: 2022/04/06 15:05:20 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_arr *stack1, t_arr *stack2)
{
	swap(stack1, 0);
	swap(stack2, 0);
	write(1, "ss\n", 3);
}

void	rr(t_arr *stack1, t_arr *stack2)
{
	rotate(stack1, 0);
	rotate(stack2, 0);
	write(1, "rr\n", 3);
}

void	rrr(t_arr *stack1, t_arr *stack2)
{
	rrotate(stack1, 0);
	rrotate(stack2, 0);
	write(1, "rrr\n", 4);
}
