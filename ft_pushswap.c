/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:27:39 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 22:55:44 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *khay, int max)
{
	int	i;

	i = 0;
	while (khay)
	{
		if (max == khay->content)
		{
			max = khay->content;
			return (i);
		}
		khay = khay->next;
		i++;
	}
	return (-1);
}

int	ft_min(t_list *a)
{
	int		i;
	int		max;
	t_list	*b;

	i = 0;
	b = a;
	if (!a)
		return (-1);
	max = a->content;
	while (b)
	{
		if (b->content < max)
			max = b->content;
		b = b->next;
	}
	while (a)
	{
		if (a->content == max)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

int	ft_chek(t_list *khay)
{
	while (khay->next != NULL)
	{
		if (khay->content > khay->next->content)
			return (1);
		khay = khay->next;
	}
	return (0);
}

void	ft_sort_3(t_list **khay)
{
	if (ft_chek(*khay) == 1)
	{
		if (ft_min(*khay) == 0)
		{
			rra(khay, 0);
			sa(khay, 0);
		}
		else if (ft_min(*khay) == 1
			&& (*khay)->content < (*khay)->next->next->content)
			sa(khay, 0);
		else if (ft_min(*khay) == 1
			&& (*khay)->content > (*khay)->next->next->content)
			ra(khay, 0);
		else if (ft_min(*khay) == 2
			&& (*khay)->content > (*khay)->next->content)
		{
			sa(khay, 0);
			rra(khay, 0);
		}
		else
			rra(khay, 0);
	}
}

void	ft_sort_5(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if (ft_min(*a) == 0)
			pa(b, a, 1);
		else if (ft_min(*a) > ft_lstsize(*a) / 2)
			rra(a, 0);
		else
			ra(a, 0);
	}
	ft_sort_3(a);
	while (ft_lstsize(*b) > 0)
		pa(a, b, 0);
}
