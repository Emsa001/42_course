/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:56 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 13:25:25 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	decide_sort(t_stack **a, t_stack **b)
{
	int	min_index;
	int	len;

	len = ft_lstsize(*a);
	if(len <= 3)
		tiny_sort(a);
	else if (len == 4)
		four_nums(a, b);
	else if (len == 5)
		five_nums(a, b);
	else
		sort_large(a,b);
}
