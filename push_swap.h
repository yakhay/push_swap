/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:29:00 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/26 22:52:05 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include<stdlib.h>
# include<unistd.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sa(t_list **list, int c);
void	rra(t_list **list, int c);
void	ra(t_list **list, int c);
void	pa(t_list **a, t_list **b, int c);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_push_swap(t_list *a);
int		ft_max(t_list *khay, int max);
int		ft_min(t_list *a);
int		ft_chek(t_list *khay);
void	ft_sort_3(t_list **khay);
void	ft_sort_5(t_list **a, t_list **b);
void	ft_sotr_list(t_list **a, t_list **b, int *tab);
void	ft_push_swap(t_list *a);
void	send_all_smaller_to_b(t_list **a, t_list **b, int c);
int		*sort_tab(int *tab, int size);

#endif
