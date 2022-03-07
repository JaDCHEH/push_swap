/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:37:53 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:37:55 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static void	ft_putnbr(int nbr)
{
	long	n;

	n = (long) nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_printf(const char *s, ...)
{
	va_list	tmp;
	int		i;

	va_start(tmp, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_putnbr(va_arg(tmp, int));
			i++;
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(tmp);
}
