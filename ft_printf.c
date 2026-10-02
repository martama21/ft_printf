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

// #include <stdio.h>
// #include "libft/libft.h"
#include "ft_printf.h"
// #include <stdarg.h>//para va_list ...
// #include <stdio.h>//pal printf
// #include <stdint.h>// para uintptr_t
// #include <stdlib.h>//para malloc y free

// int	check_conversions(char type, va_list arg)
// {
// 	int	len;

// 	len = 0;
// 	if (type == 'c')
// 		len = format_c(arg);
// 	if (type == 'd' || type == 'i')
// 		len = format_d(arg);
// 	if (type == 'u')
// 		len = format_u(arg);
// 	if (type == 's')
// 		len = format_s(arg);
// 	if (type == 'p')
// 		len = format_p(va_arg(arg, void *));
// 	if (type == 'x')
// 		len = format_x(arg);
// 	if (type == 'X')
// 		len = format_x_capital(arg);
// 	return (len);
// }

int	check_conversions(char *format, int *i, va_list arg)
{
	int	len;

	len = 0;
	if (format[*i] == 'c')
		len = format_c(arg);
	if (format[*i] == 'd' || format[*i] == 'i')
		len = format_d(va_arg(arg, int));
		//len = format_d(arg);
	if (format[*i] == 'u')
		len = format_u(arg);
	if (format[*i] == 's')
		len = format_s(arg);
	if (format[*i] == 'p')
		len = format_p(va_arg(arg, void *));
	if (format[*i] == 'x')
		len = format_x(arg);
	if (format[*i] == 'X')
		len = format_x_capital(arg);
	if (format[*i] == '%')
		len = format_percentage();
	if (format[*i] == '#' || format[*i] == ' ' || format[*i] == '+')
	{
		len = format_bonus(arg, format[*i], format[(*i) + 1]);
		*i += 1;
	}
	// if (format[*i] == '#')
	// 	len = format_asterisk(arg);
	// if (format[i] == ' ')
	// 	len = format_space(arg);
	// if (format[i] == '+')
	// 	len = format_plus(arg);
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

// int	do_conversions(char *format, va_list arg_ptr, int *length_out)
// {
// 	int	i;

// 	i = 0;
// 	while (format[i] != '\0')
// 	{
// 		if (format[i] == '%')
// 		{
// 			if (format[i + 1] == '%')
// 			{
// 				*length_out += 1;
// 				ft_putchar_fd('%', 1);
// 			}
// 			else
// 				*length_out += check_conversions(format[i + 1], arg_ptr);
// 			i++;
// 		}
// 		else
// 			ft_putchar_fd(format[i], 1);
// 		i++;
// 	}
// 	*length_out += len_without_conversions(format);
// 	return (*length_out);
// }

int	do_conversions(char *format, va_list arg_ptr, int *length_out)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			//*length_out += check_conversions(format[i + 1], arg_ptr);
			i++;
			*length_out += check_conversions(format, &i, arg_ptr);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			*length_out += 1;
		}
		i++;
	}
	//*length_out += len_without_conversions(format);
	return (*length_out);
}

int	check_bonus(char *format, int *i)
{
	if (format[*i + 1] == '#')
	{
		if (format[*i + 2] != 'x' && format[*i + 2] != 'X')
			return (-1);
	}
	if (format[*i + 1] == ' ' || format[*i + 1] == '+')
	{
		if (format[*i + 2] != 'd' && format[*i + 2] != 'i')
			return (-1);
	}
	*i += 1;
	return (0);
}

// int	good_conversions(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '%')
// 		{
// 			if (str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
// 				i++;
// 			else
// 				return (-1);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	good_conversions(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] && ft_strchr("cspdiuxX%# +", str[i + 1]))
			{
				if (check_bonus(str, &i) < 0)
					return (-1);
				i++;
			}
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

