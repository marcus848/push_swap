/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:03:53 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/16 18:16:56 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_turk *turk, int message)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = turk->stack_a;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->prev = last;
	second->next = first;
	last->next = second;
	turk->stack_a = second;
	if (message)
		ft_printf("sa\n");
}

void	sb(t_turk *turk, int message)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = turk->stack_b;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->prev = last;
	second->next = first;
	last->next = second;
	turk->stack_b = second;
	if (message)
		ft_printf("sa\n");
}
