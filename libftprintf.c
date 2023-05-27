/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:03:08 by amagnell          #+#    #+#             */
/*   Updated: 2023/05/27 18:06:42 by amagnell         ###   ########.fr       */
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
	if (write(1, &c, 1) != 1)
		return (-1);
	return (0);
}

int	writer_a(int i, const char *str)
{
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return(i);
}
/*
int	writer_b(int i, int num)
{
	write(1, &num, 1);
	return(i);
}
*/
int	sort_format(int i, const char *format, va_list args)
{
	char	*str;
	if (*format == 'c' || *format == 's')
	{
		printf("z");
		str = va_arg(args, char *);
		i = writer_a(i, str);
	}
            //if the next character is a p
	/*
	else if (*format == 'd' || *format == 'i')
	{
		writer_b(i, va_arg(args, int));
		i++;
	}
            //if the next character is a u
            //if the next character is a x
            //if the next character is a X
	*/
	return(i);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, input);
	va_end(args);
	while (input[i])
	{
		printf("1");
		if (input[i] == '%')
		{
			i = sort_format(i, &input[i + 1], args);
		}
		else
		{
			ft_putchar(input[i]);
			i++;
		}
	}
	return(i);
}

int	main(void)
{
	printf ("k");
	ft_printf("%s", "a");
	return(0);
}

//Current output = ask1z1
//Right now it counts and writes the format letter which it shouldn't
//When you tell it to print something null it will print (null) literally;
