/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:21:57 by escura            #+#    #+#             */
/*   Updated: 2023/12/02 18:23:59 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(va_list args, const char **format, t_settings *settings)
{
	while (**format == '#' || **format == ' ' || **format == '+'
		|| **format == '-' || **format == '0' || **format == '.'
		|| (**format >= '0' && **format <= '9'))
	{
		if (**format == '#')
			settings->hash = 1;
		else if (**format == ' ' && settings->space != -1)
			settings->space = 1;
		else if (**format == '+')
		{
			settings->plus = 1;
			settings->space = -1;
		}
		else if (**format == '-')
		{
			settings->fill = ' ';
			settings->minus = 1;
		}
		if(**format == '0' && settings->minus != 1)
			settings->fill = '0';
		else if(**format >= '0' && **format <= '9'){
			settings->width += ft_atoi(*format);
			settings->space = -1;
			while(**format >= '0' && **format <= '9')
				(*format)++;
			(*format)--;
		}
		else if(**format == '.'){
			settings->dot = 1;
			(*format)++;
			settings->width += ft_atoi(*format);
			while(**format >= '0' && **format <= '9')
				(*format)++;
			(*format)--;
		}
		(*format)++;
	}

}

void do_number(t_settings *settings){
	settings->width -= get_digits(settings->content);
	if((int)settings->content >= 0 && settings->plus == 1){
		settings->width--;
	}
	if(settings->space > 0)
		ft_putchar(' ', settings);
	if(settings->width > 0 && settings->minus == 0)
		pad(settings);
	if(settings->plus > 0){
		if(settings->content >= 0)
			ft_putchar('+', settings);
	}
	ft_putnbr(settings->content, settings);
	if(settings->width > 0 && settings->minus == 1)
		pad(settings);
}

void	ft_parse(va_list args, const char **format, t_settings *settings)
{
	ft_flags(args, format, settings);
	if (**format == 'c')
		ft_putchar(va_arg(args, int), settings);
	else if (**format == 's')
		ft_putstr(va_arg(args, char *), settings);
	else if (**format == 'd' || **format == 'i'){
		settings->content = (int)va_arg(args, int);
		do_number(settings);
	}
	else if (**format == '%')
		ft_putchar('%', settings);
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
	}
}

int	ft_printf(const char *format, ...)
{
	va_list args;

	t_settings settings = {0, 0, 0, ' ', 0, 0, 0, 0, 0};

	va_start(args, format);
	ft_convert(args, format, &settings);
	va_end(args);
	return (settings.printed);
}