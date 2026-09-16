/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:53:44 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:53:45 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <stddef.h>
#include "libft.h"

// size_t ft_strlen(const char *s)
// {
// 	size_t n;

// 	n = 0;
// 	while (s[n] != '\0')
// 		n++;
// 	return (n);
// }

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	dest_length;
	size_t	src_length;

	n = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (dest_length >= size)
		return (size + src_length);
	while (src[n] && (dest_length + n < size - 1))
	{
		dest[dest_length + n] = src[n];
		n++;
	}
	dest[dest_length + n] = '\0';
	return (dest_length + src_length);
}

// int	main(void)
// {
// 	char *src = "defgh";
// 	char dest[] = "abc";
// 	size_t size;

// 	printf("---------------INICIO---------------\n");
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);

// 	//PRUEBAS ORIGINAL
// 	size = strlcat(dest, src, (size_t)3);
// 	printf("ORGINAL dest: %s\n", dest);
// 	printf("Size: %ld\n", size);

// 	char *src_2 = "defgh";
// 	char dest_2[20] = "abc";
// 	size = ft_strlcat(dest_2, src_2, 6);
// 	printf("MIO dest: %s\n", dest_2);
// 	printf("Size: %ld\n", size);
// 	return (0);
// }
