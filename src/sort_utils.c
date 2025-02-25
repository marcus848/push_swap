/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:07:19 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 15:56:50 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sort(t_turk **turk)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = (*(*turk)->stack_a)->next;
	while (i < (*turk)->size)
	{
		if (a->nbr > a->next->nbr && a->next != (*(*turk)->stack_a))
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}
