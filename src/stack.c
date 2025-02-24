/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:32:17 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/24 14:38:22 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_stack_a(t_turk *turk, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
			create_stack_a_split(turk, av[i], i);
		else
		{
			nbr = ft_atoi(av[i]);
			add_node(&turk->stack_a, nbr);
			if (turk->min > nbr || i == 0)
				turk->min = nbr;
			if (turk->max < nbr || i == 0)
				turk->max = nbr;
		}
		i++;
	}
}

void	create_stack_a_split(t_turk *turk, char *av, int i)
{
	char	**split;
	long	nbr;
	int		j;

	j = -1;
	split = ft_split(av, ' ');
	while (split[++j])
	{
		nbr = ft_atoi(split[j]);
		add_node(&turk->stack_a, nbr);
		if (turk->min > nbr || i == 0)
			turk->min = nbr;
		if (turk->max < nbr || i == 0)
			turk->max = nbr;
		i++;
		free(split[j]);
	}
	free(split);
}
