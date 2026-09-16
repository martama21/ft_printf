/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:42:00 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:42:03 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void print_size(void *s)
// {
// 	int n;
// 	unsigned char *aux;

// 	n = 0;
// 	aux = s;
// 	while (aux[n] == 0)
// 		n++;
// 	printf("SIZE: %d\n", n);
// }

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	i = 0;
	aux = s;
	while (i < n)
	{
		aux[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	//char *c = "esto es una prueba.";
// 	char aux[10];
// 	//unsigned char aux_2[10];
// 	unsigned char *d;
// 	unsigned char *d2;
// 	//void str[7];
// 	printf("INICIO: %s\n", aux);
// 	//printf("s[30]: %c\n", aux_2[30]);
// 	//aux = memset(c, 'c', 4);
// 	//c = memset(aux, 'c', 10);
// 	//printf("FINAL: %s\n", aux);	
// 	d = memset(aux, 'c', 10);
// 	d2 = ft_memset(NULL, 'c', 9);
// 	//d = memset(aux, 'c', 8);
// 	printf("mem_ORIGINAL: %s\n", d);
// 	//d2 = ft_memset(&d2, 'c', 8);
// 	printf("mem_MIO: %s\n", d2);
// 	return (0);
// }
