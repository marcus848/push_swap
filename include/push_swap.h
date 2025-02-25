/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:26:25 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/25 18:45:08 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// include
# include "../libft/include/libft.h"

// enum
enum e_moves {
	e_sa,
	e_sb,
	e_ss,
	e_pa,
	e_pb,
	e_ra,
	e_rb,
	e_rr,
	e_rra,
	e_rrb,
	e_rrr
};

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

typedef struct s_moves
{
	int	i_sa;
	int	i_sb;
	int	i_ss;
	int	i_pa;
	int	i_pb;
	int	i_ra;
	int	i_rb;
	int	i_rr;
	int	i_rra;
	int	i_rrb;
	int	i_rrr;
	int	total;
}	t_moves;

typedef struct s_turk
{
	long	max;
	long	min;
	int		size;
	t_stats	stats;
	t_moves	moves;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_turk;

// parse_args
int	parse_args(int ac, char **av);
int	check_is_nbr(char **av);
int	check_nbr_duplicate(int *nbrs, int size_nbrs);
int	*get_nbrs(char **av, int size_nbrs);

// utils
int	skip_spaces(char *str, int i);
int	count_nbrs(int ac, char **av);

// init_structs
t_turk	*make_turk(int ac, char **av);
t_stats	init_stats(void);
t_moves init_moves(void);
void	reset_moves(t_moves *moves);

// circular_list
void	add_node(t_stack **stack, long nbr);

// stack
void	create_stack_a(t_turk **turk, char **av);
void	create_stack_a_split(t_turk **turk, char *av, int i);

// moves_simple
void	sa(t_stack **a, int message);
void	sb(t_stack **b, int message);
void	pa(t_turk **turk);
void	pb(t_turk **turk);

// moves_rotate
void	ra(t_turk **turk, int message);
void	rb(t_turk **turk, int message);
void	rra(t_turk **turk, int message);
void	rrb(t_turk **turk, int message);

// moves_specials
void	ss(t_turk **turk);
void	rr(t_turk **turk);
void	rrr(t_turk **turk);

// sort_turk
void	sort_turk(t_turk *turk);
void	sort_two_numbers(t_turk **turk);
void	sort_three_numbers(t_turk *turk);
void	sort_four_numbers(t_turk *turk);

// sort_utils
int	is_sort(t_turk *turk);

// turkish
void	turkish(t_turk *turk);

// stats
void	get_stats(t_limits *limits, t_stack *stack);

//end
void	free_all(t_turk **turk);

#endif
