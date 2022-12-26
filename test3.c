/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:07:36 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 22:00:40 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "push_swap.h"

void	ft_lstadd_front(t_list	**lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*khay;

	khay = (t_list *)malloc(sizeof(t_list));
	if (!khay)
		return (NULL);
	khay->content = content;
	khay->next = NULL;
	return (khay);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst || !new)
		return ;
	if (!*lst && new)
		*lst = new;
	else if (*lst && new)
	{
		list = *lst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list	*lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
