/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:50:52 by escura            #+#    #+#             */
/*   Updated: 2023/12/05 18:06:32 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

void				read_args(char **args, t_stack **a);

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
int					find_min(t_stack *a);

void				two_nums(t_stack **a);
void				three_nums(t_stack **a);
void				four_nums(t_stack **a, t_stack **b);
void				five_nums(t_stack **a, t_stack **b);
void				sort_large(t_stack **a, t_stack **b);

void				sa(t_stack **a, int write);
void				sb(t_stack **b, int write);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b, int write);
void				pb(t_stack **a, t_stack **b, int write);
void				ra(t_stack **a, int write);
void				rb(t_stack **b, int write);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int write);
void				rrb(t_stack **b, int write);
void				rrr(t_stack **a, t_stack **b);

#endif
