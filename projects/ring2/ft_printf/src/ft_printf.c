/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:21:57 by escura            #+#    #+#             */
/*   Updated: 2023/12/04 19:25:53 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_number(t_settings *settings)
{
	if ((int)settings->content >= 0)
	{
		if (settings->space == 1)
		{
			ft_putchar(' ', settings);
			settings->width--;
		}
		if (settings->plus > 0)
		{
			if (settings->content >= 0)
				ft_putchar('+', settings);
		}
	}
	ft_putnbr(settings->content, settings);
}

void	ft_parse(va_list args, const char **format, t_settings *settings)
{

	ft_flags(args, format, settings);
	settings->type = **format;
	if (**format != '%')
		settings->content = va_arg(args, void *);
	if(**format == 's'){
		if(settings->precision != -1){
			if(settings->width > 0 && ft_strlen(settings->content) - settings->precision > 0 && settings->minus == 0)
				settings->width += ft_strlen(settings->content) - settings->precision;
			if (settings->precision == 0 )
				settings->content = "";		
		}
		if(settings->content == NULL)
			settings->content = "(null)";
	}
	if (settings->minus == 0 && settings->width > 0)
		print_width(settings);
	if (settings->precision > 0 && settings->type != 's')
		print_precision(settings);
	if (**format == 'c')
		ft_putchar((char)settings->content, settings);
	else if (**format == 's'){
		if(settings->precision != -1)
			settings->content = ft_substr((char *)settings->content, 0, settings->precision);
		ft_putstr(settings->content, settings);
		if(settings->precision != -1)
			free(settings->content);
	}
	else if (**format == 'd' || **format == 'i')
	{
		settings->content = (int)settings->content;
		do_number(settings);
	}
	else if (**format == 'u')
	{
		settings->content = (unsigned int)settings->content;
		do_number(settings);
	}
	else if (**format == 'x')
	{
		settings->content = (unsigned int)settings->content;
		ft_puthex(settings->content, HEXA_LOWER, settings);
	}
	else if (**format == 'X')
	{
		settings->content = (unsigned int)settings->content;
		ft_puthex(settings->content, HEXA_CAP, settings);
	}
	else if (**format == 'p')
	{
		ft_putptr(settings->content, settings);
	}
	else if (**format == '%')
		ft_putchar('%', settings);
	if (settings->minus == 1)
		print_width(settings);
	(*format)++;
}

void	ft_convert(va_list args, const char *format, t_settings *settings)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_parse(args, &format, settings);
		}
		else
			ft_putchar(*format++, settings);
		
		ft_clearflags(settings);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list args;

	t_settings settings = {0, 0, 0, ' ', 0, ' ', -1, 0, 0, 0, 0};
	va_start(args, format);
	ft_convert(args, format, &settings);
	va_end(args);
	return (settings.printed);
}