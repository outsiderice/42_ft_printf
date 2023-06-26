/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:44:16 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/26 21:00:56 by amagnell         ###   ########.fr       */
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

// int	main(void)
// {
// 	int a;
// 	int b;
// 	a = ft_printf("'>&bK6S4dV%uzNeH%iA%dp%cx%i%x 9o%u,x __ ", 382237279, 914058350, 1094484544, 1899538252, 1816946126, -512908442, -1125117166);
// 	printf("\n");
// 	b = printf("'>&bK6S4dV%uzNeH%iA%dp%cx%i%x 9o%u,x __ ", 382237279, 914058350, 1094484544, 1899538252, 1816946126, -512908442, -1125117166);
// 	printf("\n");
// 	printf("my printf returns: %d", a);
// 	printf("pritnf returns: %d", b);
// 	return (0);
// }