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

int	ft_putchar(int i, char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	i++;
	return (i);
}

int	writer_a(int i, const char *str)
{
	int	j;

	j = 0;
	while(str[j])
	{
		i = ft_putchar(i, str[j]);
		j++;
	}
	return(i);
}

int	ft_putnbr(int i, int n)
{
	long	m;

	m = n;
	if (m < 0)
	{
		m = m * -1;
		i = ft_putchar(i, '-');
	}
	if (m > 9)
	{
		ft_putnbr(i, m / 10);
		ft_putnbr(i, m % 10);
	}
	if (m <= 9)
	{
		m = m + '0';
		i = ft_putchar(i, (char)m);
	}
	return(i);
}

int	sort_format(int i, const char *format, va_list args)
{
	char	*str;

	if (*format == 's')
	{
		printf("m");
		str = va_arg(args, char *);
		i = writer_a(i, str);
	}
	else if (*format == 'c')
		i = ft_putchar(i, va_arg(args, int));
	/*
	else if (*format == 'p')
	{
	}
	*/
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		i = ft_putnbr(i, va_arg(args, int));
	/*
	else if (*format == 'x' || *format == 'X')
	{}
	*/
	return(i);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			i;
	int			j;

	i = 0;
	j = 0;
	va_start(args, input);
	va_end(args);
	while (input[j])
	{
		printf("l");
		if (input[j] == '%')
		{
			i = sort_format(i, &input[j + 1], args);
			j += 2;
		}
		else
		{
			i = ft_putchar(i, input[j]);
			j++;
		}
	}
	return(i);
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
