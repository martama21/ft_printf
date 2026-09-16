#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>//para va_list ...
#include <stdio.h>//pal printf
#include <stdint.h>// para uintptr_t
#include <stdlib.h>//para malloc y free

// void print_digit(int d)
// {
// 	if (d == 10)
// 		ft_putchar_fd('a', 1);
// 	else if (d == 11)
// 		ft_putchar_fd('b', 1);
// 	else if (d == 12)
// 		ft_putchar_fd('c', 1);
// 	else if (d == 13)
// 		ft_putchar_fd('d', 1);
// 	else if (d == 14)
// 		ft_putchar_fd('e', 1);
// 	else if (d == 15)
// 		ft_putchar_fd('f', 1);
// 	else if (d < 10)
// 		ft_putchar_fd((char)(d + 48), 1);
// }

char hexadigit(int d)
{
	char c;
	
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
	return c;
}

void put_hexadecimal(unsigned long long n)
{
	if (n >= 16)
	{
		put_hexadecimal(n / 16);
		put_hexadecimal(n % 16);
	}
	else
		//print_digit(n);
		ft_putchar_fd(hexadigit(n), 1);
}

int conversion_p(void *p)
{
	uintptr_t dir;
	int len;

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
		put_hexadecimal((unsigned long long)dir);
		while (dir != 0)
		{
			len++;
			dir = dir / 16;
		}
	}
	return (len);
}

int format_c(va_list arg)
{
	ft_putchar_fd(va_arg(arg, int), 1);
	return 1;
}

int conversion_s(va_list arg)
{
	char *str;

	str = ft_strdup(va_arg(arg, char*));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int format_d(va_list arg)
{
	int d;

	d = va_arg(arg, int);
	ft_putnbr_fd(d, 1);
	return (ft_strlen(ft_itoa(d)));
}



// int format_u(va_list arg)
// {
// 	unsigned int ud;

// 	ud = (unsigned int)va_arg(arg, unsigned int);
// 	printf(" (ud: %d) ", ud);
// 	ft_putnbr_fd((unsigned int)ud, 1);
// 	return (ft_strlen(ft_itoa(ud)));
// }

int format_u(va_list arg)
{
	long int d;
	char *str_num;
	int len;

	d = va_arg(arg, int);
	
	if (d < 0)
	{
		d = 4294967296 + d;
		str_num = ft_uitoa(d);
		ft_putstr_fd(str_num, 1);
		len = ft_strlen(str_num);
		free(str_num);
		//ft_putnbr_fd((unsigned int)d, 1);
		return (len);
	}
	//printf(" (ud: %d) ", d);
	else
		ft_putnbr_fd((unsigned int)d, 1);
	return (ft_strlen(ft_itoa(d)));
}

int format_x(va_list arg)
{
	long int hex;
	int len;

	len = 0;
	hex = va_arg(arg, unsigned int);
	put_hexadecimal(hex);
	//printf("hex: %ld ", hex);
	//printf("| itoa : %s", ft_itoa(hex));
	while (hex != 0)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}

void put_hexadecimal_capital(unsigned long long n)
{
	if (n >= 16)
	{
		put_hexadecimal(n / 16);
		put_hexadecimal(n % 16);
	}
	else
		//print_digit(n);
		ft_putchar_fd(ft_toupper(hexadigit(n)), 1);
}

int format_x_capital(va_list arg)
{
	long int hex;
	int len;

	len = 0;
	hex = va_arg(arg, unsigned int);
	//put_hexadecimal(hex);
	put_hexadecimal_capital(hex);
	while (hex != 0)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}

int check_conversions(char type, va_list arg)
{
	//char c;
	//int d;
	//char *str;
	int len;

	len = 0;
	if (type == 'c')
	{
		len = format_c(arg);
	}	
	if (type == 'd' || type == 'i')
	{
		// d = va_arg(arg, int);
		// ft_putnbr_fd(d, 1);
		// len = ft_strlen(ft_itoa(d));
		len = format_d(arg);
	}
	if (type == 'u')
		len = format_u(arg);
	if (type == 's')
	{
		// str = ft_strdup(va_arg(arg, char*));
		// ft_putstr_fd(str, 1);
		// len = ft_strlen(str);
		//return ()
		len = conversion_s(arg);
	}
	if (type == 'p')
	{
		len = conversion_p(va_arg(arg, void *));
	}
	if (type == 'x')
		len = format_x(arg);
	if (type == 'X')
		len = format_x_capital(arg);
	return (len);
}

int len_without_conversions(char *format)
{
	int i;
	int len;

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
	//printf("len_without: %d\n", len);
	return (len);
}

int do_conversions(char *format, va_list arg_ptr, int *length_out)
{
	int i;

	i = 0;	
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i+1] == '%')
			{
				*length_out += 1;
				ft_putchar_fd('%', 1);
			}
			else
				*length_out += check_conversions(format[i+1], arg_ptr);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	*length_out += len_without_conversions(format);
	return (*length_out);
}

