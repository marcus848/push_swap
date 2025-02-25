/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:33:41 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 19:58:07 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	turkish(t_turk **turk)
{
	start_turkish(turk);
	ft_printf("---STATS---\n");
	ft_printf("      A | B\n");
	ft_printf("min:  %d | %d\n", (*turk)->stats.a.min, (*turk)->stats.b.min);
	ft_printf("imin: %d | %d\n", (*turk)->stats.a.index_min, (*turk)->stats.b.index_min);
	ft_printf("imax: %d | %d\n", (*turk)->stats.a.max, (*turk)->stats.b.max);
	ft_printf("imax: %d | %d\n", (*turk)->stats.a.index_max, (*turk)->stats.b.index_max);
	ft_printf("size: %d | %d\n", (*turk)->stats.a.size, (*turk)->stats.b.size);
	ft_printf("-----------\n");
}

void	start_turkish(t_turk **turk)
{
	pb(turk);
	pb(turk);
	get_stats(&(*turk)->stats.a, (*turk)->stack_a);
	get_stats(&(*turk)->stats.b, (*turk)->stack_b);
}
