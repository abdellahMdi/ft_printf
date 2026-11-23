/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:59:11 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/12 21:51:18 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

char	*ft_itoa(int n)
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

int ft_print_int(int num)
{
    int i;
    int len;
    char *str;
    
    str = ft_itoa(num);
	if (!str)
		return (-1);
    len = ft_strlen(str);
    i = write (1, str, len);
    free(str);
    if (i == -1)
        return (-1);
    return (len);
}