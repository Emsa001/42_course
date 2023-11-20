/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:55:29 by escura            #+#    #+#             */
/*   Updated: 2023/11/16 16:31:35 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_vars_2(const char *format, va_list args)
{
	int	result;

	result = 0;
	if (*format == 'u')
		result += ft_putunbr(va_arg(args, unsigned int), 1);
	if (*format == 'x')
		result += ft_putx(va_arg(args, unsigned int), 0, 1);
	if (*format == 'X')
		result += ft_putx(va_arg(args, unsigned int), 1, 1);
	if (*format == '%')
		result += ft_putchar('%', 1);
	return (result);
}

int	ft_parse_vars(const char *format, int width, char fill, va_list args)
{
	int	result;
	int	nb;

	if (fill == '0' || fill == '.' || fill == '-')
	{
		nb = check_for_negative(format, args);
		result = ft_fill_front(format, width, fill, args);
	}
	else
	{
		result = ft_fill_front(format, width, fill, args);
		nb = check_for_negative(format, args);
	}
	if (*format == 'c')
		result += ft_putchar(va_arg(args, int), 1);
	if (*format == 's')
		result += ft_putstr(va_arg(args, char *), 1);
	if (*format == 'p')
		result += ft_putptr(va_arg(args, void *), 1, width);
	if (*format == 'd' || *format == 'i')
		result += ft_putnbr(nb, 1);
	result += ft_parse_vars_2(format, args);
	result += ft_fill_back(width + result, fill);
	return (result);
}

const char	*ft_parse_format(const char *format, int *printed_characters,
		va_list args)
{
	int		width;
	char	fill;
	char	sign;

	format++;
	width = 0;
	fill = ' ';
	sign = 1;
	while (ft_isdigit(*format) || *format == '-' || *format == '.')
	{
		if (*format == '-' && sign != -1)
			sign = -1;
		else if (*format == '-')
			fill = '-';
		else if (*format == '.')
			fill = '.';
		else if (width == 0 && *format == '0')
			fill = '0';
		else
			width = width * 10 + *format - '0';
		format++;
	}
	*printed_characters += ft_parse_vars(format, width * sign, fill, args);
	return (format);
}

int	ft_printf_read(const char *format, int printed_characters, va_list args)
{
	while (*format != '\0')
	{
		if (*format == '%')
			format = ft_parse_format(format, &printed_characters, args);
		else
			printed_characters += ft_putchar(*format, 1);
		format++;
	}
	return (printed_characters);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_characters;

	va_start(args, format);
	printed_characters = 0;
	printed_characters = ft_printf_read(format, printed_characters, args);
	va_end(args);
	return (printed_characters);
}
