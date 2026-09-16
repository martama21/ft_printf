/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:09:00 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:09:02 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

// void *ft_memchr(const void *s, int c, size_t n)
// {
// 	int i;

// 	i = 0;
// 	while (s[i] != '\0' && i < (int)n)
// 	{
// 		if (s[i] == c)
// 			return ()
// 	}
// }

// void *ft_memchr(const void *s, int c, size_t n)
// {
// 	int i;
// 	const unsigned char *aux;

// 	i = 0;
// 	aux = s;
// 	while (*aux != '\0' && i < (int)n)
// 	{
// 		if (*aux == c)
// 			return ((void *)aux);
// 		aux++;
// 		i++;
// 	}
// 	return (NULL);
// }

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*aux;

	i = 0;
	aux = s;
	while (i < n)
	{
		if (*aux == (unsigned char)c)
			return ((void *)aux);
		aux++;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "holii esto es una prueba.";
// 	char c;
// 	//unsigned char aux[30];
// 	unsigned char *aux;
// 	int n;

// 	c = '.';
// 	n = -3;
// 	aux = memchr(str, c, n);
// 	printf("ORIGINAL: %s | (%c) -> %s\n", str, c, aux);

// 	unsigned char *aux_2;
// 	aux_2 = ft_memchr(str, c, n);
// 	printf("MIO     : %s | (%c) -> %s\n", str, c, aux_2);
// 	return (0);
// }