int good_conversions(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i+1] && ft_strchr("cspdiuxX%", str[i+1]))
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
	va_list arg_ptr;
	int len_out;

	
	len_out = 0;
	if (good_conversions((char *)format) < 0)
		return (-1);
	va_start(arg_ptr, format);//inicializamos la lista
	do_conversions((char *)format, arg_ptr, &len_out);
	
	va_end(arg_ptr);
	return (len_out);
}

int	main(void)
{
	//char str[] = "esro.";
	int len;
	int len2;
	char str[] = {'J', 'U', 'A', 'N', 'A'};
	//unsigned char *c;
	//int d;
	char *d = "1237";
	int dec;
	unsigned int hex;

	hex = 0x7FFE3445;
	//unsigned char *p_aux;

	//printf("length (%s) : %ld\n", str, ft_strlen(str));
	//ft_printf("prueba %central", c);
	//len = ft_printf("prueba MIA %ce%dntral%%r", 97, 343536);
	// len = ft_printf("prueba MIA %ce%dntral%%r : %s", 97, 343536, "prueba s");
	
	//c = (unsigned char *)ft_strdup("str_dup");
	
	//d = 97;
	//len = ft_printf("prueba MIA %ce%dntral%%r: %s %d %p", 97, 343536, str, 10, c);
	len = ft_printf("prueba MIA %ce%dntral%%r: %s %p %d", 97, 343536, str, d, 0);
	if (len < 0)
		return (1);//nose si se tiene que cambiar la salida a salida de errores.
	printf("\nlen MIO: %d\n", len);
	len = printf("prueba %ce%dntral%%r\n", 'c', 325);
	printf("len_printf: %d\n", len);
	dec = 1237;
	len2 = ft_printf("MIOginal (str) : %p\n", d);
	printf("len_printf2: %d\n", len2);
	printf("original (int)puntero: %p\n", &dec);
	//*p_aux = &((unsigned char *)d);
	//printf("original (char *)puntero (%p): %d\n", d, (int)p_aux);
	len = printf("original (str) : %p\n", d);
	printf("len_printf: %d\n", len);
	len = printf("(p) original vacio: %p", NULL);
	printf(" | len : %d\n", len);
	len = ft_printf("(p) MIOginal vacio: %p", NULL);
	printf(" | len : %d\n", len);
	printf("(d) original -2.5: %d\n", -5/2);
	ft_printf("(d) MIOginal -2.5: %d\n", -5/2);
	printf("(i) original -2.5: %i\n", -5/2);
	len = printf("(u) original -2.5: %u ", -23846827);
	printf("| len: %d\n", len);
	len = ft_printf("(u) MIOginal -2.5: %u ", -23846827);
	printf("| len: %d\n", len);
	len = printf("(x) original : %x ", hex);
	printf("| len: %d\n", len);
	len = ft_printf("(x) MIOginal : %x ", hex);
	printf("| len: %d\n", len);
	len = printf("(X) original : %X ", hex);
	printf("| len: %d\n", len);
	len = ft_printf("(X) MIOginal : %X ", hex);
	printf("| len: %d\n", len);
	return (0);
}