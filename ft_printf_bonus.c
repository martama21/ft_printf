/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 12:38:38 by mmarina-          #+#    #+#             */
/*   Updated: 2026/10/02 12:38:40 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_bonus(va_list arg, char type, char specifier)
{
    int len;

    len = 0;
    if (type == '#')
        len = format_asterisk(arg, specifier);
    // if (type  == ' ')
    //     len = format_space(arg);
    // if (type == '+')
    //     len = format_plus(arg);
    if (type == ' ' || type == '+')
        len = format_space_or_plus(arg, type);
    return (len);
}

int format_space_or_plus(va_list arg, char type)
{
    int d;

    d = va_arg(arg, int);
    if (d < 0)
    {
        return (format_d(d));
    }
    ft_putchar_fd(type, 1);
    return (format_d(d) + 1);
}

void    print_hexadecimal(unsigned int hex, char specifier)
{
    if (specifier == 'x')
        put_hexadecimal(hex, &ft_tolower);
    if (specifier == 'X')
        put_hexadecimal(hex, &ft_toupper);
}

int format_asterisk(va_list arg, char specifier)
{
    unsigned int	hex;
	int				len;

	len = 0;
	hex = va_arg(arg, unsigned int);
	if (hex == 0)
    {
        print_hexadecimal(hex, specifier);
        return (1);
    }
    ft_putstr_fd("0x", 1);
    len += 2;
    print_hexadecimal(hex, specifier);
	while (hex != 0)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}

int format_space(va_list arg)
{
    int d;

    d = va_arg(arg, int);
    if (d < 0)
    {
        return (format_d(d));
    }
    ft_putchar_fd(' ', 1);
    return (format_d(d) + 1);
}
