/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:44:09 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 11:44:11 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <strings.h>
// #include <stdio.h>
// #include <stddef.h>//para poder usar el tipo size_t
#include "libft.h"

// void print_array(void *s, int length)
// {
//     int n;
//     unsigned char *aux;
//     n = 0;
//     aux = s;
//     while (n < length)
//     {
//         printf("%u,", aux[n]);
//         n++;
//     }
//     printf("\n");
// }
void	ft_bzero(void *s, size_t n) // s[.n] ??????????????????????????
{
	ft_memset(s, 0, n);
}

// int main(void)
// {
//     unsigned char aux[10];
//     unsigned char aux_2[3];
//     int length;

//     length = sizeof(aux) / sizeof(aux[0]);
//     printf("length_array: %d\n", length);

//     //PRUEBAS ORIGINAL
//     print_array(aux, length);
//     bzero(aux, 4);
//     print_array(aux, length);

//     //PRUEBAS MIO
//     print_array(aux_2, length);
//     ft_bzero(aux_2, 2);
//     print_array(aux_2, (size_t)length);

//     return (0);
// }
