/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:12:10 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 15:07:32 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// make node with minimum value at the top  of the stack
void rotate_to_min(t_stack **stack)
{
    t_stack *min_node;

    min_node = find_min(*stack);
    int len = ft_lstsize(*stack);
    while(stack != min_node)
    {
        if(len / 2 > min_node->index)
            ra(stack);
        else
            rra(stack);
    }
}
