/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:36:24 by lelhlami          #+#    #+#             */
/*   Updated: 2021/11/29 15:57:58 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l1;
	t_list	*l2;

	l1 = *lst;
	while (l1)
	{
		l2 = l1 -> next;
		ft_lstdelone(l1, del);
		l1 = l2;
	}
	*lst = NULL;
}
