/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:52:22 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:52:23 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size > 0)
	{
		while (src[n] && (n < size - 1))
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char *src = "holii como estasa";
// 	char dest[] = "sdjh";
// 	size_t size;

// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);

// 	//PRUEBAS ORIGINAL
// 	printf("-----------ORIGINAL---------\n");
// 	size = strlcpy(dest, src, 3);
// 	printf("dest ahora: %s\n", dest);
// 	printf("size: %ld\n", size);

// 	//PRUEBAS MIO
// 	printf("---------------MIO--------------\n");
// 	char *src_2 = "holii como estasa";
// 	char dest_2[] = "sdjh";
// 	size = ft_strlcpy(dest_2, src_2, 3);
// 	printf("dest ahora: %s\n", dest_2);
// 	printf("size: %ld\n", size);
// 	return (0);
// }
