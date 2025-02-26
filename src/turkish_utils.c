/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:10:16 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/26 20:22:29 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_target_b(t_cheapest *vars, t_stack **stack_b, t_stats *stats)
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

int	get_moves(t_cheapest *vars, t_turk **turk)
{
	t_turk	*t;
	t_moves	moves;
	int		best_a;
	int		best_b;
	int		best;

	t = (*turk);
	reset_moves(&moves);
	best_a = find_best_rotate(vars->pos_a, t->stats.a.size);
	best_b = find_best_rotate(vars->pos_b, t->stats.b.size);
	best = define_rotate(vars, turk, best_a, best_b);
	if (best == er_ra)
		ft_printf("ra\n\n");
	if (best == er_rb)
		ft_printf("rb\n\n");
	if (best == er_rr)
		ft_printf("rr\n\n");
	if (best == er_rrr)
		ft_printf("rrr\n\n");
	return (1);
	
}

int	find_best_rotate(int index, int size)
{
	if (index >= size / 2)
		return (er_rrr);
	return (er_rr);
}

int	define_rotate(t_cheapest *vars, t_turk **turk, int best_a, int best_b)
{
	t_turk	*t;
	int		moves_rr;
	int		moves_rrr;
	int		moves_double_a;
	int		moves_double_b;

	t = (*turk);
	if (best_a == er_rr && best_b == er_rr)
		return (er_rr);
	else if (best_a == er_rrr && best_b == er_rrr)
		return (er_rrr);
	moves_double_a = vars->pos_a + (vars->pos_b - t->stats.b.size) + 1;
	moves_double_b = vars->pos_b + (vars->pos_a - t->stats.a.size) + 1;
	moves_rr = max(vars->pos_a, vars->pos_b);
	moves_rrr = min(vars->pos_a, vars->pos_b);
	if (moves_double_a < moves_rr && moves_double_a < moves_rrr)
		return (er_ra);
	if (moves_double_b < moves_rr && moves_double_b < moves_rrr)
		return (er_rb);
	if (moves_rr <= moves_rrr)
		return (er_rr);
	return (er_rrr);
}
//
// int	find_best_rotate(t_cheapest *vars, int size_a, int size_b)
// {
// 	double	d_ra;
// 	double	d_rb;
// 	double	d_rr;
// 	double	d_rrr;
//
// 	d_ra = (float)vars->pos_a / size_a;
// 	d_rb = (float)vars->pos_b / size_b;
// 	d_rr = max(d_ra, d_rb);
// 	d_rrr = 1.0 - min(d_ra, d_rb);
// 	if (d_rr < d_rrr)
// 		return (er_rr);
// 	return (er_rrr);
// }

//
// int	find_best_rotate(t_cheapest *vars, int size_a, int size_b)
// {
// 	t_moves	moves;
// 	int	max_rr;
// 	int	max_rrr;
// 	int	random;
//
// 	moves.i_ra = vars->pos_a;
// 	moves.i_rb = vars->pos_b;
// 	moves.i_rra = size_a - vars->pos_a;
// 	moves.i_rrb = size_b - vars->pos_b;
// 	max_rr = max(moves.i_ra, moves.i_rb);	
// 	max_rrr = max(moves.i_rra, moves.i_rrb);
// 	random = min(moves.i_ra, moves.i_rra) + min(moves.i_rb, moves.i_rrb);
// 	if (random <= max_rr && random <= max_rrr)
// 		return (er_random);
// 	else if (max_rrr <= max_rr && max_rrr <= random)
// 		return (er_rrr);
// 	return (er_rr);
// }
