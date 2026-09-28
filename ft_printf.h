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
# include <stdarg.h>//para las macros _va_...

char	*ft_uitoa(long int n);//en ft_uitoa.c
int		format_p(void *p);//en ft_printf_hexadecimal.c
int		format_x(va_list arg);//en ft_printf_hexadecimal.c
int		format_x_capital(va_list arg);//en ft_printf_hexadecimal.c
int		format_c(va_list arg);//en ft_printf_csdiu.c
int		format_s(va_list arg);//en ft_printf_csdiu.c
int		format_d(va_list arg);//en ft_printf_csdiu.c
int		format_u(va_list arg);//en ft_printf_csdiu.c
int		check_conversions(char type, va_list arg);//en ft_printf.c
int		len_without_conversions(char *format);
int		do_conversions(char *format, va_list arg_ptr, int *length_out);
int		good_conversions(char *str);
int		ft_printf(char const *format, ...);

#endif
