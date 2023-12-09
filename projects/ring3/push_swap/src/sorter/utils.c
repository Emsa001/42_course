/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:47:43 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 13:44:38 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*find_min(t_stack *a)
{
	int		min;
	t_stack	*lowest_node;

	min = INT_MAX;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			lowest_node = a;
		}
		a = a->next;
	}
	return (lowest_node);
}

t_stack	*find_max(t_stack *a)
{
	int		max;
	t_stack	*highest_node;

	max = INT_MIN;
	while (a)
	{
		if (a->value > max)
		{
			max = a->value;
			highest_node = a;
		}
		a = a->next;
	}
	return (highest_node);
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

void	set_current_position(t_stack *stack)
{
	int	i;

	i = 0;
	if (NULL == stack)
		return ;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		++i;
	}
}


void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
}