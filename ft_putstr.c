/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:25 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/18 17:32:49 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(const char *str)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[j] != '\0')
	{
		count = count + ft_putchar(str[j]);
		j++;
	}
	return (count);
}
