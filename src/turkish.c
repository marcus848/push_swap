/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:33:41 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/27 18:15:00 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	turkish(t_turk **turk)
{
	t_moves	moves;
	t_cheap	vars;

	start_turkish(turk);
	// print_stacks(turk);
	while ((*turk)->stats.a.size > 3)
	{
		vars = find_cheap_to_b(turk);
		moves = get_moves(&vars, (*turk)->stats.a.size, (*turk)->stats.b.size);
		execute_moves(turk, &moves, pb);
		// print_stacks(turk);
	}
	sort_three_numbers((*turk));
	// print_stacks(turk);
	while ((*turk)->stats.a.size < (*turk)->size)
	{
		vars = find_right_position_a(turk);
		if (vars.pos_a > (*turk)->stats.a.size / 2 + 1)
		{
			vars.rotate = er_rrr;
			vars.pos_b = (*turk)->stats.b.size;
		}
		else
			vars.rotate = er_rr;
		moves = get_moves(&vars, (*turk)->stats.a.size, (*turk)->stats.b.size);
		// print_stacks(turk);
		// ft_printf("target A: %d\nindex A: %d\n",vars.cur_a, vars.pos_a);
		execute_moves(turk, &moves, pa);
	}
	last_rotate(turk);
	// print_stacksA(turk);
}

void	execute_moves(t_turk **turk, t_moves *moves, void (*f)(t_turk **))
{
	while (moves->i_rr--)
		rr(turk);
	while (moves->i_rrr--)
		rrr(turk);
	while (moves->i_ra--)
		ra(turk, 1);
	while (moves->i_rb--)
		rb(turk, 1);
	while (moves->i_rra--)
		rra(turk, 1);
	while (moves->i_rrb--)
		rrb(turk, 1);
	f(turk);
	get_stats(&(*turk)->stats.a, (*turk)->stack_a);
	if ((*turk)->size > (*turk)->stats.a.size)
		get_stats(&(*turk)->stats.b, (*turk)->stack_b);
}

t_cheap	find_right_position_a(t_turk **turk)
{
	t_stack	*a;
	t_stack	*b;
	t_cheap	vars;

	a = (*turk)->stack_a;
	b = (*turk)->stack_b;
	reset_vars(&vars);
	vars.cur_a = (*turk)->stats.a.max;
	if (b->nbr > (*turk)->stats.a.max)
	{
		vars.cur_a = (*turk)->stats.a.min;
		vars.pos_a = (*turk)->stats.a.index_min;
		return (vars);
	}
	while (vars.i < (*turk)->stats.a.size)
	{
		if (a->nbr > b->nbr && (a->nbr < vars.cur_a || a->nbr == vars.cur_a))
		{
			vars.cur_a = a->nbr;
			vars.pos_a = vars.i;
		}
		a = a->next;
		vars.i++;
	}
	return (vars);
}

t_cheap	find_cheap_to_b(t_turk **turk)
{
	t_stack		*a;
	t_stack		*b;
	t_cheap	vars;
	t_cheap	final_vars;

	a = (*turk)->stack_a;
	b = (*turk)->stack_b;
	reset_vars(&vars);
	reset_vars(&final_vars);
	while (vars.i < (*turk)->stats.a.size)
	{
		vars.cur_a = a->nbr;
		vars.pos_a = vars.i;
		get_target_b(&vars, &b, &(*turk)->stats);
		vars.rotate = find_cheap_rotate(&vars, (*turk)->stats.a.size, (*turk)->stats.b.size);
		vars.moves = calculate_moves(&vars, (*turk)->stats.a.size, (*turk)->stats.b.size);
		if (vars.moves < final_vars.moves || vars.i == 0)
			update_final_var(&vars, &final_vars);
		if (final_vars.moves == 1 )
			return (final_vars);
		a = a->next;
		vars.i++;
	}
	return (final_vars);
}

void	start_turkish(t_turk **turk)
{
	pb(turk);
	pb(turk);
	get_stats(&(*turk)->stats.a, (*turk)->stack_a);
	get_stats(&(*turk)->stats.b, (*turk)->stack_b);
}
