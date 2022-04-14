/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:19:20 by lelhlami          #+#    #+#             */
/*   Updated: 2021/11/29 03:48:36 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l1;

	l1 = (t_list *)malloc(sizeof(t_list));
	if (!l1)
	{
		free(l1);
		return (0);
	}
	l1 -> content = content;
	l1 -> next = NULL;
	return (l1);
}
