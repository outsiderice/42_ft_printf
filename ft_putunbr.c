/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:34:39 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/26 20:33:57 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr(int count, unsigned long long nbr, char *base, const char *type)
{
	if (nbr < 0 && ft_strchr("di", *type))
	{
		nbr = nbr * -1;
		count = ft_putchar('-');
	}
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		count = ft_putnbr(count, nbr / ft_strlen(base), base, type);
		count = ft_putnbr(count, nbr % ft_strlen(base), base, type);
	}
	else if (nbr < (unsigned long)ft_strlen(base))
		count = count + write(1, &base[nbr], 1);
	return (count);
}
