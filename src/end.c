/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:11:49 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 18:58:32 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_turk **turk)
{
	t_stack	*a;
	t_stack	*temp;
	t_stack *next;

	a = (*turk)->stack_a;
	temp = a->next;
	if (a->next != a && a->next->next == a)
	{
		free(a->next);
		free(a);
	}
	else if (a->next == a)
		free(a);
	else
	{
		while (temp != a)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		free(a);
	}
	free((*turk));
}
