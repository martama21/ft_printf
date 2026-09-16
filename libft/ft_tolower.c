/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:56:44 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:56:46 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	char c;

// 	c = '?';
// 	printf("ORIGINAL: (%c) -> %c\n", c, tolower(c));
// 	printf("MIO:      (%c) -> %c\n", c, ft_tolower(c));
// 	return (0);
// }
