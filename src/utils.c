/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:13:24 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/06 22:15:10 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	count_nbrs(int ac, char **av)
{
	int		i;
	int		j;
	int		count;
	int		minus;
	char	**split;

	count = 0;
	minus = 0;
	i = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			split = ft_split(av[i], ' ');
			while (split[j])
				j++;
			minus++;
			count += j;
		}
		i++;
	}
	return (ac + count - minus - 1);
}
