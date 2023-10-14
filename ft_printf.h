/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:12:26 by amagnell          #+#    #+#             */
/*   Updated: 2023/10/14 20:16:32 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *type, ...);
int		ft_nbrs(unsigned long nbr, const char *type);
char	*ft_strchr(const char *s, int c);
int		ft_sort_format(const char *type, va_list args);
int		ft_putstr(const char *str);
int		ft_putptr(unsigned long ptr);
int		ft_putunbr(int count, unsigned long long nbr, char *base, \
		const char *type);
int		ft_putnbr(int count, long long nbr, char *base, const char *type);
int		ft_putchar(char c);
size_t	ft_strlen(char *str);

#endif
