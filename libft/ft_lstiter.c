/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarina- <mmarina-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:54:59 by mmarina-          #+#    #+#             */
/*   Updated: 2026/06/25 13:55:01 by mmarina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>//para el NULL
// #include <stdio.h>
// #include <stdlib.h>//para malloc

// void ft_plusone(void *content)
// {
// 	int i;
// 	char *c_content;

// 	i = 0;
// 	c_content = (char *)content;
// 	while (c_content[i] != '\0')
// 	{
// 		c_content[i] += 1;
// 		i++;
// 	}
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
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
// 	char n0[] = "cont0";
// 	char n1[] = "cont1";
// 	char n2[] = "cont2";

// 	node0 = ft_lstnew(n0);
// 	node1 = ft_lstnew(n1);
// 	node2 = ft_lstnew(n2);
// 	ft_lstadd_back(&node2, node1);
// 	ft_lstadd_back(&node2, node0);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node2);
// 	printf("-----------------------------\n");
// 	ft_lstiter(node2, &ft_plusone);
// 	printf("-------------LIST-----------\n");
// 	go_through_the_list(node2);
// 	printf("-----------------------------\n");
// 	free(node0);
// 	free(node1);
// 	free(node2);
// 	return (0);
// }
