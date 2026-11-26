/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:17:35 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/26 01:07:36 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_hex_char(unsigned int k)
{
	if (k >= 16)
		return (1 + nbr_hex_char(k / 16));
	return (1);
}

static int	print_prefix(char format, char flag, unsigned int n)
{
	if (!(flag == '#' && n != 0))
		return (0);
	if (format == 'X')
		return (write(1, "0X", 2));
	else
		return (write(1, "0x", 2));
}

int	ft_printf_hex(unsigned int n, char format, char flag)
{
	int		len;
	char	str[17];
	char	*hex;
	int		prfx;
	
	prfx = print_prefix(format, flag, n);
	hex = "0123456789abcdef";
	if (format == 'X')
		hex = "0123456789ABCDEF";
	len = nbr_hex_char(n);
	str[len] = '\0';
	while (n >= 16)
	{
		str[len-- - 1] = hex[n % 16];
		n /= 16;
	}
	str[len - 1] = hex[n];
	len = ft_printf_str(str);
	if (prfx == -1 || len == -1)
		return (-1);
	return (len + prfx);
}
