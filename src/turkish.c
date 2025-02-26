/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:33:41 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	turkish(t_turk **turk)
{
	t_moves	moves;

	start_turkish(turk);
	print_stacks(turk);
	print_stats(turk);
	// while ((*turk)->stats.a.size > 3)
	// {
	find_cheapest_to_b(turk, &moves);
	// }
}

void	find_cheapest_to_b(t_turk **turk, t_moves *moves)
{
	t_turk		*t;
	t_stack		*a;
	t_stack		*b;
	// t_moves		new_moves;
	t_cheapest	vars;

	(void)moves;
	t = (*turk);
	a = t->stack_a;
	b = t->stack_b;
	vars.i = 0;
	vars.cur_a = a->nbr;
	vars.pos_a = vars.i;
	while (vars.i < t->stats.a.size)
	{
		get_target_b(&vars, &b, &t->stats);
		print_vars(&vars);
		a = a->next;
		vars.cur_a = a->nbr;
		vars.i++;
	}
}

void	start_turkish(t_turk **turk)
{
	pb(turk);
	pb(turk);
	get_stats(&(*turk)->stats.a, (*turk)->stack_a);
	get_stats(&(*turk)->stats.b, (*turk)->stack_b);
}
