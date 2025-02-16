/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:07:36 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/16 17:38:32 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_turk	*make_turk(int ac, char **av)
{
	t_turk	*turk;

	turk = malloc(sizeof(t_turk));
	turk->size = count_nbrs(ac, av);
	turk->stats = init_stats();
	turk->min = 0;
	turk->max = 0;
	turk->stack_a = NULL;
	turk->stack_b = NULL;
	return (turk);
}

t_stats	init_stats(void)
{
	t_stats	stats;

	stats.a.max = 0;
	stats.a.min = 0;
	stats.a.index_max = 0;
	stats.a.index_min = 0;
	stats.a.size = 0;
	stats.b.max = 0;
	stats.b.min = 0;
	stats.b.index_max = 0;
	stats.b.index_min = 0;
	stats.b.size = 0;
	return (stats);
}
