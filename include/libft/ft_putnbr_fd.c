/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 00:44:56 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/04 16:05:35 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	p;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		p = (unsigned int)(n * -1);
	}
	else
		p = (unsigned int)n;
	if (p > 9)
	{
		ft_putnbr_fd(p / 10, fd);
		ft_putnbr_fd(p % 10, fd);
	}
	else
		ft_putchar_fd(p + 48, fd);
}
