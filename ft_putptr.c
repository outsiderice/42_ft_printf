/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:19 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/28 19:10:31 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	count = count + ft_nbrs((unsigned long)ptr, "p");
	return (count);
}
