/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:39:14 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/10 18:39:16 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

// int	main(void)
// {
// 	char *str = "holi como estamos.";
// 	printf("MIO: %lu\n", ft_strlen(NULL));
// 	printf("OFICIAL: %lu\n", strlen(str));
// 	return (0);
// }
