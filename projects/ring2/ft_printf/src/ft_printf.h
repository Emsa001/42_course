/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:41 by escura            #+#    #+#             */
/*   Updated: 2023/11/30 18:26:46 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXA "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb, char format);
void	ft_puthex(unsigned int nb, char *hex, int *counter, int i);
void	ft_putptr(void *ptr, int i, int *counter);
int		ft_convert(const char *format, va_list args);
int		ft_printf(const char *format, ...);

#endif
