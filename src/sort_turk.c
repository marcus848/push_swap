/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:39:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/16 17:47:59 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_turk(t_turk *turk)
{
	if (turk->size == 2)
		sort_two_numbers(turk);
}

void	sort_two_numbers(t_turk *turk)
{
	t_stack	*a;

	a = turk->stack_a;
	if (a->nbr > a->next->nbr)
		sa(turk, 1);
}
