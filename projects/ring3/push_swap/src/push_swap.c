/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:45:11 by escura            #+#    #+#             */
/*   Updated: 2023/12/05 19:14:55 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void show_results(t_stack *a, t_stack *b){
	printf("Stack A: ");
	while (a)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("\n");
	printf("Stack B: ");
	while (b)
	{
		printf("%d ", b->value);
		b = b->next;
	}
	printf("\n");
}

int	main(int nb, char **args)
{
	t_stack	*a;
	t_stack	*b;

	// printf("\nOperations: \n");
	read_args(args, &a);
	decide_sort(&a, &b);

	printf("\nResults: \n");
	show_results(a, b);
	return (0);
}
