/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:43:12 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:43:14 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>//para write
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>

static void	write_num(long n, int fd)
{
	int	digit;

	if (n == 0)
		return ;
	write_num(n / 10, fd);
	digit = n % 10;
	ft_putchar_fd(digit + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	write_num(num, fd);
}

// int	main(void)
// {
// 	int fd;
// 	char *path ="/home/alumnos/martama/
// Documentos/42_estudiante/d_pruebas/file_to_write";
// 	int n;

// 	n = -347623981;
// 	fd = open(path, O_WRONLY | O_APPEND);
// 	if (fd < 0)
// 		return (1);
// 	ft_putnbr_fd(n, fd);
// 	close(fd);
// 	return (0);

// 	// int n;

// 	// n = 234;
// 	// ft_putnbr_fd(n);
// 	// return (0);

// 	// printf("n = %d | n (mod) 10 = %d\n", n, (n % 10));
// 	// while (n != 0)
// 	// {
// 	// 	n = n / 10;
// 	// 	printf("n = %d | n (mod) 10 = %d\n", n, (n % 10));
// 	// }
// 	// printf("RECURSIVA:\n");
// 	// get_num(243000);
// 	// //printf("%d\n", get_num(243000));
// 	// return (0);

// }
