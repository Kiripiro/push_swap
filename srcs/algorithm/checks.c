/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:59:39 by leodauga          #+#    #+#             */
/*   Updated: 2021/05/29 18:39:20 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	check_sorted(t_list_int *stack_a)
{
	while (stack_a != NULL)
	{
		if (stack_a->next && stack_a->next->rank < stack_a->rank)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_move_chunk(t_list_int *stack, int pivot)
{
	int	first;
	int	last;
	int	i;

	i = 0;
	first = 0;
	last = 0;
	while (stack != NULL)
	{
		i++;
		if (stack->rank < pivot)
		{
			if (!first)
				first = i;
			else
				last = i;
		}
		stack = stack->next;
	}
	if (i - last <= first)
		return (0);
	return (1);
}

int	check_move_sort(t_list_int *stack, int nb)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_int(stack);
	while (stack != NULL)
	{
		i++;
		if (stack->rank == nb)
			break ;
		stack = stack->next;
	}
	if (i > size / 2)
		return (0);
	return (1);
}

int	check_largest(t_list_int *list)
{
	int	temp;

	temp = 0;
	while (list != NULL)
	{
		if (list->rank > temp)
			temp = list->rank;
		list = list->next;
	}
	return (temp);
}
