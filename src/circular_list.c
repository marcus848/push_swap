/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:36:08 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/16 17:33:39 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_node(t_stack **stack, long nbr)
{
	t_stack	*temp;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	if (*stack == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		temp = (*stack)->prev;
		new_node->next = *stack;
		new_node->prev = temp;
		temp->next = new_node;
		(*stack)->prev = new_node;
	};
}
