/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:49:29 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:49:31 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <stddef.h>
#include "libft.h"

// void print_array(void *s, int length)
// {
// 	int	n;
// 	unsigned char *aux;

// 	n = 0;
// 	aux = s;
// 	while (n < length)
// 	{
// 		printf("%u,", aux[n]);
// 		n++;
// 	}
// 	printf("\n");
// }

//void	*memmove(void dest[.n], const void src[.n], size_t n)
// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	const unsigned char *aux_src;
// 	unsigned char *aux_dest;
// 	unsigned char temporary_arr[n];
// 	size_t i;

// 	i = 0;
// 	aux_src = src;
// 	aux_dest = dest;
// 	while (i < n)
// 	{
// 		temporary_arr[i] = aux_src[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		aux_dest[i] = temporary_arr[i];
// 		i++;
// 	}
// 	return (dest);
// }

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	const unsigned char	*aux_src;
// 	unsigned char		*aux_dest;
// 	size_t				i;

// 	i = 0;
// 	if (!dest && !src && n != 0)
// 		return (NULL);
// 	aux_src = src;
// 	aux_dest = dest;
// 	if (aux_dest > aux_src)
// 	{
// 		while (n > 0)
// 		{
// 			aux_dest[n - 1] = aux_src[n - 1];
// 			n--;
// 		}
// 	}
// 	else
// 	{
// 		while (i < n)
// 		{
// 			aux_dest[i] = aux_src[i];
// 			i++;
// 		}
// 	}
// 	return (dest);
// }

static void	add_end(unsigned char *dest, const unsigned char *src, size_t n)
{
	while (n > 0)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*aux_src;
	unsigned char		*aux_dest;
	size_t				i;

	i = 0;
	if (!dest && !src && n != 0)
		return (NULL);
	aux_src = src;
	aux_dest = dest;
	if (aux_dest > aux_src)
	{
		add_end(aux_dest, aux_src, n);
	}
	else
	{
		while (i < n)
		{
			aux_dest[i] = aux_src[i];
			i++;
		}
	}
	return (dest);
}

// int main(void)
// {
// 	char src[] = "12345";
// 	char dest[4];
// 	int length;

// 	length = sizeof(src) / sizeof(src[0]);
// 	printf("src: ");
// 	print_array(src, length);
// 	printf("dest: ");
// 	print_array(dest, length);
// 	printf("src + 1: ");
// 	print_array(src + 1, length - 1);

// 	//PRUEBAS
// 	//memcpy(src + 2, src, 4);

// 	printf("src: 	(%s)\nsrc + 1: (%s)\n", src, src + 1);
// 	ft_memmove(src, src + 2, 4);
// 	printf("MIO: ");
// 	print_array(src, length);
// 	printf("src : %s\n", src);
// 	//printf("src + 2: %s\n", src + 2);

// 	return (0);
// }

// int	main(void)
// {
// 	unsigned char src[20];
// 	unsigned char dest[20];
// 	int length;

// 	length = sizeof(src) / sizeof(src[0]);
// 	printf("src: ");
// 	print_array(src, length);
// 	printf("dest: ");
// 	print_array(dest, length);

// 	//PRUEBASS
// 	printf("MIO: ");
// 	ft_memmove(dest, src, 15);
// 	print_array(dest, length);
// 	return (0);
// }
