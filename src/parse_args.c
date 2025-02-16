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
#include <stdlib.h>

int	parse_args(int ac, char **av)
{
	if (!check_is_nbr(av))
		return (0);
	if (!check_nbr_duplicate(get_nbrs(av, count_nbrs(ac, av))))
		return (0);
	return (1);
}

int	check_is_nbr(char **av)
{
	int	i;
	int	j;

	i = 0;
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
				if ((j != 0 && av[i][j - 1] != ' ' && av[i][j - 1] != '\t')
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

int	*get_nbrs(char **av, int size_nbrs)
{
	char	**split;
	int		*nbrs;
	int		i;
	int		j;
	int		k;

	nbrs = malloc(sizeof(int) * size_nbrs);
	if (!nbrs)
		return (0);
	i = 0;
	k = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			split = ft_split(av[i], ' ');
			j = -1;
			while (split[++j])
				nbrs[k++] = ft_atoi(split[j]);
		}
		else
			nbrs[k++] = ft_atoi(av[i]);
		i++;
	}
	return (nbrs);
}

int	check_nbr_duplicate(int *nbrs)
{
	int	i;
	int	j;

	i = 1;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
//
