/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:57:05 by atourret          #+#    #+#             */
/*   Updated: 2021/05/21 14:41:41 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	swap(t_list_int **stack, int i)
{
	if (!stack || !(*stack)->next)
		return (0);
	ft_lstadd_front_int(stack, (*stack)->next->content);
	(*stack)->rank = (*stack)->next->next->rank;
	ft_dellst_one_int(stack, 3);
	if (i == A)
		ft_putstr_fd("sa\n", 1);
	else if (i == B)
		ft_putstr_fd("sb\n", 1);
	return (1);
}

int	ss(t_list_int **stack_a, t_list_int **stack_b)
{
	if (!stack_a || !(*stack_a)->next ||!stack_b || !(*stack_b)->next)
		return (0);
	swap(stack_a, 0);
	swap(stack_b, 1);
	ft_putstr_fd("ss\n", 1);
	return (1);
}

int	pa(t_list_int **stack_a, t_list_int **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);
	ft_lstadd_front_int(stack_a, (*stack_b)->content);
	(*stack_a)->rank = (*stack_b)->rank;
	ft_dellst_front_int(stack_b);
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb(t_list_int **stack_a, t_list_int **stack_b)
{
	if (!stack_a ||!stack_b)
		return (0);
	ft_lstadd_front_int(stack_b, (*stack_a)->content);
	(*stack_b)->rank = (*stack_a)->rank;
	ft_dellst_front_int(stack_a);
	ft_putstr_fd("pb\n", 1);
	return (1);
}

