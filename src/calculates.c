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

void	calculate_rotate(t_cheapest *vars, t_moves *moves, int size_a, int size_b)
{
	int	max_rr;
	int	max_rrr;
	int	random;
	int	temp;

	moves->i_ra = vars->pos_a;
	moves->i_rb = vars->pos_b;
	moves->i_rra = size_a - vars->pos_a;
	moves->i_rrb = size_b - vars->pos_b;
	max_rr = max(moves->i_ra, moves->i_rb);	
	max_rrr = max(moves->i_rra, moves->i_rrb);
	random = min(moves->i_ra, moves->i_rra) + min(moves->i_rb, moves->i_rrb);
	if (random <= max_rr & random <= max_rrr)
	{
		if (moves->i_ra < moves->i_rra)
			moves->i_rra = 0;
		else
			moves->i_ra = 0;
		if (moves->i_rb < moves->i_rrb)
			moves->i_rrb = 0;
		else
			moves->i_rb = 0;
	}
	if (max_rr <= random && max_rr <= max_rrr)
	{
		if (moves->i_ra == moves->i_rb)
		{
			temp = moves->i_ra;
			reset_moves(moves);
			moves->i_rr = temp;
		}
	}
}
