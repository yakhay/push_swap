/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:19:31 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 23:15:51 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void printListe(t_list *list)
// {
//     printf("------- start -------\n");
//     while (list)
//     {
//         printf("{%d} ", list->content);
//         list = list->next;
//     }
//     printf("\n------- end -------\n"); 
// }

int	ft_doub(t_list *a)
{
	int		i;
	int		c;
	t_list	*b;

	b = a;
	while (b)
	{
		c = b->content;
		a = b;
		i = 0;
		while (a)
		{
			if (c == a->content)
			{
				i++;
				if (i == 2)
					return (-1);
			}
			a = a->next;
		}
		b = b->next;
	}
	return (0);
}

int	ft_check_valid(char **str, t_list **a)
{
	int	j;
	int	k;

	j = 0;
	while (str[j] != NULL)
	{
		k = -1;
		while (str[j][++k])
		{
			if (!(str[j][k] >= 48 && str[j][k] <= 57)
				&& (str[j][k] != '-' && str[j][k] != '+'))
			{
				write(2, "error\n", 6);
				return (-1);
			}
			if ((str[j][k] == '-' || str[j][k] == '+')
				&& !(str[j][k + 1] >= 48 && str[j][k + 1] <= 57))
			{
				write(2, "error\n", 6);
				return (-1);
			}
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(str[j++])));
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	t_list	*a;

	a = NULL;
	if (ac == 1)
	{
		write(2, "error\n", 6);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		str = ft_split(av[i], 32);
		if (ft_check_valid(str, &a) == -1)
			return (0);
		i++;
	}
	if (ft_doub(a) == -1)
	{
		write(2, "error\n", 6);
		return (0);
	}
	ft_push_swap(a);
}
