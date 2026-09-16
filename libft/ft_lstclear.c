/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:54:02 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:54:06 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdlib.h>//para free
// #include <stdio.h>

// void ft_delete_content(void *content)
// {
// 	//free(content);
// 	(void)content;
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

// void go_through_the_list(t_list *dir_first)
// {
// 	// t_list *aux;
// 	int n;

// 	n = 0;
// 	// aux = dir_first;
// 	while (dir_first)
// 	{
// 		printf("[%d] -> (%s)\n", n, (char*)dir_first->content);
// 		n++;
// 		printf("dir_next -> %p\n", dir_first->next);
// 		dir_first = dir_first->next;
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
// 	//ft_lstdelone(node1, &ft_delete_content);
// 	ft_lstclear(&node1, &ft_delete_content);
// 	printf("node2->next -> %p\n", node2->next);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node2);
// 	printf("-----------------------------\n");
// 	printf("nodo -> %s\n", (char*)node2->content);
// 	printf("nodo -> %s\n", (char*)node0->content);
// 	// free(node0);
// 	// free(node1);
// 	// free(node2);
// 	return (0);
// }
