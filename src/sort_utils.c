/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:07:19 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 18:48:10 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sort(t_turk *turk)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = turk->stack_a->next;
	while (i < turk->size)
	{
		if (a->nbr > a->next->nbr && a->next != turk->stack_a)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

int	is_sort_advanced(t_turk *turk)
{
	t_stack	*a;
	t_stack	*tmp;
	int		i;

	i = 0;
	a = turk->stack_a;
	while (i < turk->stats.a.index_min)
	{
		a = a->next;
		i++;
	}
	tmp = a->next;
	while (tmp != a)
	{
		if (tmp->nbr > tmp->next->nbr && tmp->next != a)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
