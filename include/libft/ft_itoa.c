/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:32:00 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/03 16:22:08 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate(int len)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	return (str);
}

void	*fill(char *s, int len, long nbr)
{
	while (nbr)
	{
		s[len - 1] = nbr % 10 + 48;
		nbr /= 10;
		len--;
	}
	return (s);
}

int	f_len(int nbr)
{
	int	len;

	len = 0;
	if (!nbr || nbr < 0)
		len = 1;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		len;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	len = f_len(n);
	str = allocate(len);
	if (!str)
		return (0);
	str[len] = '\0';
	if (!nbr)
		str[0] = 48;
	if (n < 0)
		str[0] = '-';
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	fill(str, len, nbr);
	return (str);
}
