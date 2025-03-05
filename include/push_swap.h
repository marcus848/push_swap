/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:26:25 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/03 21:59:57 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// include
# include "../libft/include/libft.h"

// enum
enum e_rotate
{
	er_ra,
	er_rb,
	er_rr,
	er_rrr,
	er_random
};

enum e_moves
{
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

typedef struct s_cheap
{
	long	cur_a;
	long	target_b;
	int		pos_a;
	int		pos_b;
	int		i;
	int		j;
	int		moves;
	int		rotate;
}	t_cheap;

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
int		parse_args(int ac, char **av);
int		check_is_nbr(char **av);
int		check_nbr_duplicate(int *nbrs, int size_nbrs);
int		*get_nbrs(char **av, int size_nbrs);

// utils
int		skip_spaces(char *str, int i);
int		count_nbrs(int ac, char **av);
int		max(int a, int b);
int		min(int a, int b);
void	print_move(char *mv, int message);

// init_structs
t_turk	*make_turk(int ac, char **av);
t_stats	init_stats(void);
t_moves	init_moves(void);
void	reset_moves(t_moves *moves);
void	reset_vars(t_cheap *vars);

// circular_list
void	add_node(t_stack **stack, long nbr);

// stack
void	create_stack_a(t_turk **turk, char **av);
void	create_stack_a_split(t_turk **turk, char *av, int i);

// moves_simple
void	sa(t_stack **a, int message);
void	sb(t_stack **b, int message);
void	pa(t_turk **turk, int message);
void	pb(t_turk **turk, int message);

// moves_rotate
void	ra(t_turk **turk, int message);
void	rb(t_turk **turk, int message);
void	rra(t_turk **turk, int message);
void	rrb(t_turk **turk, int message);

// moves_specials
void	ss(t_turk **turk, int message);
void	rr(t_turk **turk, int message);
void	rrr(t_turk **turk, int message);
void	pass(t_turk **turk, int message);

// sort_turk
void	sort(t_turk *turk);
void	sort_two_numbers(t_turk **turk);
void	sort_three_numbers(t_turk *turk);
void	sort_four_numbers(t_turk *turk);

// sort_utils
int		is_sort(t_turk *turk);
int		is_sort_advanced(t_turk *turk);

// turkish
void	turkish(t_turk **turk);
void	start_turkish(t_turk **turk);
t_cheap	find_cheap_to_b(t_turk **turk);
void	execute_moves(t_turk **turk, t_moves *moves, void (*f)(t_turk **, int));
t_cheap	find_right_position_a(t_turk **turk);

// turkish_utils
void	get_target_b(t_cheap *vars, t_stack **stack_b, t_stats *stats);
int	calculate_moves(t_cheap *vars, int size_a, int size_b);
void	update_final_var(t_cheap *vars, t_cheap *final_vars);
t_moves	get_moves(t_cheap *vars, int size_a, int size_b);
void	last_rotate(t_turk **turk);

// stats
void	get_stats(t_limits *limits, t_stack *stack);
void	print_stats(t_turk **turk);
void	print_stacks(t_turk **turk);
void	print_vars(t_cheap *vars);
void	print_moves(t_moves *moves);
void	print_stacksA(t_turk **turk);

//end
void	free_all(t_turk **turk);

// calculates
int	find_cheap_rotate(t_cheap *vars, int size_a, int size_b);
int	calculate_rr(t_cheap *vars);
int	calculate_rrr(t_cheap *vars, int size_a, int size_b);
int	calculate_ra(t_cheap *vars, int size_b);
int	calculate_rb(t_cheap *vars, int size_a);

// get_moves_utils
void	get_rotate_rr(t_cheap *vars, t_moves *moves);
void	get_rotate_rrr(t_cheap *vars, t_moves *moves, int size_a, int size_b);
void	get_rotate_ra(t_cheap *vars, t_moves *moves, int size_b);
void	get_rotate_rb(t_cheap *vars, t_moves *moves, int size_a);

#endif
