/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:03 by escura            #+#    #+#             */
/*   Updated: 2023/12/05 18:41:47 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate_to_top(t_stack **stack, int index) {
    int size = ft_lstsize(*stack);
    int rotations = index < size / 2 ? index : size - index;
    void (*rotate)(t_stack**, int) = index < size / 2 ? ra : rra;
    
    while (rotations--)
        rotate(stack, 1);
}

void sort_large(t_stack **a, t_stack **b) {
    while (*a) {
        int min_index = find_min(*a);
        rotate_to_top(a, min_index);
        pb(a, b, 1);
    }
    
    while (*b)
        pa(a, b, 1);
}