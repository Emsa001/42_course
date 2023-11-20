/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:41 by escura            #+#    #+#             */
/*   Updated: 2023/11/16 16:46:27 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_strlen(char *str);
int		ft_putchar(char c, int do_print);
int		ft_putstr(char *str, int do_print);
int		ft_putnbr(int n, int do_print);
int		ft_putunbr(unsigned int nb, int do_print);
int		ft_putptr(void *ptr, int do_print, int width);
int		ft_putx(unsigned int value, int capital, int do_print);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_toupper(int c);
void	ft_set_zeros(char *input, int width);
int		ft_isdigit(int c);
int		ft_count_digits(long int n);
char	*ft_strcpy(char *dest, char *src);
int		ft_fill_front(const char *format, int width, char fill, va_list args);
int		ft_fill_back(int width, char fills);
int		get_var_len(const char format, va_list args);
int		check_for_negative(const char *format, va_list args);

#endif
