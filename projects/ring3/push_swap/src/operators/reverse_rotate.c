/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:08:18 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 13:59:03 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	reverseRotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

void rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (reverseRotate(a) == -1)
		return;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (reverseRotate(b) == -1)
		return;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return;
	reverseRotate(a);
	reverseRotate(b);
	ft_putstr_fd("rrr\n", 1);
}