/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:50:52 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 14:01:14 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

# define true 1
# define false 0

typedef struct s_stack
{
	int				value;
	int				index;
	int				push;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				read_args(char **args, t_stack **a);
void				ft_error(char *msg);

void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				ft_lstclear(t_stack **lst, void (*del)(int));
void				ft_lstdelone(t_stack *lst, void (*del)(int));
void				ft_lstiter(t_stack *lst, int (*f)(int));
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int));
t_stack				*ft_lstnew(int value);
int					ft_lstsize(t_stack *lst);

void				decide_sort(t_stack **a, t_stack **b);
t_stack				*find_min(t_stack *a);
t_stack				*find_max(t_stack *a);
int					get_digits(int nb);
void				finish_rotation(t_stack **stack, t_stack *top_node,
						char stack_name);
void				rotate_to_min(t_stack **stack);
void				init_nodes(t_stack *a, t_stack *b);
void				set_current_position(t_stack *stack);
void				show_results(t_stack *a, t_stack *b);

void				tiny_sort(t_stack **a);
void				four_nums(t_stack **a, t_stack **b);
void				five_nums(t_stack **a, t_stack **b);
void				sort_large(t_stack **a, t_stack **b);

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

#endif
