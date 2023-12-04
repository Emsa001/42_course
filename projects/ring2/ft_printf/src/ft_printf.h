/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:41 by escura            #+#    #+#             */
/*   Updated: 2023/12/04 18:44:37 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"

typedef struct s_settings
{
	int		printed;
	int		current_printed;
	void	*content;
	char	type;

	int		minus;
	char	fill;
	int		precision;

	int		plus;
	int		space;
	int		hash;

	int		width;
}			t_settings;

int			ft_strlen(char *str);
char		*ft_substr(char *str, int start, int len);
void		ft_putchar(char c, t_settings *settings);
void		ft_putstr(char *str, t_settings *settings);
void		ft_putnbr(long int nb, t_settings *settings);
void		ft_puthex(unsigned int nb, char *hex, t_settings *settings);
void		ft_putptr(void *ptr, t_settings *settings);
int			ft_printf(const char *format, ...);

int			ft_atoi(const char *str);
int			get_digits(long int n);
int			ft_ptrlen(void *ptr);
int			ft_hexlen(unsigned int nb);
void		pad(t_settings *settings);

void		print_width(t_settings *settings);
void		print_precision(t_settings *settings);
void		ft_flags(va_list args, const char **format, t_settings *settings);
void		ft_parse(va_list args, const char **format, t_settings *settings);
void		ft_clearflags(t_settings *settings);

#endif
