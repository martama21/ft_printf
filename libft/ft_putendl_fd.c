/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:42:01 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:42:03 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>//para write
#include "libft.h"
// #include <sys/stat.h>
// #include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// int	main(void)
// {
// 	int fd;
// 	char *path ="/home/alumnos/martama/
// Documentos/42_estudiante/d_pruebas/file_to_write";
// 	//char *s = "cadenita";

// 	fd = open(path, O_WRONLY | O_APPEND);
// 	if (fd < 0)
// 		return (1);
// 	ft_putendl_fd(NULL, fd);
// 	close(fd);
// 	return (0);
// }
