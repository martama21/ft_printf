/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:10:06 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:10:08 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*aux1;
	const unsigned char	*aux2;

	aux1 = (const unsigned char *)s1;
	aux2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (aux1[i] != aux2[i])
			return (aux1[i] - aux2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	unsigned char str1[40];
// 	unsigned char str2[70];
// 	int length;

// 	length = sizeof(str1) / sizeof(str1[0]);
// 	printf("str1: ");
// 	print_array(str1, length);

// 	length = sizeof(str2) / sizeof(str2[0]);
// 	printf("str2: ");
// 	print_array(str2, length);

// 	printf("ORIGINAL: %d\n", memcmp(str2, str1, 40));
// 	printf("MIO: %d\n", ft_memcmp(str2, str1, 40));

// 	return (0);
// }
