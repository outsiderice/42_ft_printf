/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:19 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/26 20:25:01 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	count = count + ft_nbrs((unsigned long)ptr, "p");
	return (count);
}
