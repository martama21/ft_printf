/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:55:41 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:55:42 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	char c;

// 	c = 't';
// 	printf("ORIGINAL: (%c) -> %c\n", c, toupper(c));
// 	printf("MIO:      (%c) -> %c\n", c, ft_toupper(c));
// 	return (0);
// }
