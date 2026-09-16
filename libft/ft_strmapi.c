/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:36:20 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:36:22 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>//para malloc y free
#include "libft.h"

// char f_aux(unsigned int u_i, char c)
// {
// 	if ((u_i % 2) == 0)
// 		return ('p');
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	p = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int	main(void)
// {
// 	char *s = "cadena sobre la que iterar";
// 	char *p;

// 	printf("ORIGINAL: (%s)\n", s);
// 	p = ft_strmapi(s, &f_aux);
// 	printf("     MIO: (%s)\n", p);
// 	free(p);
// 	return (0);
// }
