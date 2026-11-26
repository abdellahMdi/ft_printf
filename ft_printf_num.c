/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:59:11 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/26 01:15:35 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrchar(long k)
{
	if (k < 0)
	{
		k = -k;
		return (1 + nbrchar(k));
	}
	if (k > 9)
		return (1 + nbrchar(k / 10));
	return (1);
}

static int	nbrcharu(unsigned long k)
{
	if (k > 9)
		return (1 + nbrcharu(k / 10));
	return (1);
}

static char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		nlen;

	nb = n;
	nlen = nbrchar(nb);
	str = malloc((nlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	if (nb < 0)
	{
		str[0] = '-';
		n++;
		nb = -nb;
	}
	str[nlen--] = '\0';
	while (n <= nlen)
	{
		str[nlen--] = '0' + (nb % 10);
		nb = nb / 10 ;
	}
	return (str);
}

static char	*ft_itoau(unsigned int n)
{
	unsigned long	nb;
	char			*str;
	int				nlen;

	nb = n;
	nlen = nbrcharu(nb);
	str = malloc((nlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	str[nlen] = '\0';
	nlen--;
	while ((int)n <= nlen)
	{
		str[nlen--] = '0' + (nb % 10);
		nb = nb / 10 ;
	}
	return (str);
}

static int print_flags(int num, char flag)
{
	char to_print;

	if (num >= 0)
	{
		if (flag == '+')
			to_print = '+';
		else
			to_print = ' ';
	}
	else
		return (0);
	return (write(1, &to_print, 1));
}

int	ft_print_int(int num, unsigned int num1, int is_signed, char flag)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = NULL;
	if ((flag == '+' || flag == ' ') && is_signed == 1)
		i = print_flags(num, flag);
	if (is_signed == 1 && i != -1)
		str = ft_itoa(num);
	else if (i != -1)
		str = ft_itoau(num1);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	len = write (1, str, len);
	free(str);
	if (len == -1)
		return (-1);
	len += i;
	return (len);
}
