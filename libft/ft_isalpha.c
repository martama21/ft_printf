/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:44:27 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/10 18:20:23 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int c;

// 	c = 'Z';
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, ft_isalpha(c));
// 	printf("c = %c = %d | is_alpha -> %d\n", c, c, isalpha(c));
// 	return (0);
// }
