/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:56 by escura            #+#    #+#             */
/*   Updated: 2023/12/06 18:18:51 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	decide_sort(t_stack **a, t_stack **b)
{
	int	min_index;

	if (ft_lstsize(*a) == 2)
		two_nums(a);
	else if (ft_lstsize(*a) == 3)
		three_nums(a);
	else if (ft_lstsize(*a) == 4)
		four_nums(a, b);
	else if (ft_lstsize(*a) == 5)
		five_nums(a, b);
	else if(ft_lstsize(*a) > 5)
		sort_large(a, b);
}
