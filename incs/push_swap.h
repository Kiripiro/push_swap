/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:10:26 by atourret          #+#    #+#             */
/*   Updated: 2021/06/02 11:21:54 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../my_libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# define A 0
# define B 1

typedef struct s_main
{
	t_list_int	*stack_a;
	t_list_int	*stack_b;

	int			lst_size;
	int			chunk;
	int			move;
	int			div;

}t_main;

void	parsing(t_main *main, char **av, int i);

void	solver(t_main *main);

int		get_div(t_main *main);
int		get_nb_chunk(t_list_int *stack, int pivot);

int		check_sorted(t_list_int *stack_a);
int		check_move_chunk(t_list_int *stack, int pivot);
int		check_largest(t_list_int *list);
int		check_move_sort(t_list_int *stack, int nb);

void	solve_3(t_list_int **stack);
void	solve_4(t_main *main, int rank);
void	solve_5(t_main *main);

int		swap(t_list_int **stack, int i);
int		pa(t_list_int **stack_a, t_list_int **stack_b);
int		pb(t_list_int **stack_a, t_list_int **stack_b);
int		rotate(t_list_int **stack, int i);
int		reverse_rotate(t_list_int **stack, int i);
int		rrr(t_list_int **stack_a, t_list_int **stack_b);

void	quit(t_main *main, char *s, int success);

#endif
