/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 04:14:55 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/04 15:25:27 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l1;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			l1 = ft_lstlast(*lst);
			l1 -> next = new;
		}
	}
}
