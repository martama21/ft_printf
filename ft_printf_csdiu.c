/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdiu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 19:34:28 by mmarina-          #+#    #+#             */
/*   Updated: 2026/09/19 19:34:30 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>//para malloc y free
#include <stdarg.h>//para las macros de _va_..
//#include <stdint.h>// para uintptr_t

int	format_c(va_list arg)
{
	ft_putchar_fd(va_arg(arg, int), 1);
	return (1);
}

int	format_s(va_list arg)
{
	char	*str;

	str = ft_strdup(va_arg(arg, char *));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	format_d(va_list arg)
{
	int	d;

	d = va_arg(arg, int);
	ft_putnbr_fd(d, 1);
	return (ft_strlen(ft_itoa(d)));
}

int	format_u(va_list arg)
{
	long int	d;
	char		*str_num;
	int			len;

	d = va_arg(arg, int);
	if (d < 0)
	{
		d = 4294967296 + d;
		str_num = ft_uitoa(d);
		ft_putstr_fd(str_num, 1);
		len = ft_strlen(str_num);
		free(str_num);
		return (len);
	}
	else
		ft_putnbr_fd((unsigned int)d, 1);
	return (ft_strlen(ft_itoa(d)));
}
