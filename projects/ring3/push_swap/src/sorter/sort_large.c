/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:03 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 16:59:45 by escura           ###   ########.fr       */
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

#include "../../includes/push_swap.h"

void print_sol(t_stack *a){
    while(a){
        printf("a: %d (%d)\n", (a)->value, (a)->push);
        a = (a)->next;
    }
}

void max_sorted_seq(t_stack **a){
    // nested loops
    int start_from = (*a)->index;
    int max_sorted = 0;
    t_stack *tmp;
    tmp = *a;
    while(tmp)
    {
        t_stack *b;
        b = (tmp)->next;
        int current_sorted = 0;
        int last = (tmp)->value;
        while(b != NULL)
        {
            if(last <= b->value){
                last = b->value;
                current_sorted++;
            }
            b = b->next;
        }
        if(current_sorted > max_sorted)
        {
            max_sorted = current_sorted;
            start_from = (tmp)->index;
        }

        tmp = (tmp)->next;
    }
    tmp = *a;
    while(start_from > 0)
    {
        tmp->push = true;
        tmp = tmp->next;
        start_from--;
    }
    
    max_sorted = 0;
    while(tmp){
        t_stack *b;
        b = tmp->next;
        int last = tmp->value;
        while(b != NULL)
        {
            b->push = true;
            if(last <= b->value){
                last = b->value;
                b->push = false;
            }
            b = b->next;
        }
        tmp = tmp->next;
    }
}

void	sort_large(t_stack **a, t_stack **b)
{
    max_sorted_seq(a);

    t_stack *tmp = *a;
    while(tmp->next != NULL){
        if((tmp)->push == true)
            pb(a, b);
        else
            ra(a);

        if((tmp)->next == NULL)
            break;
        tmp = (tmp)->next;
    }

    //set a to first element
    // print_sol(*a);
}
