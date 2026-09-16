/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:20:54 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/10 18:20:56 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char c;

// 	//c = 128;
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, ft_isascii(128));
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, isascii(128));
// 	return (0);
// }
