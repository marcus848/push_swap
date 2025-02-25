/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:54:58 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 15:41:34 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_turk **turk)
{
	t_turk	*t;
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;

	t = (*turk);
	a = t->stack_a;
	b = t->stack_b;
	temp = a->next;
	while (temp != a)
	{
		temp = temp->next;
		free(temp->prev);
	}
	free((*turk)->stack_a);
	// free((*turk)->stack_b);
	free((*turk));
	free(turk);
}
