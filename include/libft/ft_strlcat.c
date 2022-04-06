/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:23:47 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/04 21:36:40 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	size_res;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (dstsize <= size_dest)
		size_res = size_src + dstsize;
	else
		size_res = size_src + size_dest;
	size_src = 0;
	if (size_dest < dstsize)
	{
		while (src[size_src] != '\0' && size_dest < dstsize - 1)
		{	
			dst[size_dest] = src[size_src];
			size_src++;
			size_dest++;
		}
		dst[size_dest] = '\0';
	}
	return (size_res);
}
