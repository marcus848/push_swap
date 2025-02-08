/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:26:03 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/06 20:55:37 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);

	ft_printf("Retorno: %d\n", parse_args(ac, &av[1]));
	// if (!parse_args(av))
	// {
	// 	ft_printf("error\n");
	// 	return (0);
	// }
	// else
	// 	ft_printf("success\n");
}
