/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:08:31 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 16:04:14 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	check_duplicates(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				ft_error("Error");
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	single_arg(char *arg, t_stack **a)
{
	int			i;
	int			sign;
	long int	num;
	int			len;

	sign = 1;
	i = 0;
	num = 0;
	len = ft_strlen(arg);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || arg[i] == '-')
		{
			if (arg[i] == '-')
			{
				if (sign == -1)
					ft_error("Error");
				sign = -1;
				i++;
			}
			else if (!ft_isdigit(arg[i]))
				ft_error("Error");
			num = num * 10 + arg[i] - '0';
			if (num > INT_MAX)
				ft_error("Error");
		}
		if (ft_isdigit(arg[i]) && (is_space(arg[i + 1]) || i + 1 == len))
		{
			ft_lstadd_back(a, ft_lstnew((int)num * sign));
			num = 0;
			sign = 1;
		}
		if ((is_space(arg[i]) && !ft_isdigit(arg[i - 1])) || is_space(arg[len
				- 1]))
			ft_error("Error");
		i++;
	}
}

void	multi_args(char **args, t_stack **a)
{
	int			i;
	int			j;
	int			sign;
	long int	num;

	sign = 1;
	i = 1;
	j = 0;
	while (args[i])
	{
		num = 0;
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-')
			{
				if (sign == -1)
					ft_error("Error");
				sign = -1;
				j++;
			}
			else if (!ft_isdigit(args[i][j]))
				ft_error("Error");
			num = num * 10 + args[i][j] - '0';
			if (num > INT_MAX)
				ft_error("Error");
			j++;
		}
		ft_lstadd_back(a, ft_lstnew((int)num * sign));
		i++;
		sign = 1;
	}
}

void	read_args(char **args, t_stack **a)
{
	if (!args[1])
		exit(0);
	if (args[1] && !args[2])
		single_arg(args[1], a);
	else
		multi_args(args, a);
	check_duplicates(*a);
}
