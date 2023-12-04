/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:37:41 by escura            #+#    #+#             */
/*   Updated: 2023/12/04 19:08:35 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int ft_ptrlen(void *ptr)
{
    unsigned long long	d;
    int					len;

    d = (unsigned long long)ptr;
    len = 2;
    if(d == 0)
        len++;
    while (d > 0)
    {
        d /= 16;
        len++;
    }
    
    return (len);
}

int ft_hexlen(unsigned int nb)
{
    int len;

    len = 0;
    if(nb == 0)
        len++;
    while (nb > 0)
    {
        nb /= 16;
        len++;
    }
    
    return (len);
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

int ft_strlen(char *str)
{
    int i;


    if(str == '\0')
        return 6;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_substr(char *str, int start, int len)
{
    char *substr;
    int i;

    i = 0;
    if(!(substr = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (i < len)
    {
        substr[i] = str[start];
        i++;
        start++;
    }
    substr[i] = '\0';
    return (substr);
}