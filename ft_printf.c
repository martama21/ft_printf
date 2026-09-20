/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 16:14:35 by mmarina-          #+#    #+#             */
/*   Updated: 2026/09/19 16:14:37 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>//para va_list ...
#include <stdio.h>//pal printf
#include <stdint.h>// para uintptr_t
#include <stdlib.h>//para malloc y free

int	check_conversions(char type, va_list arg)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = format_c(arg);
	if (type == 'd' || type == 'i')
		len = format_d(arg);
	if (type == 'u')
		len = format_u(arg);
	if (type == 's')
		len = format_s(arg);
	if (type == 'p')
		len = format_p(va_arg(arg, void *));
	if (type == 'x')
		len = format_x(arg);
	if (type == 'X')
		len = format_x_capital(arg);
	return (len);
}

int	len_without_conversions(char *format)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
		}
		else
			len++;
		if (format[i])
			i++;
	}
	return (len);
}

int	do_conversions(char *format, va_list arg_ptr, int *length_out)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				*length_out += 1;
				ft_putchar_fd('%', 1);
			}
			else
				*length_out += check_conversions(format[i + 1], arg_ptr);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	*length_out += len_without_conversions(format);
	return (*length_out);
}

int	good_conversions(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
				i++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg_ptr;
	int		len_out;

	len_out = 0;
	if (good_conversions((char *)format) < 0)
		return (-1);
	va_start(arg_ptr, format);
	do_conversions((char *)format, arg_ptr, &len_out);
	va_end(arg_ptr);
	return (len_out);
}

// int	main(void)
// {
// 	int				len;
// 	char			str[] = {'J', 'U', 'A', 'N', 'A'};
// 	char			*d = "1237";
// 	int				dec;
// 	unsigned int	hex;

// 	hex = 0x7FFE3445;
// 	len = ft_printf("prueba MIOginal %ce%dntral%%r:
// %s %p %d ", 97, 343536, str, d, 0);
// 	if (len < 0)
// 		return (1);//nose si se tiene que cambiar la salida a salida de errores.
// 	printf("| len: %d\n", len);
// 	len = printf("prueba original %ce%dntral%%r:
// %s %p %d ", 97, 343536, str, d, 0);
// 	printf("| len: %d\n", len);
// 	printf("________________\n");
// 	len = ft_printf("(c) MIOginal: %ciem%cre %cg%ca%c%c.%%", 
// 		's', 'p', 'i', 'u', 'l', '*');
// 	printf(" | len: %d\n", len);
// 	len = printf("(c) original: %ciem%cre %cg%ca%c%c.%%", 
// 's', 'p', 'i', 'u', 'l', '*');
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(s) MIOginal: %s %s%s.", 
// "Todo eso", "que tanto", " nos gusta.");
// 	printf(" | len: %d\n", len);
// 	len = printf("(s) original: %s %s%s.", 
// "Todo eso", "que tanto", " nos gusta.");
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(d) (i) MIOginal: d:%d.i:%i", 456, -2763);
// 	printf(" | len: %d\n", len);
// 	len = printf("(d) (i) original: d:%d.i:%i", 456, -2763);
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(u) MIOginal: -2:%u|2:%u|0:%u", -2, 2, 0);
// 	printf(" | len: %d\n", len);
// 	len = printf("(u) original: -2:%u|2:%u|0:%u", -2, 2, 0);
// 	printf(" | len: %d\n", len);
// 	printf("________________\n");
// 	dec = 1237;
// 	len = ft_printf("(p) MIOginal (str) : %p", d);
// 	printf(" | len_printf: %d\n", len);
// 	printf("original (int)puntero: %p\n", &dec);
// 	//*p_aux = &((unsigned char *)d);
// 	//printf("original (char *)puntero (%p): %d\n", d, (int)p_aux);
// 	len = printf("original (str) : %p\n", d);
// 	printf("len_printf: %d\n", len);
// 	len = printf("(p) original vacio: %p", NULL);
// 	printf(" | len : %d\n", len);
// 	len = ft_printf("(p) MIOginal vacio: %p", NULL);
// 	printf(" | len : %d\n", len);
// 	printf("(d) original -2.5: %d\n", -5/2);
// 	ft_printf("(d) MIOginal -2.5: %d\n", -5/2);
// 	printf("(i) original -2.5: %i\n", -5/2);
// 	len = printf("(u) original -2.5: %u ", -23846827);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(u) MIOginal -2.5: %u ", -23846827);
// 	printf("| len: %d\n", len);
// 	len = printf("(x) original : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(x) MIOginal : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = printf("(X) original : %X ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(X) MIOginal : %X ", hex);
// 	printf("| len: %d\n", len);
// 	return (0);
// }

// //MAIN PARA PROBAR FORMATOS: %p, %x, %X
// int	main(void)
// {
// 	int				len;
// 	char			*d = "1237";
// 	int				dec;
// 	unsigned int	hex;

// 	hex = 0x7FFE3445;
// 	dec = 1237;
// 	len = ft_printf("MIOginal (str) : %p\n", d);
// 	printf("len_printf2: %d\n", len);
// 	printf("original (int)puntero: %p\n", &dec);
// 	//*p_aux = &((unsigned char *)d);
// 	//printf("original (char *)puntero (%p): %d\n", d, (int)p_aux);
// 	len = printf("original (str) : %p\n", d);
// 	printf("len_printf: %d\n", len);
// 	len = printf("(p) original vacio: %p", NULL);
// 	printf(" | len : %d\n", len);
// 	len = ft_printf("(p) MIOginal vacio: %p", NULL);
// 	printf(" | len : %d\n", len);
// 	len = printf("(x) original : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(x) MIOginal : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = printf("(X) original : %X ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(X) MIOginal : %X ", hex);
// 	printf("| len: %d\n", len);
// 	return (0);
// }

// int	main(void)
// {
// 	int				len;
// 	int				len2;
// 	char			str[] = {'J', 'U', 'A', 'N', 'A'};
// 	char			*d = "1237";
// 	int				dec;
// 	unsigned int	hex;

// 	hex = 0x7FFE3445;
// 	//unsigned char *p_aux;

// 	//printf("length (%s) : %ld\n", str, ft_strlen(str));
// 	//ft_printf("prueba %central", c);
// 	//len = ft_printf("prueba MIA %ce%dntral%%r", 97, 343536);
// 	// len = ft_printf("prueba MIA %ce%dntral%%r : %s", 97, 343536, "prueba s");

// 	//c = (unsigned char *)ft_strdup("str_dup");

// 	//d = 97;
// 	//len = ft_printf("prueba MIA %ce%dntral%%r: 
// %s %d %p", 97, 343536, str, 10, c);
// 	len = ft_printf("prueba MIA %ce%dntral%%r: 
// %s %p %d", 97, 343536, str, d, 0);
// 	if (len < 0)
// 		return (1);//nose si se tiene que cambiar la salida a salida de errores.
// 	printf("\nlen MIO: %d\n", len);
// 	len = printf("prueba %ce%dntral%%r\n", 'c', 325);
// 	printf("len_printf: %d\n", len);
// 	dec = 1237;
// 	len2 = ft_printf("MIOginal (str) : %p\n", d);
// 	printf("len_printf2: %d\n", len2);
// 	printf("original (int)puntero: %p\n", &dec);
// 	//*p_aux = &((unsigned char *)d);
// 	//printf("original (char *)puntero (%p): %d\n", d, (int)p_aux);
// 	len = printf("original (str) : %p\n", d);
// 	printf("len_printf: %d\n", len);
// 	len = printf("(p) original vacio: %p", NULL);
// 	printf(" | len : %d\n", len);
// 	len = ft_printf("(p) MIOginal vacio: %p", NULL);
// 	printf(" | len : %d\n", len);
// 	printf("(d) original -2.5: %d\n", -5/2);
// 	ft_printf("(d) MIOginal -2.5: %d\n", -5/2);
// 	printf("(i) original -2.5: %i\n", -5/2);
// 	len = printf("(u) original -2.5: %u ", -23846827);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(u) MIOginal -2.5: %u ", -23846827);
// 	printf("| len: %d\n", len);
// 	len = printf("(x) original : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(x) MIOginal : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = printf("(X) original : %X ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(X) MIOginal : %X ", hex);
// 	printf("| len: %d\n", len);
// 	return (0);
// }