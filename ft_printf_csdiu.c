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
	int		len;

	str = ft_strdup(va_arg(arg, char *));
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	format_d(va_list arg)
{
	int		d;
	char	*str_num;
	int		len;

	d = va_arg(arg, int);
	ft_putnbr_fd(d, 1);
	str_num = ft_itoa(d);
	len = ft_strlen(str_num);
	free(str_num);
	return (len);
}

int	format_u(va_list arg)
{
	long int	d;
	char		*str_num;
	char		*str_num2;
	int			len;
	int			len2;

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
	str_num2 = ft_itoa(d);
	len2 = ft_strlen(str_num2);
	free(str_num2);
	return (len2);
}
