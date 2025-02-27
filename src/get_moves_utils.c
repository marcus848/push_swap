/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:22:34 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/27 17:32:28 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_rotate_rr(t_cheap *vars, t_moves *moves)
{
	if (vars->pos_a == vars->pos_b)
		moves->i_rr = vars->pos_a;
	else if (vars->pos_a > vars->pos_b)
	{
		moves->i_rr = vars->pos_b;
		moves->i_ra = vars->pos_a - vars->pos_b;
	}
	else if (vars->pos_b > vars->pos_a)
	{
		moves->i_rr = vars->pos_a;
		moves->i_rb = vars->pos_b - vars->pos_a;
	}
}

void	get_rotate_rrr(t_cheap *vars, t_moves *moves, int size_a, int size_b)
{
	int	a;
	int	b;

	a = size_a - vars->pos_a;
	b = size_b - vars->pos_b;
	if (a == b)
		moves->i_rrr = a;
	else if (a > b)
	{
		moves->i_rrr = b;
		moves->i_rra = a - b;
	}
	else if (b > a)
	{
		moves->i_rrr = a;
		moves->i_rrb = b - a;
	}
}

void	get_rotate_ra(t_cheap *vars, t_moves *moves, int size_b)
{
	moves->i_ra = vars->pos_a;
	moves->i_rrb = size_b - vars->pos_b;
}

void	get_rotate_rb(t_cheap *vars, t_moves *moves, int size_a)
{
	moves->i_rb = vars->pos_b;
	moves->i_rra = size_a - vars->pos_a;
}
