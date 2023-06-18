/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:36 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/18 17:31:22 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*a;

	i = 0;
	a = (char *)s;
	while (a[i] != '\0')
	{
		if (a[i] == (char)c)
			return (&a[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&a[i]);
	return (NULL);
}
