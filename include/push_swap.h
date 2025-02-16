/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:26:25 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/16 18:15:41 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// include
# include "../libft/include/libft.h"

// struct
typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_limits
{
	long	max;
	long	min;
	int		index_min;
	int		index_max;
	int		size;
}	t_limits;

typedef struct s_stats
{
	t_limits	a;
	t_limits	b;
}	t_stats;

typedef struct s_turk
{
	long	max;
	long	min;
	int		size;
	t_stats	stats;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_turk;

// parse_args
int	parse_args(int ac, char **av);
int	check_is_nbr(char **av);
int	check_nbr_duplicate(int *nbrs);
int	*get_nbrs(char **av, int size_nbrs);

// utils
int	skip_spaces(char *str, int i);
int	count_nbrs(int ac, char **av);

// init_structs
t_turk	*make_turk(int ac, char **av);
t_stats	init_stats(void);

// circular_list
void	add_node(t_stack **stack, long nbr);

// stack
void	create_stack_a(t_turk *turk, char **av);
void	create_stack_a_split(t_turk *turk, char *av, int i);

// moves
void	sa(t_turk *turk, int message);
void	sb(t_turk *turk, int message);
void	ss(t_turk *turk, int message);

#endif
