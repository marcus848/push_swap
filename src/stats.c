/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:42:33 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/24 15:26:38 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_stats(t_limits *limits, t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	limits->max = stack->nbr;
	limits->min = stack->nbr;
	limits->index_max = 0;
	limits->index_min = 0;
	temp = stack->next;
	while (temp != stack)
	{
		if (temp->nbr > limits->max)
		{
			limits->index_max = i;
			limits->max = temp->nbr;
		}
		else if (temp->nbr < limits->min)
		{
			limits->index_min = i;
			limits->min = temp->nbr;
		}
		temp = temp->next;
		i++;
	}
	limits->size = i;
}
//
// void	actualize_stats(t_turk **turk, int move)
// {
// 	if (move == e_ra)
// 	{
// 		(*turk)->stats.a.index_max
// 	}
//
// }
