/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:03:15 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:03:17 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	if (!ch)
		return ((char *)(s + (ft_strlen(s))));
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "holi que tal";
// 	//char *str = "holi que tal";

// 	printf("ORIGINAL: %s | p -> %p\n", strchr(str, '\0'), strchr(str, '\0'));
// 	printf("MIO     : %s | p -> 
// %p\n", ft_strchr(str, '\0'), ft_strchr(str, '\0'));
// 	printf("ORIGINAL: %s | p -> %p | 't' + 56 -> 
// %d\n", str, strchr(str, 't' + 256), 't' + 256);
// 	printf("MIO     : %s | p -> %p | 't' + 56 -> 
// %d\n", str, ft_strchr(str, 't' + 256), 't' + 256);
// 	printf("puntero al pricipio -> %p | ", str);
// 	while (*str != '\0')
// 		str++;
// 	printf("puntero a nil -> %p\n", str);
// 	return (0);
// }
