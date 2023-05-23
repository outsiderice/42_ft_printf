/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:03:08 by amagnell          #+#    #+#             */
/*   Updated: 2023/05/23 21:53:22 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
//printf prints its arguments, and the number of characters of the resulting stirng 
//and if there's an error it returns -1

int	writer_a(int i, const char *str)
{
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int	writer_b(int i, int num)
{
	write(1, &num, 1);
	return(i);
}

int	sort_format(int i, const char *format, va_list args)
{
	if (*format == 'c' || *format == 's')
		i = writer_a(i, va_arg(args, char *));
            //if the next character is a p
	else if (*format == 'd' || *format == 'i')
	{
		writer_b(i, va_arg(args, int));
		i++;
	}
            //if the next character is a u
            //if the next character is a x
            //if the next character is a X
	return(i);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			i;
	const char	*output;

	i = 0;
	va_start(args, input);
	output = va_arg(args, char *);
	va_end(args);
	while (output[i])
	{
		if (output[i] == '%')
			i = sort_format(i, &output[i + 1], args);
		else
		{
			write(1, &output[i], 1);
			i++;
		}
	}
	return(i);
}

int	main(void)
{
	ft_printf("a");
	return(0);
}

//Something wrong in the else condition in the while loop, can't print simple string right now
//When you tell it to print something null it will print (null) literally;
