/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:56:35 by escura            #+#    #+#             */
/*   Updated: 2023/11/23 13:03:36 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int do_print)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)", do_print));
	len = 0;
	while (str[len])
	{
		ft_putchar(str[len], do_print);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n, int do_print)
{
	long int	nb;
	int			length;

	nb = n;
	length = 0;
	if (nb < 0)
	{
		nb = -nb;
		length++;
	}
	if (nb <= 9)
	{
		ft_putchar(nb + '0', do_print);
		length++;
	}
	else
	{
		length += ft_putnbr(nb / 10, do_print);
		length += ft_putnbr(nb % 10, do_print);
	}
	return (length);
}

int	ft_putunbr(unsigned int nb, int do_print)
{
	int	length;

	length = 0;
	if (nb <= 9)
	{
		ft_putchar(nb + '0', do_print);
		length++;
	}
	else
	{
		length += ft_putnbr(nb / 10, do_print);
		length += ft_putnbr(nb % 10, do_print);
	}
	return (length);
}

int	ft_putptr(void *ptr, int do_print, int width)
{
	char		buffer[sizeof(void *) * 2 * 3];
	uintptr_t	ptr_value;
	int			shift;
	size_t		index;

	ptr_value = (uintptr_t)ptr;
	buffer[0] = '0';
	buffer[1] = 'x';
	index = 2;
	while (index < sizeof(void *) * 2 + 2)
	{
		shift = (sizeof(void *) * 2 + 1 - index) * 4;
		buffer[index++] = "0123456789abcdef"[(ptr_value >> shift) & 0xf];
	}
	buffer[index] = '\0';
	ft_set_zeros(buffer, width);
	return (ft_putstr(buffer, do_print));
}

int	ft_putx(unsigned int value, int capital, int do_print)
{
	char	buffer[9];
	int		index;
	int		len;

	index = 0;
	buffer[index++] = "0123456789abcdef"[value % 16];
	value /= 16;
	while (value != 0)
	{
		buffer[index++] = "0123456789abcdef"[value % 16];
		value /= 16;
	}
	len = index;
	while (index > 0)
	{
		if (capital)
			ft_putchar(ft_toupper(buffer[--index]), do_print);
		else
			ft_putchar(buffer[--index], do_print);
	}
	return (len);
}
