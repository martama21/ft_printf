/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:40:36 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:40:38 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//para write
#include "libft.h"
// #include <sys/stat.h>
// #include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s) * sizeof(char));
}

// int	main(void)
// {
// 	int fd;
// 	char *path ="/home/alumnos/martama/
// Documentos/42_estudiante/d_pruebas/file_to_write";
// 	//char *str = "\nesta es la cadena a escribir\n";

// 	fd = open(path, O_WRONLY | O_APPEND);
// 	if (fd < 0)
// 		return (1);
// 	ft_putstr_fd(NULL, fd);
// 	close(fd);
// 	return (0);
// }
