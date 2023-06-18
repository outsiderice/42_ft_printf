/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:06:41 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/18 19:38:59 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_nbrs(unsigned long nbr, const char *format)
{
	int		count;
	char	*base;

	count = 0;
	/*
	if (ft_strchr("diu", *format))
		base = "0123456789";
	else if (*format == 'X')
		base = "0123456789ABCDEF";
	else
	*/
		base = "0123456789abcdef";
	count = count + ft_putnbr(count, nbr, base, format);
	return (count);
}
