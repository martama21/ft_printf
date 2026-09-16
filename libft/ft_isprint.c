/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:30:49 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/10 18:30:50 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char c;

// 	//c = 122;
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, ft_isprint(32));
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, isprint(32));
// 	return (0);
// }
