/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:27:54 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:27:55 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>//para malloc y free
#include "libft.h"

static int	number_length(int n)
{
	int			len;
	long int	n_aux;

	len = 0;
	n_aux = n;
	if (n_aux < 0)
		n_aux = -n_aux;
	if (n_aux == 0)
		return (1);
	while (n_aux != 0)
	{
		n_aux = n_aux / 10;
		len++;
	}
	return (len);
}

static void	fill_array(char *str_num, int i, long int n)
{
	if (n == 0)
		return ;
	str_num[i] = (n % 10) + '0';
	fill_array(str_num, i - 1, n / 10);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	n_aux;
	char		*str_num;
	int			i;

	n_aux = n;
	i = 0;
	len = number_length(n_aux);
	if (n_aux < 0)
		len++;
	str_num = malloc ((len + 1) * sizeof(char));
	if (!str_num)
		return (NULL);
	if (n_aux < 0)
	{
		str_num[i] = '-';
		i++;
		n_aux = -n_aux;
	}
	if (n_aux == 0)
		str_num[i] = '0';
	if (i < len && n_aux != 0)
		fill_array(str_num, len -1, n_aux);
	str_num[len] = '\0';
	return (str_num);
}

// int main(void)
// {
// 	int n;

// 	n = 0;
// 	printf("len: %d\n", number_length(n));
// 	printf("itoa: %s\n", ft_itoa(n));
// 	return (0);
// }

// int	main(void)
// {
// 	int n;
// 	//int n_len;

// 	//n = 234357;
// 	n = -2147483647;
// 	//n = -452;
// 	//n = 30000;
// 	//n = 0;

// 	//n_len = ft_len_number(n);
// 	//if n_len = 0 -> CASO ESPECIAL

// 	//printf("n_len: %d\n", n_len);
// 	//printf("10^(%d) = %ld\n", n_len, raising_ten_to_n(n_len));
// 	printf("str_num: %s\n", ft_itoa(n));
// 	return (0);
// }
