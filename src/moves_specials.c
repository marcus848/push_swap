/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_specials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:52:13 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/24 11:54:53 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_turk *turk)
{
	sa(turk, 0);
	sb(turk, 0);
	ft_printf("ss\n");
}

void	rr(t_turk *turk)
{
	ra(turk, 0);
	sb(turk, 0);
	ft_printf("rr\n");
}

void	rrr(t_turk *turk)
{
	rra(turk, 0);
	rrb(turk, 0);
	ft_printf("rrr\n");
}
