/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:34:00 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 23:01:14 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fffff(t_list **a, t_list **b, int c, int k)
{
	if ((((*b)->content > ft_lstlast(*a)->content) || c == 0)
		&& ft_max(*b, k) != 0)
	{
		pa(a, b, 0);
		ra(a, 0);
		return (1);
	}
	return (0);
}

int	ft_limit(t_list **a, t_list **b, int k, int c)
{
	while (ft_max(*b, k) != -1)
	{
		if (ft_max(*b, k) == 0)
			pa(a, b, 0);
		else if (ft_max(*b, k) > ft_lstsize(*b) / 2)
		{
			rra(b, 1);
			c += ft_fffff(a, b, c, k);
		}
		else
		{
			ra(b, 1);
			c += ft_fffff(a, b, c, k);
		}
	}
	return (c);
}

void	ft_sort_lst1(t_list **a, t_list **b, int k, int *tab)
{
	int	c;

	c = 1;
	while (k > 0)
	{	
		if (ft_max(*b, tab[k - 1]) != -1)
		{
			c = ft_limit(a, b, tab[k - 1], c);
		}
		else
		{
			rra(a, 0);
			c--;
		}
		k--;
	}
}

void	ft_sotr_list(t_list **a, t_list **b, int *tab)
{
	int	k;
	int	c;

	c = 1;
	k = ft_lstsize(*b);
	pa(a, b, 0);
	ft_sort_lst1(a, b, k, tab);
}
