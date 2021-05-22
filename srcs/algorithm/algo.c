/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:20:11 by atourret          #+#    #+#             */
/*   Updated: 2021/05/22 16:00:41 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	solve_3(t_main *main)
{
	if (main->stack_a->content > main->stack_a->next->content)
	{
		if (main->stack_a->content > main->stack_a->next->next->content)
		{
			rotate(&main->stack_a, A);
			if (main->stack_a->content > main->stack_a->next->content)
				swap(&main->stack_a, A);
		}
		else
			swap(&main->stack_a, A);
	}
	else
	{
		if ((main->stack_a->content < main->stack_a->next->content) && \
		(main->stack_a->content > main->stack_a->next->next->content))
			reverse_rotate(&main->stack_a, A);
		if (main->stack_a->next->content > main->stack_a->next->next->content)
		{
			swap(&main->stack_a, A);
			rotate(&main->stack_a, A);
		}
	}
}

int	find_pivot(t_list_int *stack)
{
	t_list_int	*tmp;
	int	average;
	int	i;

	i = 0;
	average = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		average += tmp->content;
		tmp = tmp->next;
	}
	average = average / i;
	tmp = stack;
	while (tmp->rank != average)
		tmp = tmp->next;
	return (tmp->content);
}

void	solver(t_main *main, int values)
{
	int	average;

	if (values == 2)
		if (main->stack_a->content > main->stack_a->next->content)
			swap(&main->stack_a, A);
	if (values == 3)
		solve_3(main);
	average = find_pivot(main->stack_a);
	dprintf(1, "%d\n", average);
}
