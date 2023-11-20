/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:32:21 by escura            #+#    #+#             */
/*   Updated: 2023/11/16 17:45:06 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_for_negative(const char *format, va_list args)
{
	int	nb;

	nb = 0;
	if ((*format == 'd' || *format == 'i'))
	{
		nb = va_arg(args, int);
		if (nb < 0)
			ft_putchar('-', 1);
	}
	return (nb);
}

int	get_var_len(const char format, va_list args)
{
	int		result;
	va_list	args_copy;

	result = 0;
	va_copy(args_copy, args);
	if (format == 'c' || format == '%')
		return (1);
	if (format == 's')
		return (ft_strlen(va_arg(args_copy, char *)));
	if (format == 'p')
		result += ft_putptr(va_arg(args_copy, void *), 0, 0);
	if (format == 'd' || format == 'i')
		result += ft_putnbr(va_arg(args_copy, int), 0);
	if (format == 'u')
		result += ft_putunbr(va_arg(args_copy, unsigned int), 0);
	if (format == 'x')
		result += ft_putx(va_arg(args_copy, unsigned int), 0, 0);
	if (format == 'X')
		result += ft_putx(va_arg(args_copy, unsigned int), 1, 0);
	va_end(args_copy);
	return (result);
}
