/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:39:41 by atourret          #+#    #+#             */
/*   Updated: 2021/05/28 15:49:01 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 0
# define B 1

# include "../my_libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>


typedef struct s_main
{
	t_list_int	*stack_a;
	t_list_int	*stack_b;
	int			lst_size;
	int			next_nb;
}t_main;

void	parsing(t_main *main, char **av, int i);
void	solver(t_main *main);

int		check_move_chunk(t_list_int *stack, int pivot);

int		swap(t_list_int **stack, int i);
int		pa(t_list_int **stack_a, t_list_int **stack_b);
int		pb(t_list_int **stack_a, t_list_int **stack_b);
int		rotate(t_list_int **stack, int i);
int		reverse_rotate(t_list_int **stack, int i);
int		rrr(t_list_int **stack_a, t_list_int **stack_b);
void	free_tab(char **av);
void	quit(t_main *main, char *s, int success);

void	print_list(t_list_int *stack);

#endif