/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:42:33 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/26 15:05:10 by marcudos         ###   ########.fr       */
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

void	print_stacks(t_turk **turk)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*ta;
	t_stack	*tb;

	a = (*turk)->stack_a;
	b = (*turk)->stack_b;
	ta = a->next;
	tb = b->next;
	ft_printf("--STACKS--\nA  | B\n");
	ft_printf("%.2d | %.2d\n", a->nbr, b->nbr);
	while (a != ta || b != tb)
	{
		if (ta != a)
			ft_printf("%.2d | ",ta->nbr);
		else if (ta == a && tb != b)
			ft_printf("  | ");
		if (tb != b)
			ft_printf("%.2d\n", tb->nbr);
		else
			ft_printf("\n");
		if (ta != a)
			ta = ta->next;
		if (tb != b)
			tb = tb->next;
	}
}

void	print_stats(t_turk **turk)
{
	ft_printf("---STATS---\n");
	ft_printf("       A | B\n");
	ft_printf("min:  %.2d | %.2d\n", (*turk)->stats.a.min, (*turk)->stats.b.min);
	ft_printf("imin: %.2d | %.2d\n", (*turk)->stats.a.index_min, (*turk)->stats.b.index_min);
	ft_printf("imax: %.2d | %.2d\n", (*turk)->stats.a.max, (*turk)->stats.b.max);
	ft_printf("imax: %.2d | %.2d\n", (*turk)->stats.a.index_max, (*turk)->stats.b.index_max);
	ft_printf("size: %.2d | %.2d\n", (*turk)->stats.a.size, (*turk)->stats.b.size);
	ft_printf("-----------\n");
}

void	print_vars(t_cheapest *vars)
{
	ft_printf("---VARS---\n");
	ft_printf("cur_a:    %d\n", vars->cur_a);
	ft_printf("pos_a:    %d\n", vars->pos_a);
	ft_printf("target_a: %d\n", vars->target_b);
	ft_printf("pos_b:    %d\n", vars->pos_b);
}
