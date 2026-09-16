/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:39:00 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:39:02 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//para write
// #include "libft.h"//para write
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

// int	main(void)
// {
// 	int fd;
// 	char *path ="/home/alumnos/martama/
// Documentos/42_estudiante/d_pruebas/file_to_write";
// 	char c = '\0';

// 	fd = open(path, O_WRONLY | O_APPEND);
// 	if (fd < 0)
// 	{
// 		printf("PROBLEMS");
// 		return (1);
// 	}
// 	ft_putchar_fd(c, fd);
// 	ft_putchar_fd(c, fd);
// 	ft_putchar_fd(c, fd);
// 	close(fd);
// 	return (0);
// }
