/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_voidp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:17:52 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/26 01:19:40 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_hexl_char(unsigned long k)
{
	if (k >= 16)
		return (1 + nbr_hexl_char(k / 16));
	return (1);
}

int	ft_printf_hexl(unsigned long n)
{
	int			len;
	char		str[17];
	const char	*hex;

	hex = "0123456789abcdef";
	len = nbr_hexl_char(n);
	str[len] = '\0';
	while (n >= 16)
	{
		str[len - 1] = hex[n % 16];
		n /= 16;
		len--;
	}
	str[len - 1] = hex[n];
	return (ft_printf_str(str));
}

static int	ft_write_pointer(unsigned long pointer)
{
	int	len;
	int	check;

	len = 0;
	check = write(1, "0x", 2);
	if (check == -1)
		return (-1);
	len += 2;
	check = ft_printf_hexl(pointer);
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}

int	ft_printf_voidp(void *ptr)
{
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	return (ft_write_pointer((unsigned long)ptr));
}
