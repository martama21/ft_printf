/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:14:30 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:14:32 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>//para malloc y free
#include "libft.h"
//#include <stdio.h>

static void	copy_s1(char const *s1, char *dest, size_t len1)
{
	size_t	i;

	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
}

static void	copy_s2(char const *s2, char *dest, size_t start, size_t len2)
{
	size_t	i;

	i = 0;
	while (i < len2)
	{
		dest[start + i] = s2[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc ((len1 + len2 + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	copy_s1(s1, p, len1);
	copy_s2(s2, p, len1, len2);
	p[len1 + len2] = '\0';
	return (p);
}

// char *ft_strjoin(char const *s1, char const *s2)
// {
// 	char *p;
// 	size_t size;
// 	size_t i;
// 	size_t i_2;

// 	size = (ft_strlen(s1) + ft_strlen(s2))*sizeof(char) + sizeof(char);
// 	p = malloc(size);
// 	i = 0;
// 	i_2 = 0;
// 	if (p == NULL)
// 		return (NULL);
// 	while (i < (ft_strlen(s1) + ft_strlen(s2)))
// 	{
// 		if (i < ft_strlen(s1))
// 			p[i] = s1[i];
// 		else
// 		{
// 			p[i] = s2[i_2];
// 			i_2++;
// 		}
// 		i++;
// 	}
// 	p[i] = '\0';
// 	return (p);
// }

// int	main(void)
// {
// 	char *s1 = "hola que";
// 	char *s2 = "tal todo?";
// 	char *result;

// 	printf("[%s] - [%s]\n", s1, s2);
// 	result = ft_strjoin(s1, s2);
// 	printf("[%s]\n", result);
// 	return (0);
// }
