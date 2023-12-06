/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:03 by escura            #+#    #+#             */
/*   Updated: 2023/12/06 20:23:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

sa (swap a): Swap the first 2 elements at the top of stack a.Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

*/

// 87 487 781 100 101 0 1

int ft_pow(int base, int exp)
{
    int result = 1;
    while (exp--)
        result *= base;
    return result;
}

void radix_sort(t_stack **a, t_stack **b)
{
    int digits = get_digits(find_max(*a));
    printf("Digits: %d\n", digits);

}

void rotate_to_top(t_stack **stack, int index) {
    int size = ft_lstsize(*stack);
    int rotations = index < size / 2 ? index : size - index;
    void (*rotate)(t_stack**, int) = index < size / 2 ? ra : rra;
    
    while (rotations--)
        rotate(stack, 1);
}

void sort_large(t_stack **a, t_stack **b) {
    bubble(a, b);
    // quick_sort(a, b);
    // radix_sort(a, b);
    // int i = 0;
    // while (*a) {
    //     int min_index = find_min(*a);
    //     rotate_to_top(a, min_index);
    //     pb(a, b, 1);
    // }
    
    // while (*b)
    //     pa(a, b, 1);
}