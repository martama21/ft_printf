/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:12:32 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:12:34 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>//para malloc y free
#include "libft.h"
// #include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*p;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	i = 0;
	p = malloc (sizeof(char) * len + sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int	main(void)
// {
// 	char *str_original = "esto es una prueba";
// 	char *str_MIO;
// 	int i;

// 	i = 35;
// 	printf("str_original(%p): %s\n", str_original, str_original);
// 	str_MIO = ft_substr(str_original, i, 20);
// 	printf("     str_MIO(%p): (%s)\n", str_MIO, str_MIO);
// 	printf("(%p) + %lu : %p\n", 
// str_original, sizeof(char)*i, str_original + sizeof(char)*i);
// 	return (0);
// }
