/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:16:03 by leodauga          #+#    #+#             */
/*   Updated: 2021/05/29 18:38:26 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	solve_3(t_list_int **stack)
{
	if ((*stack)->content > (*stack)->next->content)
	{
		if ((*stack)->content > (*stack)->next->next->content)
		{
			rotate(stack, A);
			if ((*stack)->content > (*stack)->next->content)
				swap(stack, A);
		}
		else
			swap(stack, A);
	}
	else
	{
		if (((*stack)->content < (*stack)->next->content) && \
		((*stack)->content > (*stack)->next->next->content))
			reverse_rotate(stack, A);
		if ((*stack)->next->content > (*stack)->next->next->content)
		{
			swap(stack, A);
			rotate(stack, A);
		}
	}
}

void	solve_4(t_main *main, int rank)
{
	while (main->stack_a->rank != rank)
	{
		if (check_move_chunk(main->stack_a, (main->lst_size / 2)))
			rotate(&main->stack_a, A);
		else
			reverse_rotate(&main->stack_a, A);
	}
	if (!check_sorted(main->stack_a))
	{
		pb(&main->stack_a, &main->stack_b);
		solve_3(&main->stack_a);
		pa(&main->stack_a, &main->stack_b);
	}
}

void	solve_5(t_main *main)
{
	while (main->stack_a->rank != 1)
	{
		if (check_move_chunk(main->stack_a, (main->lst_size / 2)))
			rotate(&main->stack_a, A);
		else
			reverse_rotate(&main->stack_a, A);
	}
	pb(&main->stack_a, &main->stack_b);
	solve_4(main, 2);
	pa(&main->stack_a, &main->stack_b);
}
