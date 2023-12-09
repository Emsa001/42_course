/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:07:04 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 13:59:17 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

void	ra(t_stack **a)
{
	if(rotate(a) == -1)
		return;
	ft_putstr_fd("ra\n", 1);
}
	

void	rb(t_stack **b)
{
	if(rotate(b) == -1)
		return;
	ft_putstr_fd("ra\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return;
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
