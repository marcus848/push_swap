/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:40:39 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/06 22:17:28 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parse_args(char **av)
{
	if (!check_is_nbr(av))
		return (0);
	return (1);
}

int	check_is_nbr(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			j = skip_spaces(av[i], j);
			if (!av[i][j])
				break ;
			if (av[i][j] == '-' || av[i][j] == '+' )
			{
				if ((j != 0 && av[i][j - 1] != ' ')
					|| !ft_isdigit(av[i][j + 1]))
					return (0);
			}
			else if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
