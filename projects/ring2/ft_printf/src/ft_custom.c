/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:41:17 by escura            #+#    #+#             */
/*   Updated: 2023/11/16 17:44:40 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_remove_zeros(char *input)
{
	int	non_zero_index;
	int	new_len;

	non_zero_index = 2;
	while (input[non_zero_index] == '0' && non_zero_index < 17)
		non_zero_index++;
	new_len = 18 - non_zero_index;
	ft_memmove(input + 2, input + non_zero_index, new_len);
	input[2 + new_len] = '\0';
	return (new_len + 2);
}

void	ft_set_zeros(char *input, int width)
{
	const int	input_len = ft_strlen(input);
	const int	num_zeros = width - input_len;
	int			i;
	char		*temp;

	temp = NULL;
	ft_remove_zeros(input);
	if (input_len >= width)
		return ;
	if (width > 0)
	{
		temp = (char *)malloc(width + 1);
		temp[0] = '0';
		temp[1] = 'x';
		i = 2;
		while (i < num_zeros + 2)
			temp[i++] = '0';
		ft_strcpy(temp + num_zeros + 2, input + 2);
		temp[width] = '\0';
		ft_strcpy(input, temp);
	}
	free(temp);
}

int	ft_count_digits(long int n)
{
	size_t	i;

	if (n < 0)
		n = -n;
	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_fill_front(const char *format, int width, char fill, va_list args)
{
	int	result;

	result = 0;
	if (width > 0 && !(*format == 'p' && fill == '0'))
	{
		width -= get_var_len(*format, args);
		while (width-- > 0)
			result += ft_putchar(fill, 1);
	}
	return (result);
}

int	ft_fill_back(int width, char fill)
{
	int	result;

	result = 0;
	if (width < 0)
	{
		while (width++ < 0)
			result += ft_putchar(fill, 1);
	}
	return (result);
}
