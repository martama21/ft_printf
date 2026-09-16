/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:11:43 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:11:44 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>
// #include <stddef.h>

static int	little_search(const char *big, const char *lit, int ind, size_t len)
{
	size_t	n;

	n = 0;
	while (lit[n] && (ind + n) < len)
	{
		if (lit[n] != big[ind + n])
		{
			return (0);
		}
		n++;
	}
	if (lit[n] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (little[0] == big[i])
		{
			if (little_search(big, little, i, len))
			{
				big = big + i;
				return ((char *)big);
			}
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *big = "aqui tengo que buscar";
// 	//char *little = "tesgo";
// 	char *little = "tengo";
// 	int len;

// 	len = 10;
// 	printf("ORIGINAL: [[%s]] search ((%s)) 
// -> %s\n", big, little, strstr(big, little));
// 	printf("MIO     : [[%s]] search ((%s)) ->
//  %s\n", big, little, ft_strnstr(big, little, len));

// 	return (0);
// }
