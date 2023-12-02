/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:56:29 by escura            #+#    #+#             */
/*   Updated: 2023/12/02 18:14:10 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->width)
	{
		ft_putchar(settings->fill, settings);
		i++;
	}
}
