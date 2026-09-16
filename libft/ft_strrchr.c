/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:04:51 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:04:52 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	s += n;
	while (n >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "hola quei tal";
// 	//char *str = "holi que tal";

// 	printf("ORIGINAL: %s | p -> %p\n", strrchr(str, 'a'), strrchr(str, 'a'));
// 	return (0);
// }
