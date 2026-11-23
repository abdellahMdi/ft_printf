static int	nbr_hex_char(long k)
{
	if (k >= 16)
		return (1 + nbr_hex_char(k / 16));
	return (1);
}

int	ft_printf_hex(unsigned int n, char format)
{
	int		len;
	char	*str;
	char	*hex;

	if (format == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = nbr_hex_char(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n >= 16)
	{
		str[len - 1] = hex[n % 16];
		n /= 16;
		len--;
	}
	str[len - 1] = hex[n];
	len = ft_printf_str(str);
	free(str);
	return (len);
}
