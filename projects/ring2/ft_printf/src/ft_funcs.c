/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:37:41 by escura            #+#    #+#             */
/*   Updated: 2023/12/02 18:02:57 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_digits(long int n)
{
	int	i;
	i = 1;

	if (n < 0){
		n = -n;
        i++;
    }
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
    str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
        i++;
    if (str[i] == '-')
        sign = -sign;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= 48 && str[i] <= 57)
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (sign * result);
}