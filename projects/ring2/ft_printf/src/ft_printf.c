/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:21:57 by escura            #+#    #+#             */
/*   Updated: 2023/11/30 18:49:08 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_check_for_flags(const char *format, va_list args)
{
	// check for "# 0 - +" flags
	while(*format == '#' || *format == '0' || *format == '-' || *format == '+')
	{
		// if (*format == '#')
		// else if (*format == '0')
		// else if (*format == '-')
		// else if (*format == '+')
		*format++;
	}
}

int	ft_convert(const char *format, va_list args)
{
	int	counter;

	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_for_flags(format, args);

			if (*format == 'c')
				counter += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				counter += ft_putstr(va_arg(args, char *));
			else if (*format == 'd')
				counter += ft_putnbr(va_arg(args, int), *format);
			else if (*format == 'i')
				counter += ft_putnbr(va_arg(args, int), *format);
			else if (*format == 'u')
				counter += ft_putnbr(va_arg(args, unsigned int), *format);
			else if (*format == 'x')
				ft_puthex(va_arg(args, unsigned int), HEXA,
					&counter, 0);
			else if (*format == 'X')
				ft_puthex(va_arg(args, unsigned int), HEXA_CAP,
					&counter, 0);
			else if (*format == 'p')
				ft_putptr(va_arg(args, void *), 0, &counter);
			else if (*format == '%')
				counter += ft_putchar('%');
		}
		else
			counter += ft_putchar(*format);
		format++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	va_start(args, format);
	counter = ft_convert(format, args);
	va_end(args);
	return (counter);
}
