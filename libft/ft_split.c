/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:18:26 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:18:27 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>//para malloc y free
#include "libft.h"

static int	count_blocks(const char *s, char c)
{
	int		i;
	int		n_blocks;
	char	*s_aux;

	i = 0;
	n_blocks = 0;
	s_aux = (char *)s;
	while (s_aux[i])
	{
		if (s_aux[i] != c)
		{
			while (s_aux[i] && s_aux[i] != c)
			{
				i++;
			}
			n_blocks++;
		}
		if (s_aux[i] && s_aux[i] == c)
		{
			while (s_aux[i] && s_aux[i] != c)
				i++;
			i++;
		}
	}
	return (n_blocks);
}

static char	**free_array(char **strings, size_t i)
{
	while (i > 0)
	{
		i--;
		free(strings[i]);
	}
	free(strings);
	return (NULL);
}

static char	**create_strings(char const *s, char c, char **strings)
{
	size_t	i;
	size_t	i_aux;
	size_t	start;

	i_aux = 0;
	start = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			strings[i_aux] = ft_substr(s, start, i - start);
			if (!strings[i_aux])
				return (free_array(strings, i_aux));
			i_aux++;
		}
	}
	strings[i_aux] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		n_blocks;

	if (!s)
		return (NULL);
	n_blocks = count_blocks(s, c);
	strings = (char **)malloc ((n_blocks + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	if (!create_strings(s, c, strings))
		return (NULL);
	return (strings);
}

// int	main(void)
// {
// 	char	*s = "esta es la cadena que tengo    que dividir.";
// 	char	c;
// 	char	**stringss;
// 	int		i;

// 	c = '.';
// 	i = 0;
// 	stringss = ft_split(s, c);
// 	printf("HOLI\n");
// 	if (stringss)
// 	{
// 		while (stringss[i])
// 		{
// 			printf("sss\n");
// 			printf("[%d] -> (%s)\n", i, stringss[i]);
// 			free(stringss[i]);
// 			i++;
// 		}
// 		free(stringss);
// 	}
// 	return (0);
// }
