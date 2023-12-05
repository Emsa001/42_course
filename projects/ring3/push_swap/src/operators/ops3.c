/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:08:18 by escura            #+#    #+#             */
/*   Updated: 2023/12/05 16:17:08 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **a, int write)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (write)
		ft_putstr_fd("rra\n", 1);
	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	*a = tmp2->next;
	(*a)->next = tmp;
	tmp2->next = NULL;
}

void	rrb(t_stack **b, int write)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (write)
		ft_putstr_fd("rrb\n", 1);
	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	tmp2 = *b;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	*b = tmp2->next;
	(*b)->next = tmp;
	tmp2->next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
}