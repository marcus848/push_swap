/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_specials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:52:13 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/03 21:54:34 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_turk **turk, int message)
{
	sa(&(*turk)->stack_a, 0);
	sb(&(*turk)->stack_b, 0);
	if (message)
		ft_printf("ss\n");
}

void	rr(t_turk **turk, int message)
{
	ra(turk, 0);
	rb(turk, 0);
	if (message)
		ft_printf("rr\n");
}

void	rrr(t_turk **turk, int message)
{
	rra(turk, 0);
	rrb(turk, 0);
	if (message)
		ft_printf("rrr\n");
}
