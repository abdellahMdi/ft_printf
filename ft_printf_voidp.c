int ft_write_pointer(unsigned long pointer)
{
    int len;
    int check;

    len = 0;
    check = write(1, "0x", 2);
    if (check == -1)
        return (check);
    len += 2;
    check = ft_printf_hexl(pointer);
    if (check == -1)
        return (check);
    len += check;
    return (len);
}

int ft_printf_voidp(void *ptr)
{
    unsigned long pointer;
    int len;

    len = 0;
    // if (ptr == NULL)
    // {
    //     len = write(1, "(nil)", 5);
    //         if (len == -1)
    //             return (len);
    //     return (5);
    // }
    if (ptr == NULL)
        return (write(1, "(nil)", 5));
    pointer = (unsigned long)ptr;
	len = ft_write_pointer(pointer);
    return (len);
}