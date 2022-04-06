/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:02:08 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/04 21:42:57 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (del)(void *))
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (head == NULL)
			head = new;
		else
			ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
