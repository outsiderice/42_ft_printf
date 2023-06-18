/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:44:16 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/18 20:21:28 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//printf prints its arguments, and the number of characters of the 
//resulting string and if there's an error it returns -1

#include "libftprintf.h"

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			count;
	int			j;

	count = 0;
	j = 0;
	va_start(args, input);
	while (input[j])
	{
		if (input[j] == '%')
		{
			count = count + ft_sort_format(&input[j + 1], args);
			j = j + 2;
		}
		else
		{
			count = count + ft_putchar(input[j]);
			j++;
		}
	}
	va_end(args);
	return (count);
}


int	main(void)
{
	ft_printf("ft printf says %p", (void *)-14523);
	printf("\n");
	printf("printf says %p", (void *)-14523);
	printf("\n");
	ft_printf("ft printf says %p", "hell");
	printf("\n");
	printf("printf says %p", "hell");
	return (0);
}