int	main(void)
{
	int				i;
	int				len;
	//unsigned int	hex;

	i = -23;
	len = printf("(%%#x) original (%d): (%#x)", -23, -23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%%#x) MIOginal (%d): (%#x)", -23, -23);
	printf(" | len: %d\n", len);
	printf("------------------\n");
	len = printf("(%%#x) original (%d): (%#x)", 23, 23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%%#x) MIOginal (%d): (%#x)", 23, 23);
	printf(" | len: %d\n", len);
	printf("------------------\n");
	len = printf("(%%#X) original (%d): (%#X)", -23, -23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%%#X) MIOginal (%d): (%#X)", -23, -23);
	printf(" | len: %d\n", len);
	printf("------------------\n");
	len = printf("(%%#X) original (%d): (%#X)", 23, 23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%%#X) MIOginal (%d): (%#X)", 23, 23);
	printf(" | len: %d\n", len);
	printf("------------------\n");

	len = printf("(%% d) || (%% i) original (%d): (% d)", -23, -23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%% d) || (%% i) MIOginal (%d): (% d)", -23, -23);
	printf(" | len: %d\n", len);
	printf("------------------\n");
	len = printf("(%% d) || (%% i) original (%d): (% d)", 23, 23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%% d) || (%% i) MIOginal (%d): (% d)", 23, 23);
	printf(" | len: %d\n", len);
	printf("------------------\n");
	len = printf("(%%+d) || (%%+i) original (%d): (%+i)", 23, 23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%%+d) || (%%+i) MIOginal (%d): (%+i)", 23, 23);
	printf(" | len: %d\n", len);
	printf("------------------\n");
	len = printf("(%%+d) || (%%+i) original (%d): (%+i)", -23,-23);
	printf(" | len: %d\n", len);
	len = ft_printf("(%%+d) || (%%+i) MIOginal (%d): (%+i)", -23,-23);
	printf(" | len: %d\n", len);
	return (0);
}

// int	main(void)
// {
// 	int				len;
// 	char			str[] = {'J', 'U', 'A', 'N', 'A'};
// 	char			*d = "1237";
// 	unsigned int	hex;
// 	int				x;
// 	void			*ptr = &x;
// 	char			*str2;

// 	len = ft_printf("prueba MIOginal %ce%dntral%%r:
// %s %p %d ", 97, 343536, str, d, 0);
// 	if (len < 0)
// 		return (1);//nose si se tiene que cambiar la salida a salida de errores.
// 	printf("| len: %d\n", len);
// 	len = printf("prueba original %ce%dntral%%r:
// %s %p %d ", 97, 343536, str, d, 0);
// 	printf("| len: %d\n", len);
// 	printf("________________\n");
// 	printf("PRUEBAS ESPECEFICADOR *%%c*:\n");
// 	len = ft_printf("(c) MIOginal: %ciem%cre 
// %cg%ca%c%c.%%", 's', 'p', 'i', 'u', 'l', '*');
// 	printf(" | len: %d\n", len);
// 	len = printf("(c) original: %ciem%cre 
// %cg%ca%c%c.%%", 's', 'p', 'i', 'u', 'l', '*');
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(c) MIOginal (int): %c", 35);
// 	printf(" | len: %d\n", len);
// 	len = printf("(c) original (int): %c", 35);
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(c) MIOginal (NUL): %c", '\0');
// 	printf(" | len: %d\n", len);
// 	len = printf("(c) original (NUL): %c", '\0');
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(c) MIOginal (nothin): %c");
// 	printf(" | len: %d\n", len);
// 	// len = printf("(c) original (nothing): %c");//error compilacion
// 	// printf(" | len: %d\n", len);
// 	printf("________________\n");
// 	printf("PRUEBAS ESPECEFICADOR *%%s*:\n");
// 	len = ft_printf("(s) MIOginal: %s %s%s.", 
// "Probando", "varios", " strs juntos.");
// 	printf(" | len: %d\n", len);
// 	len = printf("(s) original: %s %s%s.", 
// "Probando", "varios", " strs juntos.");
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(s) MIOginal (NULL): %s.", NULL);
// 	printf(" | len: %d\n", len);
// 	// len = printf("(s) original (NULL): %s.", NULL);//ERROR COMPILACION
// 	// printf(" | len: %d\n", len);
// 	// len = ft_printf("(s) MIOginal (int): %s.", 6);//ERROR EJECUCION
// 	// printf(" | len: %d\n", len);
// 	printf("________________\n");
// 	printf("PRUEBAS ESPECEFICADORES *%%d* e *%%i*:\n");
// 	len = ft_printf("(d) (i) MIOginal: d:%d.i:%i", 456, -2763);
// 	printf(" | len: %d\n", len);
// 	len = printf("(d) (i) original: d:%d.i:%i", 456, -2763);
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(d) (i) MIOginal (NULL): d:%d.", NULL);
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(d) (i) MIOginal (nothing): d:%d.");
// 	printf(" | len: %d\n", len);
// 	printf("________________\n");
// 	printf("PRUEBAS ESPECEFICADOR *%%u*:\n");
// 	len = ft_printf("(u) MIOginal: -2:%u|2:%u|0:%u", -2, 2, 0);
// 	printf(" | len: %d\n", len);
// 	len = printf("(u) original: -2:%u|2:%u|0:%u", -2, 2, 0);
// 	printf(" | len: %d\n", len);
// 	printf("________________\n");
// 	printf("PRUEBAS ESPECEFICADOR *%%p*:\n");
// 	len = ft_printf("(p) MIOginal: %p", ptr);
// 	printf(" | len: %d\n", len);
// 	len = printf("(p) original: %p", ptr);
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(p) MIOginal (NULL) : %p", NULL);
// 	printf(" | len: %d\n", len);
// 	len = printf("(p) original (NULL) : %p", NULL);
// 	printf(" | len: %d\n", len);
// 	str2 = "1237";
// 	len = ft_printf("(p) MIOginal (str) : %p", str2);
// 	printf(" | len: %d\n", len);
// 	len = printf("(p) original (str) : %p", str2);
// 	printf(" | len: %d\n", len);
// 	len = ft_printf("(p) MIOginal (nothing) : %p");
// 	printf(" | len: %d\n", len);
// 	//len = printf("(p) original (nothing) : %p");//error de compilacion
// 	//printf(" | len_printf: %d\n", len);
// 	len = ft_printf("(p) MIOginal (char) : %p", 'f');
// 	printf(" | len_printf: %d\n", len);
// 	// len = printf("(p) original (char) : %p" ,'f');//error de compilacion
// 	// printf(" | len_printf: %d\n", len);
// 	printf("________________\n");
// 	printf("(d) original -2.5: %d\n", -5/2);
// 	ft_printf("(d) MIOginal -2.5: %d\n", -5/2);
// 	printf("(i) original -2.5: %i\n", -5/2);
// 	len = printf("(u) original -2.5: %u ", -23846827);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(u) MIOginal -2.5: %u ", -23846827);
// 	printf("| len: %d\n", len);
// 	printf("________________\n");
// 	printf("PRUEBAS ESPECEFICADORES *%%x* y *%%X*:\n");
// 	hex = 0x7FFE3445;
// 	len = printf("(x) original : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(x) MIOginal : %x ", hex);
// 	printf("| len: %d\n", len);
// 	len = printf("(X) original : %X ", hex);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(X) MIOginal : %X ", hex);
// 	printf("| len: %d\n", len);
// 	len = printf("(x) original (0): %x ", 0);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(x) MIOginal (0): %x ", 0);
// 	printf("| len: %d\n", len);
// 	len = printf("(X) original (25): %X ", 25);
// 	printf("| len: %d\n", len);
// 	len = ft_printf("(X) MIOginal (25): %X ", 25);
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