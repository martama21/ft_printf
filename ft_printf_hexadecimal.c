/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:29:35 by mmarina-          #+#    #+#             */
/*   Updated: 2026/09/19 18:29:37 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>//para las macros de _va_..
#include <stdint.h>// para uintptr_t

static char	hexadigit(int d)
{
	char	c;

	if (d == 10)
		c = 'a';
	else if (d == 11)
		c = 'b';
	else if (d == 12)
		c = 'c';
	else if (d == 13)
		c = 'd';
	else if (d == 14)
		c = 'e';
	else if (d == 15)
		c = 'f';
	else if (d < 10)
		c = (char)(d + 48);
	return (c);
}

static void	put_hexadecimal(unsigned long long n, int (*f)(int c))
{
	if (n >= 16)
	{
		put_hexadecimal(n / 16, f);
		put_hexadecimal(n % 16, f);
	}
	else
		ft_putchar_fd(f(hexadigit(n)), 1);
}

int	format_p(void *p)
{
	uintptr_t	dir;
	int			len;

	dir = (uintptr_t)p;
	len = 0;
	if (dir == 0)
	{
		ft_putstr_fd("(nil)", 1);
		len = 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		len += 2;
		put_hexadecimal((unsigned long long)dir, &ft_tolower);
		while (dir != 0)
		{
			len++;
			dir = dir / 16;
		}
	}
	return (len);
}

int	format_x(va_list arg)
{
	long int	hex;
	int			len;

	len = 0;
	hex = va_arg(arg, unsigned int);
	put_hexadecimal(hex, &ft_tolower);
	while (hex != 0)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}

int	format_x_capital(va_list arg)
{
	long int	hex;
	int			len;

	len = 0;
	hex = va_arg(arg, unsigned int);
	put_hexadecimal(hex, &ft_toupper);
	while (hex != 0)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}
