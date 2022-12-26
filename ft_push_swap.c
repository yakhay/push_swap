/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:38:30 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 22:56:16 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	c;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
			i = -1;
		}
		i++;
	}
	return (tab);
}

void	ft_push_swap(t_list *a)
{
	t_list	*b;

	b = NULL;
	if (ft_chek(a) == 1)
	{
		if (ft_lstsize(a) >= 6 && ft_lstsize(a) <= 480)
			send_all_smaller_to_b(&a, &b, 4);
		else if (ft_lstsize(a) > 480)
			send_all_smaller_to_b(&a, &b, 9);
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		else if (ft_lstsize(a) > 3 && ft_lstsize(a) <= 5)
			ft_sort_5(&a, &b);
		else if (ft_lstsize(a) >= 6 && ft_lstsize(a) <= 99)
			send_all_smaller_to_b(&a, &b, 4);
		else if (ft_lstsize(a) == 2)
			ra(&a, 0);
	}
}
