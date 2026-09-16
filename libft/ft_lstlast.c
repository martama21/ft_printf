/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:50:55 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:50:59 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>//para el NULL
// #include <stdio.h>
// #include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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
// 	t_list *last;

// 	node0 = ft_lstnew("cont0");
// 	node1 = ft_lstnew("cont1");
// 	node2 = ft_lstnew("cont2");
// 	ft_lstadd_front(&node2, node1);
// 	ft_lstadd_front(&node1, node0);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node0);
// 	printf("-----------------------------\n");
// 	printf("N Elements list -> %d\n", ft_lstsize(node0));
// 	printf("-----------------------------\n");
// 	last = ft_lstlast(node0);
// 	printf("jejej\n");
// 	printf("LAST ONE: -> (%s)\n", (char*)last->content);
// 	// free(node2);
// 	// free(node1);
// 	free(node0);
// 	return (0);
// }
