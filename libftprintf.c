/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:03:08 by amagnell          #+#    #+#             */
/*   Updated: 2023/05/29 20:28:03 by amagnell         ###   ########.fr       */
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
	int			j;

	i = 0;
	j = 0;
	va_start(args, input);
	va_end(args);
	while (input[j])
	{
		printf("1");
		if (input[j] == '%')
		{
			i = sort_format(i, &input[j + 1], args);
			j += 2;
		}
		else
		{
			ft_putchar(input[j]);
			i++;
			j++;
		}
	}
	return(i);
}

int	main(void)
{
	printf ("k");
	printf("%d", ft_printf("%s", "Hello"));
	return(0);
}

//Now I should deal with d and i
//When you tell it to print something null it will print (null) literally;
