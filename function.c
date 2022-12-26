/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:45:44 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 23:14:32 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, int c)
{
	t_list	*next;

	if (!*b)
		return ;
	next = (*b)->next;
	ft_lstadd_front(a, ft_lstnew((*b)->content));
	*b = next;
	if (c == 0)
		write(1,"pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	ra(t_list **list, int c)
{
	t_list	*khay;
	t_list	*lst;

	lst = *list;
	khay = ft_lstnew((*list)->content);
	*list = (*list)->next;
	free(lst);
	ft_lstadd_back(list, khay);
	if (c == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rra(t_list **list, int c)
{
	t_list	*khay;
	t_list	*ls;
	t_list	*lst;

	lst = *list;
	khay = ft_lstlast(*list);
	ls = ft_lstnew(khay->content);
	while (lst->next != NULL)
	{
		if (lst->next->next == NULL)
		{
			lst->next = NULL;
			break ;
		}
		lst = lst->next;
	}
	free(khay);
	ft_lstadd_front(list, ls);
	if (c == 0)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	sa(t_list **list, int d)
{
	int	c;

	c = (*list)->content;
	(*list)->content = ((*list)->next)->content;
	((*list)->next)->content = c;
	if (d == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}
