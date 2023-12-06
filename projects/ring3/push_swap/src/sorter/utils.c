/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:47:43 by escura            #+#    #+#             */
/*   Updated: 2023/12/06 20:05:43 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min(t_stack *a)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 0;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		i++;
	}
	return (min);
}

int	find_max(t_stack *a)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = 0;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
		i++;
	}
	return (max);
}

int	get_digits(int nb)
{
	long int	num;
	int			digits;

	num = nb;
	digits = 1;
	if (num < 0)
		num *= -1;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}
