/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:20:11 by atourret          #+#    #+#             */
/*   Updated: 2021/05/29 19:05:04 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	fill_stack_a(t_main *main)
{
	while (main->stack_b)
	{
		if (check_largest(main->stack_b) == main->stack_b->rank)
			pa(&main->stack_a, &main->stack_b);
		else if (!main->stack_a)
		{
			if (check_move_sort(main->stack_b, main->lst_size))
				rotate(&main->stack_b, B);
			else
				reverse_rotate(&main->stack_b, B);
		}
		else if (check_move_sort(main->stack_b, main->stack_a->rank - 1))
			rotate(&main->stack_b, B);
		else
			reverse_rotate(&main->stack_b, B);
	}
}

void	fill_stack_b(t_main *main)
{
	int	chunk;
	int	div;
	int	move;

	div = get_div(main);
	chunk = 1;
	move = check_move_chunk(main->stack_a, (main->lst_size / div) * chunk);
	while (main->stack_a)
	{
		if (!get_nb_chunk(main->stack_a, (main->lst_size / div) * chunk))
		{
			chunk++;
			move = check_move_chunk(main->stack_a, \
				(main->lst_size / div) * chunk);
		}
		if (main->stack_a->rank < (main->lst_size / div) * chunk)
			pb(&main->stack_a, &main->stack_b);
		else if (move)
			rotate(&main->stack_a, A);
		else
			reverse_rotate(&main->stack_a, A);
	}
	fill_stack_a(main);
}

void	solver(t_main *main)
{
	if (!check_sorted(main->stack_a))
	{
		if (main->lst_size == 2)
			swap(&main->stack_a, A);
		else if (main->lst_size == 3)
			solve_3(&main->stack_a);
		else if (main->lst_size == 4)
			solve_4(main, 1);
		else if (main->lst_size == 5)
			solve_5(main);
		else
			fill_stack_b(main);
	}
}
