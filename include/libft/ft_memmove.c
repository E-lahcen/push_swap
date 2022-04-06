/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:52:26 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/03 13:17:05 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (!src && !dst)
		return (0);
	if (dst1 > src1)
	{
		while (len)
		{
			*(dst1 + len - 1) = *(src1 + len - 1);
			len--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
