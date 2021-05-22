/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:01:40 by atourret          #+#    #+#             */
/*   Updated: 2021/05/20 15:16:12 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	rotate(t_list_int **stack, int i)
{
	if (!stack || !(*stack)->next)
		return (0);
	ft_lstadd_back_int(stack, (*stack)->content);
	ft_lstlast_int(*stack)->rank = (*stack)->rank;
	ft_dellst_front_int(stack);
	if (i == A)
		ft_putstr_fd("ra\n", 1);
	else if (i == B)
		ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rr(t_list_int **stack_a, t_list_int **stack_b)
{
	if (!stack_a || !(*stack_a)->next || !stack_b || !(*stack_b)->next)
		return (0);
	rotate(stack_a, A);
	rotate(stack_b, B);
	ft_putstr_fd("rr\n", 1);
	return (1);
}

int	reverse_rotate(t_list_int **stack, int i)
{
	if (!stack || !(*stack)->next)
		return (0);
	ft_lstadd_front_int(stack, ft_lstlast_int(*stack)->content);
	(*stack)->rank = ft_lstlast_int(*stack)->rank;
	ft_dellst_back_int(stack);
	if (i == A)
		ft_putstr_fd("rra\n", 1);
	else if (i == B)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr(t_list_int **stack_a, t_list_int **stack_b)
{
	if (!stack_a || !(*stack_a)->next || !stack_b || !(*stack_b)->next)
		return (0);
	reverse_rotate(stack_a, A);
	reverse_rotate(stack_b, B);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}