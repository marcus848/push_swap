/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:26:25 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/06 22:17:38 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// include
# include "../libft/include/libft.h"

// struct
typedef struct s_stack
{
	long		nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// parse_args
int	parse_args(int ac, char **av);
int	check_is_nbr(char **av);
int	count_nbrs(int ac, char **av);
int	check_nbr_duplicate(int *nbrs);
int	*get_nbrs(char **av, int size_nbrs);

// utils
int	skip_spaces(char *str, int i);

#endif
