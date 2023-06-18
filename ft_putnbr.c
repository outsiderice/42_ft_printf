/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:08 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/18 20:11:06 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int count, long nbr, char *base, const char *format)
{
	if (nbr < 0 && ft_strchr("di", *format))
	{
		nbr = nbr * -1;
		count = ft_putchar('-');
	}
	if (nbr >= ft_strlen(base))
	{
		count = ft_putnbr(count, nbr / ft_strlen(base), base, format);
		count = ft_putnbr(count, nbr % ft_strlen(base), base, format);
	}
	if (nbr < ft_strlen(base))
		count = count + ft_putchar(base[nbr]);
	return (count);
}
