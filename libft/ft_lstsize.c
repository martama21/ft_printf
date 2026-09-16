/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:49:45 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:49:46 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>//para el NULL
// #include <stdio.h>
// #include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

// void go_through_the_list(t_list *dir_first)
// {
// 	t_list *aux;
// 	int n;

// 	n = 0;
// 	aux = dir_first;
// 	while (aux != NULL)
// 	{
// 		printf("[%d] -> (%s)\n", n, (char*)aux->content);
// 		n++;
// 		aux = aux->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *node0;
// 	t_list *node1;
// 	t_list *node2;

// 	node0 = ft_lstnew("cont0");
// 	node1 = ft_lstnew("cont1");
// 	node2 = ft_lstnew("cont2");
// 	ft_lstadd_front(&node2, node1);
// 	ft_lstadd_front(&node1, node0);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node0);
// 	printf("-----------------------------\n");
// 	printf("N Elements list -> %d\n", ft_lstsize(node0));
// 	free(node0);
// 	free(node1);
// 	free(node2);
// 	return (0);
// }
