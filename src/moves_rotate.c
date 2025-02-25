/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:30:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/24 11:51:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_turk **turk, int message)
{
	t_stack	*a;

	a = (*turk)->stack_a;
	(*turk)->stack_a = a->next;
	if (message)
		ft_printf("ra\n");
}

void	rb(t_turk **turk, int message)
{
	t_stack	*b;

	b = (*turk)->stack_b;
	(*turk)->stack_b = b->next;
	if (message)
		ft_printf("rb\n");
}

void	rra(t_turk **turk, int message)
{
	t_stack	*a;

	a = (*turk)->stack_a;
	(*turk)->stack_a = a->prev;
	if (message)
		ft_printf("rra\n");
}

void	rrb(t_turk **turk, int message)
{
	t_stack	*b;

	b = (*turk)->stack_b;
	(*turk)->stack_b = b->prev;
	if (message)
		ft_printf("rrb\n");
}
