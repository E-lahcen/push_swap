/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:38:11 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/02 22:15:38 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*ptr;
	int		last;

	i = 0;
	if (!s1 || !set)
		return (0);
	last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i <= last)
		i++;
	while (ft_strchr(set, s1[last]) && i <= last)
		last--;
	ptr = (char *)malloc(sizeof(char) * (last - i + 2));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1 + i, (last - i) + 2);
	return (ptr);
}
