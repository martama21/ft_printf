/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:52:01 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:52:02 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdio.h>
// #include <stdlib.h>//para malloc

// void go_through_the_list2(t_list *dir_first)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
}

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
// 	free(node0);
// 	free(node1);
// 	free(node2);
// 	return (0);
// }
