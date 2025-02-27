/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:02:33 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/26 19:29:03 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_cheap_rotate(t_cheap *vars, int size_a, int size_b)
{
	int	moves_rr;
	int	moves_rrr;
	int	moves_ra;
	int	moves_rb;

	moves_rr = calculate_rr(vars);
	moves_rrr = calculate_rrr(vars, size_a, size_b);
	moves_ra = calculate_ra(vars, size_b);
	moves_rb = calculate_rb(vars, size_a);
	if (moves_rr <= moves_rrr && moves_rr <= moves_ra && moves_rr <= moves_rb)
		return (er_rr);
	if (moves_ra <= moves_rrr && moves_ra <= moves_rr && moves_ra <= moves_rb)
		return (er_ra);
	if (moves_rb <= moves_rrr && moves_rb <= moves_ra && moves_rb <= moves_rr)
		return (er_rb);
	return (er_rrr);
}

int	calculate_rr(t_cheap *vars)
{
	return (max(vars->pos_a, vars->pos_b));
}

int	calculate_rrr(t_cheap *vars, int size_a, int size_b)
{
	int	a;
	int	b;

	a = size_a - vars->pos_a;
	b = size_b - vars->pos_b;
	return (max(a, b));
}

int	calculate_ra(t_cheap *vars, int size_b)
{
	int	a;
	int	b;

	a = vars->pos_a;
	b = size_b - vars->pos_b;
	return (a + b);
}

int	calculate_rb(t_cheap *vars, int size_a)
{
	int	a;
	int	b;

	b = vars->pos_b;
	a = size_a - vars->pos_a;
	return (a + b);
}
