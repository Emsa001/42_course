/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:58:30 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 13:58:09 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_max(*a);
	
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	four_nums(t_stack **a, t_stack **b)
{
	int	min_index;

	set_current_position(*a);
	min_index = find_min(*a)->index;
	if (min_index >= 2)
	{
		min_index = 4 - min_index;
		while (min_index--)
			rra(a);
	}
	else
		while (min_index--)
			ra(a);
	pb(a, b);
	tiny_sort(a);
	pa(a, b);
}

void	five_nums(t_stack **a, t_stack **b)
{
	int min_index;

	min_index = find_min(*a)->index;
	if (min_index >= 3)
	{
		min_index = 5 - min_index;
		while (min_index--)
			rra(a);
	}
	else
		while (min_index--)
			ra(a);
	pb(a, b);
	four_nums(a, b);
	pa(a, b);
}