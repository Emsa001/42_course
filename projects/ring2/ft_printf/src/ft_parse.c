/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:59 by escura            #+#    #+#             */
/*   Updated: 2023/12/02 18:15:21 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_settings *settings)
{
	write(1, &c, 1);
	settings->printed++;
}

void	ft_putstr(char *str, t_settings *settings)
{
	if (!str)
		return (ft_putstr("(null)", settings));
	while (*str)
		ft_putchar(*(str++), settings);
}

void ft_putnbr(int n, t_settings *settings)
{
	long int nb = n;
	if (nb < 0)
	{
		ft_putchar('-', settings);
		nb = (unsigned int)(-nb);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, settings);
		ft_putnbr(nb % 10, settings);
	}
	else
		ft_putchar(nb + '0', settings);
}

// void	ft_puthex(unsigned int nb, char *hex, int *counter, int i)
// {
// 	if (nb == 0)
// 	{
// 		if (i == 0)
// 			*counter += ft_putchar('0');
// 		return ;
// 	}
// 	ft_puthex(nb / 16, hex, counter, ++i);
// 	*counter += ft_putchar(hex[nb % 16]);
// }

// void	ft_putptr(void *ptr, int i, int *counter)
// {
// 	unsigned long long	d;

// 	d = (unsigned long long)ptr;
// 	if (d == 0)
// 	{
// 		*counter += ft_putstr("0x");
// 		if (i == 0)
// 			*counter += ft_putstr("0");
// 		return ;
// 	}
// 	ft_putptr((void *)(d / 16), ++i, counter);
// 	*counter += ft_putchar(HEXA[d % 16]);
// }
