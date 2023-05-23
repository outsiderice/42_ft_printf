/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:03:08 by amagnell          #+#    #+#             */
/*   Updated: 2023/05/18 21:30:28 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
//printf prints its arguments, and the number of characters of the stirng 
//and if there's an error it returns -1

//what does this function have to return?

void	writer_a(const char *str)
{

}

void	writer_b(int num)
{

}

void	sort_format(const char *trigger)
{
	if (trigger == 'c' || trigger == 's')
		writer_a(va_arg(args, char *));
            //if the next character is a p
	else if (trigger == 'd' || trigger == 'i')
		writer_b();
            //if the next character is a u
            //if the next character is a x
            //if the next character is a X
}

int	ft_printf(const char *input, ...)
{
	va_list args;
	int	i;
	const char *output;

	i = 0;
	va_start(args, input);
	output = va_arg(args, char*);
	va_end(args);
	while (output[i])
	{
		if (output[i] == '%')
			sort_format(&output[i + 1]);
		else
			write(1, &output[i], 1);
		i++;
	}
	return(i);
}

//I need to move through const char *, and when it finds a special character
//(aka %) it should go to some if conditions which do different things depending on what's after the special character.
//does each special character need a unique function? Or can they be reused.
//When you tell it to print something null it will print (null) literally;
