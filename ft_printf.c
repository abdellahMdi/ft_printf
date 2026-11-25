/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:23:15 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/12 17:21:03 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_handler(char c, va_list args)
{
	int nprinted;
	int check;

	nprinted = 0;
	if (c == 'i')
		check = ft_printf_int(va_arg(args, int));
	else if (c == 'u')
		check = ft_printf_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'd')
		check = ft_printf_int(va_arg(args, int));
	else if (c == 's')
		check = ft_printf_string(va_arg(args, char *));
	else if (c == 'c')
		check = ft_printf_char(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		check = ft_printf_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		check = ft_printf_pointer(va_arg(args, void *));
	else if (c == '%')
		check = ft_printf_char('%');

	return (check);
}

int check_type (char i)
{
	return (i == 'i' || i == 's' ||  i == 'p' || i == 'd' || i == 'c' || i == 'u' || i == 'x' || i == 'X' || i == '%');
}
int ft_print_inputs(const char *str, va_list args)
{
	int i;
	int nprinted;
	int check;

	i = 0;
	nprinted = 0;
	while (true)
	{
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			if (check_type(str[i + 1]))
				check = ft_handler(str[i++ + 1], args);
			else if ()
				check = ft_printf_char(str[i]);
			i++;
		}
		else
			check = ft_printf_char(str[i]);
		if (check == -1)
			return (-1);
		nprinted += check;
	}
	return (nprinted);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    char    *str;
    int nprinted;

    nprinted  = 0;
    if (!format)
        return (0);
    str = ft_strdup(format);
    va_start(args, format);
    nprinted += ft_print_inputs(str, args);
    va_end(args);
    free(str);
    return (nprinted);
}
