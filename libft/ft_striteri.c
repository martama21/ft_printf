/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:37:34 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:37:36 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// void f_aux(unsigned int u_i, char *c)
// {
// 	if ((u_i % 2) == 0)
// 	{
// 		//printf("c[%d] : %c\n", u_i, *c);
// 		*c = 'p';
// 	}
// 	//printf("c = %c\n", *c);
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s != '\0')
	{
		f(i, s);
		i++;
		s++;
	}
}

// int	main(void)
// {
// 	char s[] = "subcadena sobre la que iterar";

// 	printf("ORIGINAL: (%s)\n", s);
// 	ft_striteri(s, &f_aux);
// 	printf("MIO:      (%s)\n", s);
// 	return (0);
// }
