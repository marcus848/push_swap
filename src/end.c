/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:11:49 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 18:17:28 by marcudos         ###   ########.fr       */
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
	free((*turk));
}
