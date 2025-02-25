/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:11:49 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 18:41:53 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_turk **turk)
{
	// t_turk	*t;
	// t_stack	*a;
	// t_stack	*temp;
	// t_stack	*next;
	// int		i;
	//
	// i = 0;
	// t = (*turk);
	// a = t->stack_a;
	// temp = a->next;
	// while (temp != a)
	// {
	// 	next = temp->next;
	// 	free(temp);
	// 	temp = next;
	// }
	// free((*turk)->stack_b);
	// free(a);
	// free((*turk));
	t_turk	*t = (*turk);
	t_stack	*a = t->stack_a;

	if (!a)
	{
		free(t);
		return;
	}

	t_stack	*temp = a->next;

	// Caso especial: lista com exatamente dois elementos
	if (a->next != a && a->next->next == a)
	{
		free(a->next);  // Libera o segundo nó
		free(a);        // Libera o primeiro nó
	}
	else if (a->next == a)  // Caso de apenas um nó
	{
		free(a);
	}
	else  // Caso geral para mais de dois nós
	{
		while (temp != a)
		{
			t_stack *next = temp->next;
			free(temp);
			temp = next;
		}
		free(a);
	}

	free(t);
}
