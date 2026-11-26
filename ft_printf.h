/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdemahm <abdemahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:04:02 by abdemahm          #+#    #+#             */
/*   Updated: 2026/11/26 01:28:11 by abdemahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_print_inputs(const char *str, va_list args);
int		check_type(char c);
int		ft_handler(char type, char flag, va_list args);
int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_voidp(void *ptr);
int		ft_print_int(int num, unsigned int num1, int is_signed, char flag);
int		ft_printf_hex(unsigned int n, char format, char flag);
int		ft_printf_hexl(unsigned long n);
int		ft_strlen(char *str);

#endif