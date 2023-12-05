/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:11:20 by escura            #+#    #+#             */
/*   Updated: 2023/12/04 19:32:45 by escura           ###   ########.fr       */
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
		if (**format == '0' && settings->minus != 1)
			settings->fill = '0';
		else if (**format >= '0' && **format <= '9')
		{
			settings->width += ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
			(*format)--;
		}
		else if (**format == '.')
		{
			if (settings->precision == -1)
				settings->precision = 0;
			(*format)++;
			settings->precision += ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
			(*format)--;
		}
		(*format)++;
	}
}

void	print_width(t_settings *settings)
{
	if (settings->type == 's')
		settings->width -= ft_strlen((char *)settings->content);
	else if (settings->type == 'd' || settings->type == 'i')
	{
		settings->width -= get_digits((int)settings->content);
		if ((int)settings->content < 0 && settings->fill == '0'
			&& settings->minus != 1)
		{
			settings->content = -(int)settings->content;
			if (settings->content != INT_MIN)
				ft_putchar('-', settings);
		}
	}
	else if (settings->type == 'u')
		settings->width -= get_digits((unsigned int)settings->content);
	else if (settings->type == 'x' || settings->type == 'X')
		settings->width -= ft_hexlen(settings->content);
	else if (settings->type == 'p')
		settings->width -= ft_ptrlen(settings->content);
	else if (settings->type == 'c' || settings->type == '%')
		settings->width -= 1;
	else
		settings->width -= 1;
	while (settings->width > 0)
	{
		ft_putchar(settings->fill, settings);
		settings->width--;
	}
}

void	print_precision(t_settings *settings)
{
	if (settings->type == 'd' || settings->type == 'i')
	{
		if ((int)settings->content < 0)
		{
			settings->content = -(int)settings->content;
			if (settings->content != INT_MIN)
				ft_putchar('-', settings);
		}
		settings->precision -= get_digits((int)settings->content);
	}
	else if (settings->type == 'u')
		settings->precision -= get_digits((unsigned int)settings->content);
	else if (settings->type == 'x' || settings->type == 'X')
		settings->precision -= ft_hexlen(settings->content);
	while (settings->precision > 0)
	{
		ft_putchar('0', settings);
		settings->precision--;
	}
}

void	ft_clearflags(t_settings *settings)
{
	settings->current_printed = 0;
	settings->minus = 0;
	settings->fill = ' ';
	settings->precision = -1;
	settings->plus = 0;
	settings->space = 0;
	settings->hash = 0;
	settings->width = 0;
}
