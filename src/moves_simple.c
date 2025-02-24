/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:03:53 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/24 14:37:09 by marcudos         ###   ########.fr       */
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

void	pa(t_turk *turk)
{
	t_stack	*first_a;
	t_stack	*last_a;
	t_stack	*moved_b;
	t_stack	*last_b;

	first_a = turk->stack_a;
	last_a = turk->stack_a->prev;
	moved_b = turk->stack_b;
	last_b = turk->stack_b->prev;
	if (moved_b != last_b)
	{
		last_b->next = moved_b->next;
		moved_b->next->prev = last_b;
		turk->stack_b = moved_b->next;
	}
	else
		turk->stack_b = NULL;
	last_a->next = moved_b;
	turk->stack_a->prev = moved_b;
	moved_b->prev = last_a;
	moved_b->next = first_a;
	turk->stack_a = moved_b;
	ft_printf("pa\n");
}

void	pb(t_turk *turk)
{
	t_stack	*moved_a;
	t_stack	*last_a;
	t_stack	*first_b;
	t_stack	*last_b;

	moved_a = turk->stack_a;
	last_a = moved_a->prev;
	turk->stack_a = moved_a->next;
	turk->stack_a->prev = last_a;
	last_a->next = turk->stack_a;
	if (!turk->stack_b)
	{
		turk->stack_b = moved_a;
		turk->stack_b->next = moved_a;
		turk->stack_b->prev = moved_a;
		return ;
	}
	first_b = turk->stack_b;
	last_b = first_b->prev;
	last_b->next = moved_a;
	moved_a->prev = last_b;
	moved_a->next = first_b;
	first_b->prev = moved_a;
	turk->stack_b = moved_a;
	ft_printf("pb\n");
}
