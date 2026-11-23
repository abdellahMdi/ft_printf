int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_printf_char(char c)
{
    int check;

    check = write(1, &c, 1);
    return (check);
}

int ft_printf_str(char *str)
{
    int len;
    int check;

    len = ft_strlen(str);
    check = write(1, str, len);
    if (check == -1)
        return (check);
    return (len);
}