/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:23:15 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/12 17:21:03 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_inputs(char *str, va_list args)
{

}

int ft_printf(const char *format, ...)
{
    va_list args;
    char    *str;
    int nprinted;

    nprinted  = 0;
    if (format)
    {
        str = ft_strdup(format);
        va_start(args, format);
        nprinted += ft_print_inputs(str, args);
        va_end(args);
        free(str);
    }
    return (nprinted);
}
