/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:11:37 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/03 22:14:12 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void	execute_moves_checker(t_turk **turk, char *move);

int	main(int ac, char **av)
{
	t_turk	*turk;
	char	*move;

	if (ac == 1)
		return (0);
	if (!parse_args(ac, &av[1]))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (count_nbrs(ac, &av[1]) == 1)
		return (0);
	turk = make_turk(ac, av);
	create_stack_a(&turk, &av[1]);
	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		execute_moves_checker(&turk, move);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	if (is_sort(turk))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	execute_moves_checker(t_turk **turk, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		sa(&(*turk)->stack_a, 0);
	else if (!ft_strcmp(move, "sb\n"))
		sb(&(*turk)->stack_b, 0);
	else if (!ft_strcmp(move, "ss\n"))
		ss(turk, 0);
	else if (!ft_strcmp(move, "pa\n"))
		pa(turk, 0);
	else if (!ft_strcmp(move, "pb\n"))
		pb(turk, 0);
	else if (!ft_strcmp(move, "ra\n"))
		ra(turk, 0);
	else if (!ft_strcmp(move, "rb\n"))
		rb(turk, 0);
	else if (!ft_strcmp(move, "rr\n"))
		rr(turk, 0);
	else if (!ft_strcmp(move, "rra\n"))
		rra(turk, 0);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(turk, 0);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(turk, 0);
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
