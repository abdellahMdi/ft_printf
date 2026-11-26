/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hellper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 00:01:32 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/26 00:57:21 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char i)
{
	return (i == 'i' || i == 's' || i == 'p' || i == 'd' || i == 'c'
		||i == 'u' || i == 'x' || i == 'X' || i == '%');
}

int	ft_handler(char type, char flag, va_list args)
{
	int	check;

	check = 0;
	if (type == 'i')
		check = ft_print_int(va_arg(args, int), 0, 1, flag);
	else if (type == 'u')
		check = ft_print_int(0, va_arg(args, unsigned int), 0, flag);
	else if (type == 'd')
		check = ft_print_int(va_arg(args, int), 0, 1, flag);
	else if (type == 's')
		check = ft_printf_str(va_arg(args, char *));
	else if (type == 'c')
		check = ft_printf_char(va_arg(args, int));
	else if (type == 'x' || type == 'X')
		check = ft_printf_hex(va_arg(args, unsigned int), type, flag);
	else if (type == 'p')
		check = ft_printf_voidp(va_arg(args, void *));
	else if (type == '%')
		check = ft_printf_char('%');
	return (check);
}
