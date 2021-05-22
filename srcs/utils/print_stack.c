/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:26:39 by atourret          #+#    #+#             */
/*   Updated: 2021/05/19 16:31:24 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	print_list(t_list_int *stack)
{
	t_list_int *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		dprintf(1, "| rank = %d | content = %d |\n", tmp->rank, tmp->content);
		tmp = tmp->next;
	}
}