/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:24:32 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 21:56:23 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_sheck_min(t_list *a, int end)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->content <= end)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	ft_place(t_list **b, int c)
{
	if ((*b)->next)
	{
		if ((*b)->content > c)
			ra(b, 1);
	}
}

void	ft_x(t_list **a, t_list **b, int l, int h)
{
	while (ft_sheck_min(*a, l) != -1)
	{
		if (ft_sheck_min(*a, l) == 0)
		{
			pa(b, a, 1);
			ft_place(b, h);
		}
		else if (ft_sheck_min(*a, l) > ft_lstsize(*a) / 2)
			rra(a, 0);
		else
			ra(a, 0);
	}
}

t_list	*ft_xila3ba(t_list **a, int max, int c, int *tab)
{
	int		i;
	int		l;
	int		h;
	t_list	*b;

	i = 1;
	b = NULL;
	while (i <= c)
	{
		if (i == c)
		{
			while (ft_lstsize(*a) > 0)
			{
				pa(&b, a, 1);
				ft_place(&b, tab[i * max - (max) / 2]);
			}
			break ;
		}
		l = tab[(i * max)];
		h = tab[i * max - (max) / 2];
		ft_x(a, &b, l, h);
		i++;
	}
	return (b);
}

void	send_all_smaller_to_b(t_list **a, t_list **b, int c)
{
	int		*tab;
	int		k;
	int		max;
	t_list	*tmp;

	k = 0;
	tab = (int *)malloc(sizeof(int) * ft_lstsize(*a));
	tmp = *a;
	while (tmp != NULL)
	{
		tab[k++] = tmp->content;
		tmp = tmp->next;
	}
	k = ft_lstsize(*a);
	tab = sort_tab(tab, ft_lstsize(*a));
	max = k / c;
	if (k % c != 0)
		max = (k / c) + 1;
	*b = ft_xila3ba(a, max, c, tab);
	ft_sotr_list(a, b, tab);
}

// void printList(t_list *list)
// {
//     printf("------- start -------\n");
//     while (list)
//     {
//         printf("{%d} ", list->content);
//         list = list->next;
//     }
//     printf("\n------- end -------\n");
// }
//
