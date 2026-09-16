/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:44:45 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:44:46 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>//para malloc y free
#include <stdint.h>
#include "libft.h"
// #include <stdio.h>

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

//si size no es nulo y nmemb*size excede los límites de size_t, devolvemos NULL

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	p = malloc (nmemb * size);
	if (p == NULL)
		return (p);
	ft_memset(p, 0, nmemb * size);
	return (p);
}

// int	main(void)
// {
// 	size_t nmemb;
// 	size_t size;
// 	unsigned char *p;

// 	nmemb = 20;//n bytes
// 	size = sizeof(char);//size of type of bytes
// 	p = calloc(nmemb, size);
// 	printf("p: ");
// 	print_array(p, nmemb + 3);
// 	return (0);
// }
