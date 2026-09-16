/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:21:07 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 12:21:08 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

// free_signs() 
// comprueba si comienza por un signo en cuyo caso:
// 	mira si lo siguiente es un numero, en cuyo caso:
// 		si el signo es - : retorna -1
// 		si el signo es + : retorna 1
// 	o si es otra cosa, en cuyo caso:
// 		retorna 0
// comprueba si comienza por un numero, en cuyo caso:
// 		retorna 0

static char	*scape_spaces(const char *nptr)
{
	char	*aux;

	aux = (char *)nptr;
	while ((*aux >= 9 && *aux <= 13) || *aux == 32)
	{
		aux++;
	}
	return (aux);
}

static int	check_start_and_sign(char *nptr)//free_signs(char *nptr) 
{
	if (*nptr == '+' || ft_isdigit(*nptr))
		return (1);
	else if (*nptr == '-')
		return (-1);
	return (0);
}

static int	get_number(char *nptr)
{
	int	n_aux;
	int	n_total;
	int	i;

	i = 0;
	n_total = 0;
	while (ft_isdigit(nptr[i]))
	{
		n_aux = nptr[i] - 48;
		n_total = n_total * 10 + n_aux;
		i++;
	}
	return (n_total);
}

int	ft_atoi(const char *nptr)
{
	char	*nptr_aux;
	int		start_and_sign;
	int		num;

	nptr_aux = scape_spaces(nptr);
	start_and_sign = check_start_and_sign(nptr_aux);
	if (!start_and_sign)
		return (0);
	if (*nptr_aux == '+' || *nptr_aux == '-')
		nptr_aux++;
	num = get_number(nptr_aux) * start_and_sign;
	return (num);
}

// int	main(void)
// {
// 	//int min = -2147483647;
// 	//int max = 2147483647;
// 	char *nptr = "-02147483648";

// 	//PRUEBAS ATOI ORIGINAL
// 	printf("--------------ATOI ORIGINAL-------------\n");
// 	printf("min 2147483648 -> %d\n", atoi("2147483648"));
// 	printf("max 2147483647 -> %d\n", atoi("2147483647"));
// 	printf("num ' -21474' -> %d\n", atoi(" -21474"));
// 	printf("num '- 21474' -> %d\n", atoi(" -21474"));
// 	printf("num '- 21474' -> %d\n", atoi(" -21474"));
// 	printf("num '- 21d474' -> %d\n", atoi(" -21d474"));
// 	printf("num '- 21d474' -> %d\n", atoi(" -21+474"));
// 	printf("num (%s) -> %d\n", nptr, atoi(nptr));

// 	//MIERDAS MIAS
// 	printf("--------------MIS MIERDAS-------------\n");
// 	//printf("INICIO: '%s'\n", nptr);
// 	//scape_spaces(nptr);
// 	//printf("DEPOIS: '%s'\n", nptr);
// 	printf("MI_ATOI (%s) -> %d\n", nptr, ft_atoi(nptr));
// 	return (0);
// }
