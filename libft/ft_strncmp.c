/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:06:58 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:07:00 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

// size_t ft_strlen(const char *s)
// {
// 	size_t n;

// 	n = 0;
// 	while (s[n] != '\0')
// 		n++;
// 	return (n);
// }

// int min_length(const char *s1, const char *s2)
// {
// 	if (ft_strlen(s1) > ft_strlen(s2))
// 		return ((int)ft_strlen(s2));
// 	return ((int)ft_strlen(s1));
// }

// int strncmp(const char s1[.n], const char s2[.n], size_t n);
// int ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	int n_comparisons;
// 	int aux;

// 	aux = 0;
// 	n_comparisons = min_length(s1, s2);
// 	if (n_comparisons > (int)n && (int)n > 0)
// 		n_comparisons = n;
// 	while (aux < n_comparisons)
// 	{
// 		if ((unsigned char)s1[aux] < (unsigned char)s2[aux])
// 			return (-1);
// 		else if (s1[aux] > s2[aux])
// 			return (1);
// 		aux++;
// 	}
// 	if (n_comparisons == (int)n)
// 		return (0);
// 	if (s1[aux] != '\0')
// 		return (1);
// 	return (-1);
// }
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	aux;

	aux = 0;
	while (aux < n)
	{
		if ((unsigned char)s1[aux] != (unsigned char)s2[aux])
			return ((unsigned char)s1[aux] - (unsigned char)s2[aux]);
		if (s1[aux] == '\0')
			return (0);
		aux++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *s1 = "holi";
// 	char *s2 = "holij";
// 	int n = -1;

// 	printf("ORGIINAL: %s vs. %s : %d\n", s1, s2, strncmp(s1, s2, n));
// 	printf("MIO     : %s vs. %s : %d\n", s1, s2, ft_strncmp(s1, s2, n));
// 	return (0);
// }
