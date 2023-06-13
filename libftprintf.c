/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:03:08 by amagnell          #+#    #+#             */
/*   Updated: 2023/06/03 17:47:33 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

//printf prints its arguments, and the number of characters of the resulting stirng 
//and if there's an error it returns -1
//it doesnt count the %*.

int	ft_putchar(char c)
{
	return (write(1, &c, 1);
}

int	ft_putstr(const char *str)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while(str[j])
	{
		count = count + ft_putchar(str[j]);
		j++;
	}
	return(count);
}

int	ft_putnbr(int count, int n)
{
	long	m;

	m = n;
	if (m < 0)
	{
		m = m * -1;
		count = count + ft_putchar('-');
	}
	if (m > 9)
	{
		ft_putnbr(count, m / 10);
		ft_putnbr(count, m % 10);
	}
	if (m <= 9)
	{
		m = m + '0';
		count = count + ft_putchar((char)m);
	}
	return(count);
}

int	sort_format(const char *format, va_list args)
{
	int	count;
	
	count = 0;
	if (*format == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*format == 'p')
	{
		ft_putptr()
	}
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		count = ft_putnbr(count, va_arg(args, int));
	/*
	else if (*format == 'x' || *format == 'X')
	{}
	*/
	return(count);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			count;
	int			j;

	count = 0;
	j = 0;
	va_start(args, input);
	va_end(args);
	while (input[j])
	{
		printf("l");
		if (input[j] == '%')
		{
			count = count + sort_format(&input[j + 1], args);
			j = j + 2;
		}
		else
		{
			count = count + ft_putchar(input[j]);
			j++;
		}
	}
	return(count);
}

int	main(void)
{
	printf ("k");
	printf("%d", ft_printf("%u", 2));
	printf("\n");
	printf("%u", -2);
	return(0);
}

//if what's in %u is negative return -1. add some condition like that i guess idk.
//why does printf actually print things when it's %u and a negative number?
//When you tell it to print something null it will print (null) literally;
//?? % alone no compile how in mine ??? unga unga too tired for this bs
