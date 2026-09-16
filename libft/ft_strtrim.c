/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:16:34 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:16:35 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>//malloc y free
#include "libft.h"
//#include <stdio.h>

static int	in_set(char c, char const *set)
{
	int		i;
	char	*set_aux;

	i = 0;
	set_aux = (char *)set;
	while (set_aux[i] != '\0')
	{
		if (c == set_aux[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*p_aux;
	int		start;
	int		end;
	int		i;

	start = 0;
	p_aux = (char *)s1;
	end = ft_strlen(s1);
	while (p_aux[start] != '\0' && in_set(p_aux[start], set))
		start++;
	while (in_set(p_aux[end - 1], set) && end > start)
		end--;
	p = malloc ((end - start + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		p[i] = s1[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int	main(void)
// {
// 	char *s1 = "c8adena con cositas y tal pascual";
// 	char *set = "cfcgsn34r3878iyldughb3iyg87ye8732yh8g2";
// 	char *p;

// 	printf("s1: (%s)\n", s1);
// 	p = ft_strtrim(s1, set);
// 	printf("p: (%s)\n", p);
// 	free(p);
// 	return (0);
// }
