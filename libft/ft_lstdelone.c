/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:53:05 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:53:06 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
#include <stdlib.h>//para free
// #include <stdio.h>

// void ft_delete_content(void *content)
// {
// 	//free(content);
// 	(void)content;
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
// 	ft_lstadd_back(&node2, node1);
// 	ft_lstadd_back(&node2, node0);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node2);
// 	printf("-----------------------------\n");
// 	ft_lstdelone(node2, &ft_delete_content);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node2);
// 	printf("-----------------------------\n");
// 	// free(node0);
// 	// free(node1);
// 	// free(node2);
// 	return (0);
// }
