/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:17:47 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/04 22:28:44 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_out_nbr(unsigned long nbr, int neg)
{
	if (nbr > 9223372036854775807)
	{
		if (neg == 1)
			return (-1);
		else if (neg == -1)
			return (0);
	}
	return (nbr * neg);
}

int	ft_atoi(const char *str)
{
	unsigned long			nbr;
	int						is_negative;

	nbr = 0;
	is_negative = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str
			== '\r' || *str == '\v' || *str == '\f'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		is_negative = -1;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			nbr = nbr * 10 + (*str - 48);
		else
			return (is_negative * nbr);
		str++;
	}
	return (check_out_nbr(nbr, is_negative));
}
