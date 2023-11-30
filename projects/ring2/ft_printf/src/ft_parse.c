/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:59 by escura            #+#    #+#             */
/*   Updated: 2023/11/30 18:38:33 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	counter;

	if (!str)
		return (ft_putstr("(null)"));
	counter = 0;
	while (*str)
	{
		counter += ft_putchar(*str);
		str++;
	}
	return (counter);
}

int	ft_putnbr(int nb, char format)
{
	int				counter;
	unsigned int	num;

	counter = 0;
	if (format == 'u')
		num = (unsigned int)nb;
	else
	{
		num = (unsigned int)nb;
		if (nb < 0)
		{
			counter += ft_putchar('-');
			num = (unsigned int)(-nb);
		}
	}

	if (num >= 10)
	{
		counter += ft_putnbr(num / 10, format);
		counter += ft_putnbr(num % 10, format);
	}
	else
		counter += ft_putchar(num + '0');
	return (counter);
}

void	ft_puthex(unsigned int nb, char *hex, int *counter, int i)
{
	if (nb == 0)
	{
		if (i == 0)
			*counter += ft_putchar('0');
		return ;
	}
	ft_puthex(nb / 16, hex, counter, ++i);
	*counter += ft_putchar(hex[nb % 16]);
}

void	ft_putptr(void *ptr, int i, int *counter)
{
	unsigned long long	d;

	d = (unsigned long long)ptr;
	if (d == 0)
	{
		*counter += ft_putstr("0x");
		if (i == 0)
			*counter += ft_putstr("0");
		return ;
	}
	ft_putptr((void *)(d / 16), ++i, counter);
	*counter += ft_putchar(HEXA[d % 16]);
}
