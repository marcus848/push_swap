/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:10:16 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/26 15:24:39 by marcudos         ###   ########.fr       */
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
