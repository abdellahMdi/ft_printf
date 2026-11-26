/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:17:21 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/26 01:03:18 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_printf_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_str(char *str)
{
	int	len;
	int	check;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	check = write(1, str, len);
	if (check == -1)
		return (-1);
	return (len);
}
