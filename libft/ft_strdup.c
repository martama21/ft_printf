/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:48:46 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:48:48 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>//para malloc y free
#include "libft.h"
// #include <stdio.h>
// #include <string.h>

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	p = malloc (len * sizeof(char) + sizeof(char));
	if (!p)
		return (NULL);
	while (i < len + 1)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}

// int	main(void)
// {
// 	char *str = "holi como va";
// 	char *str_cpy;
// 	char *str_cpy_MIO;

// 	str_cpy = strdup(str);
// 	printf("        str(%p): %s\n", str, str);
// 	printf("    str_cpy(%p): %s\n", str_cpy, str_cpy);
// 	//free(str_cpy);
// 	str_cpy_MIO = ft_strdup(str);
// 	printf("str_cpy_MIO(%p): %s\n", str_cpy_MIO, str_cpy_MIO);
// 	free(str_cpy);
// 	free(str_cpy_MIO);
// 	return (0);
// }
