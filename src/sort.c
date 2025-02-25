/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:39:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 18:14:13 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_turk(t_turk *turk)
{
	get_stats(&turk->stats.a, turk->stack_a);
	if (is_sort(turk))
		exit (1);
	else if (turk->size == 2)
		sort_two_numbers(&turk->stack_a);
	else if (turk->size == 3)
		sort_three_numbers(turk);
	else if (turk->size == 4)
		sort_four_numbers(turk);
	else
		turkish(turk);
	free_all(&turk);
}

void	sort_two_numbers(t_stack **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}

void	sort_three_numbers(t_turk *turk)
{
	t_stack	*a;

	a = turk->stack_a;
	if (a->next->nbr == turk->stats.a.min)
	{
		if (a->nbr == turk->stats.a.max)
			ra(&turk, 1);
		else
			sa(&turk->stack_a, 1);
	}
	else if (a->next->nbr == turk->stats.a.max)
	{
		if (a->nbr == turk->stats.a.min)
		{
			rra(&turk, 1);
			sa(&turk->stack_a, 1);
		}
		else
			rra(&turk, 1);
	}
	else if (a->nbr == turk->stats.a.max && a->prev->nbr == turk->stats.a.min)
	{
		sa(&turk->stack_a, 1);
		rra(&turk, 1);
	}
}

void	sort_four_numbers(t_turk *turk)
{
	long	b;

	pb(&turk);
	get_stats(&turk->stats.b, turk->stack_b);
	get_stats(&turk->stats.a, turk->stack_a);
	sort_three_numbers(turk);
	get_stats(&turk->stats.a, turk->stack_a);
	b = turk->stack_b->nbr;
	if (turk->stats.b.min < turk->stats.a.min)
		pa(&turk);
	else if (turk->stats.b.max > turk->stats.a.max)
	{
		pa(&turk);
		ra(&turk, 1);
	}
	else if (b > turk->stack_a->next->nbr)
	{
		rra(&turk, 1);
		pa(&turk);
		ra(&turk, 1);
		ra(&turk, 1);
	}
	else if (b < turk->stack_a->next->nbr)
	{
		pa(&turk);
		sa(&turk->stack_a, 1);
	}
}
