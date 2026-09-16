/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:56:04 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:56:05 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>//para el NULL
//#include <stdio.h>
//#include <stdlib.h>//para malloc

// void *ft_plusone(void *content)
// {
// 	int i;
// 	char *c_content;

// 	i = 0;
// 	c_content = ft_strdup(content);//(char *)content;
// 	while (c_content[i] != '\0')
// 	{
// 		c_content[i] += 1;
// 		i++;
// 	}
// 	return (c_content);
// }

// void ft_delete_content(void *content)
// {
// 	//free(content);
// 	(void)content;
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_result;
	t_list	*lst_aux;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	lst_result = NULL;
	lst_aux = lst;
	while (lst_aux)
	{
		new = ft_lstnew(f(lst_aux->content));
		if (!new)
		{
			ft_lstclear(&lst_result, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_result, new);
		lst_aux = lst_aux->next;
	}
	return (lst_result);
}

// void go_through_the_list(t_list *dir_first)
// {
// 	t_list *aux;
// 	int n;

// 	n = 0;
// 	aux = dir_first;
// 	while (aux != NULL)
// 	{
// 		printf("[%d] -> (%s) | pointer -> %p\n", n, (char*)aux->content, aux);
// 		n++;
// 		aux = aux->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *node0;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *new_list;
// 	char n0[] = "cont0";
// 	char n1[] = "cont1";
// 	char n2[] = "cont2";

// 	node0 = ft_lstnew(n0);
// 	node1 = ft_lstnew(n1);
// 	node2 = ft_lstnew(n2);
// 	ft_lstadd_back(&node2, node1);
// 	ft_lstadd_back(&node2, node0);
// 	new_list = ft_lstmap(node2, &ft_plusone, &ft_delete_content);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node2);
// 	printf("-----------------------------\n");
// 	//ft_lstiter(node2, &ft_plusone);
// 	//new_list = ft_lstmap(node2, &ft_plusone, &ft_delete_content);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(new_list);
// 	printf("-----------------------------\n");
// 	free(node0);
// 	free(node1);
// 	free(node2);
// 	return (0);
// }
