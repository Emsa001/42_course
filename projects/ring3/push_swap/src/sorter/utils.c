/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:47:43 by escura            #+#    #+#             */
/*   Updated: 2023/12/05 17:48:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min(t_stack *a)
{
	int	min;
	int	min_index;
	int	i;

	min = INT_MAX;
	min_index = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_index = i;
		}
		a = a->next;
		i++;
	}
	return (min_index);
}
