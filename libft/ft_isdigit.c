/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:48:09 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/10 17:48:11 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char c;

// 	c = 58;
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, ft_isdigit(c));
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, isdigit(c));
// 	return (0);
// }
