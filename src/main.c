/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:26:03 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/15 21:49:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_turk	*turk;

	if (ac == 1)
		return (0);
	if (!parse_args(ac, &av[1]))
	{
		ft_printf("Error\n");
		return (0);
	}
	turk = make_turk(ac, av);
	ft_printf("size: %d\n", turk->size);
	ft_printf("max a: %d\n", turk->stats.a.index_max);
}
