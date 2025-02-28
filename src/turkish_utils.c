/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:10:16 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/27 17:36:24 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_target_b(t_cheap *vars, t_stack **stack_b, t_stats *stats)
{
	t_stack	*temp;

	temp = (*stack_b)->next;
	vars->target_b = (*stack_b)->nbr;
	vars->pos_b = 0;
	vars->j = 1;
	if (vars->cur_a < stats->b.min)
	{
		vars->target_b = stats->b.max;
		vars->pos_b = stats->b.index_max;
		return ;
	}
	while ((*stack_b) != temp)
	{
		if (temp->nbr < vars->cur_a)
		{
			if (vars->target_b > vars->cur_a || temp->nbr > vars->target_b)
			{
				vars->pos_b = vars->j;
				vars->target_b = temp->nbr;
			}
		}
		temp = temp->next;
		vars->j++;
	}
}

int	calculate_moves(t_cheap *vars, int size_a, int size_b)
{
	int	type;

	type = vars->rotate;
	if (type == er_rr)
		return (calculate_rr(vars));
	else if (type == er_rrr)
		return (calculate_rrr(vars, size_a, size_b));
	else if (type == er_ra)
		return (calculate_ra(vars, size_b));
	return (calculate_rb(vars, size_a));
}

void	update_final_var(t_cheap *vars, t_cheap *final_vars)
{
	final_vars->rotate = vars->rotate;
	final_vars->i = vars->i;
	final_vars->j = vars->j;
	final_vars->target_b = vars->target_b;
	final_vars->cur_a = vars->cur_a;
	final_vars->pos_b = vars->pos_b;
	final_vars->pos_a = vars->pos_a;
	final_vars->moves = vars->moves;
}

t_moves	get_moves(t_cheap *vars, int size_a, int size_b)
{
	int	type;
	t_moves	moves;

	moves = init_moves();
	type = vars->rotate;
	if (type == er_rr)
		get_rotate_rr(vars, &moves);
	else if (type == er_rrr)
		get_rotate_rrr(vars, &moves, size_a, size_b);
	else if (type == er_ra)
		get_rotate_ra(vars, &moves, size_b);
	else if (type == er_rb)
		get_rotate_rb(vars, &moves, size_a);
	return (moves);
}

void	last_rotate(t_turk **turk)
{
	t_moves	moves;
	
	moves = init_moves();
	moves.i_ra = (*turk)->stats.a.index_min;
	execute_moves(turk, &moves, pass);
}
