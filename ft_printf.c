/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:23:15 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/26 01:22:36 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_flags(char c)
{
	return (c == '+' || c == '#' ||c == ' ');
}

int	ft_print_inputs(const char *str, va_list args)
{
	int	i;
	int	nprinted;
	int	check;

	i = 0;
	nprinted = 0;
	while (1337)
	{
		if (!str[i])
			break ;
		else if (str[i] == '%')
		{
			if (str[i + 1] && check_type(str[i + 1]))
				check = ft_handler(str[++i], 0, args);
			else if(str[i + 1] && str[i + 2] && check_flags(str[i + 1]) && check_type(str[i + 2]))
			{
				check = ft_handler(str[i + 2], str[i + 1], args);
				i += 2;
			}
			else
				check = -1;
		}
		else
			check = ft_printf_char(str[i]);
		if (check == -1)
			return (-1);
		nprinted += check;
		i++;
	}
	return (nprinted);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nprinted;

	nprinted = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	nprinted = ft_print_inputs(format, args);
	va_end(args);
	return (nprinted);
}
