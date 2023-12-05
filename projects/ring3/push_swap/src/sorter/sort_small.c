/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:58:30 by escura            #+#    #+#             */
/*   Updated: 2023/12/05 18:02:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	two_nums(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	three_nums(t_stack **a)
{
	const int	top_value = (*a)->value;
	const int	middle_value = (*a)->next->value;
	const int	bottom_value = (*a)->next->next->value;

	if (top_value > middle_value && top_value < bottom_value)
		sa(a, 1);
	else if (top_value > middle_value && middle_value > bottom_value)
	{
		if (bottom_value > middle_value)
			ra(a, 1);
		else
		{
			sa(a, 1);
			rra(a, 1);
		}
	}
	else if (top_value > bottom_value && top_value < middle_value)
		rra(a, 1);
	else if (top_value > middle_value && top_value > bottom_value)
		ra(a, 1);
	else if (middle_value > top_value && middle_value > bottom_value)
	{
		sa(a, 1);
		ra(a, 1);
	}
}

void	four_nums(t_stack **a, t_stack **b)
{
	int min_index;

	min_index = find_min(*a);
	while (min_index--)
		ra(a, 1);
	pb(a, b, 1);
	three_nums(a);
	pa(a, b, 1);
}

void five_nums(t_stack **a, t_stack **b)
{
    int min_index;

    min_index = find_min(*a);
    if (min_index >= 3)
    {
        min_index = 5 - min_index;
        while (min_index--)
            rra(a, 1);
    }
    else
        while (min_index--)
            ra(a, 1);
    pb(a, b, 1);
    four_nums(a, b);
    pa(a, b, 1);
}