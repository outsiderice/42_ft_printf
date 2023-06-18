/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:31 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/18 18:24:30 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_sort_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		count = ft_putptr(va_arg(args, void *));
	else if (ft_strchr("diuxX", *format))
		count = ft_nbrs(va_arg(args, int), format);
	else if (*format == '%')
		count = ft_putchar('%');
	return (count);
}
