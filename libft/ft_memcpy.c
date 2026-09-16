/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:46:37 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:46:39 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <stddef.h>
#include "libft.h"

//¿¿¿¿¿¿¿¿¿¿ CÓMO CONTROLAR OVERLOAP ??????????????
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
//void	*memcpy(void dest[restrict .n], const void src[restrict .n], size_t n)
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*aux_src;
	unsigned char		*aux_dest;
	size_t				i;

	i = 0;
	if (!dest && !src && n != 0)
		return (NULL);
	aux_src = src;
	aux_dest = dest;
	while (i < n)
	{
		aux_dest[i] = aux_src[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	char src[] = "abcdef";
// 	char dest[4];
// 	int length;
// 	length = sizeof(src) / sizeof(src[0]);
// 	printf("src: ");
// 	print_array(src, length);
// 	printf("dest: ");
// 	print_array(dest, length);
// 	printf("src + 2: ");
// 	print_array(src + 2, length - 2);

// 	//PRUEBAS
// 	//memcpy(src + 2, src, 4);
// 	//ft_memcpy(src + 2, src, 4);
// 	printf("with NULL: %p\n", ft_memcpy(NULL, src, 6));
// 	//memcpy(, src, 4);
// 	printf("MIO: ");
// 	print_array(src, length);
// 	printf("src : %s\n", src);
// 	//printf("src + 2: %s\n", src + 2);

// 	return (0);
// }

// int	main(void)
// {
// 	unsigned char src[10];
// 	unsigned char dest[10];
// 	int length;
// 	length = sizeof(src) / sizeof(src[0]);
// 	printf("src: ");
// 	print_array(src, length);
// 	printf("dest: ");
// 	print_array(dest, length);

// 	//PRUEBAS
// 	//ft_memcpy(dest + 2, dest, 7);
// 	//memcpy(dest + 2, dest, 7);
// 	printf("MIO: ");
// 	print_array(dest, length);

// 	//MAS PRUEBAS
// 	ft_bzero(src, length);
// 	ft_bzero(dest, length);
// 	printf("____________\nA ZERO:\nsrc: ");
// 	print_array(src, length);
// 	printf("dest: ");
// 	print_array(dest, length);
// 	printf("_________\n");
// 	ft_memcpy(dest, src, 7);
// 	printf("MIO: ");
// 	print_array(dest, length);
// 	printf("--------------------------\n");
// 	ft_memcpy(dest, src, 4);
// 	printf("MIO: ");
// 	print_array(dest, length);
// 	// if (!dest)
// 	// 	printf("NO HAY NA\n");
// 	return (0);
// }
