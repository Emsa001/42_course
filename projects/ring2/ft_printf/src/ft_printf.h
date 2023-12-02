/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:41 by escura            #+#    #+#             */
/*   Updated: 2023/12/02 18:13:18 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXA "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"

typedef struct s_settings
{
	int	printed;
    void *content;

	int	minus;
	char fill;
	int	dot;

	int	plus;
	int	space;
	int	hash;

	int	width;
}		t_settings;

void	ft_putchar(char c, t_settings *settings);
void	ft_putstr(char *str, t_settings *settings);
void	ft_putnbr(int nb, t_settings *settings);
// void	ft_puthex(unsigned int nb, char *hex, int *counter, int i);
// void	ft_putptr(void *ptr, int i, int *counter);
int		ft_printf(const char *format, ...);

int		ft_atoi(const char *str);
int		get_digits(long int n);
void	pad(t_settings *settings);

#endif
