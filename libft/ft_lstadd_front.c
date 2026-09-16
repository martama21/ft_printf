/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:48:27 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:48:29 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>//para malloc

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// void go_through_the_list(t_list *dir_first)
// {
// 	t_list *aux;
// 	int n;

// 	n = 0;
// 	aux = dir_first;
// 	while (aux != NULL)
// 	{
// 		printf("[%d] -> (%d)\n", n, *(int*)aux->content);
// 		n++;
// 		aux = aux->next;
// 	}
// }

// int	main(void)
// {
// 	int n;
// 	int n_2;
// 	t_list *node;
// 	t_list *first_node;

// 	n = 4;
// 	node = ft_lstnew(&n);
// 	printf("nodo -> %d\n", *(int*)node->content);
// 	n_2 = 2;
// 	first_node = ft_lstnew(&n_2);
// 	printf("first_nodo -> %d\n", *(int*)first_node->content);
// 	printf("------OUTRA VEZ------\n");
// 	printf("nodo -> %d\n", *(int*)node->content);
// 	printf("first_nodo -> %d\n", *(int*)first_node->content);
// 	printf("----------------------\n");
// 	ft_lstadd_front(&node, first_node);
// 	go_through_the_list(first_node);
// 	free(node);
// 	free(first_node);
// 	return (0);
// }
