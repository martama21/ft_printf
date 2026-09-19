/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:22:25 by mmarina-          #+#    #+#             */
/*   Updated: 2026/09/19 18:22:27 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>//para el size_t
#include <stdarg.h>//para las macros _va_...

char	*ft_uitoa(long int n);//en ft_uitoa.c
int	format_p(void *p);//en ft_printf_hexadecimal.c
int	format_x(va_list arg);//en ft_printf_hexadecimal.c
int	format_x_capital(va_list arg);//en ft_printf_hexadecimal.c

#endif
