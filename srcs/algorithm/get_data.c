/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:06:13 by leodauga          #+#    #+#             */
/*   Updated: 2021/05/29 18:36:06 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	get_nb_chunk(t_list_int *stack, int pivot)
{
	while (stack != NULL)
	{
		if (pivot > stack->rank)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	get_div(t_main *main)
{
	if (main->lst_size <= 10)
		return (2);
	else if (main->lst_size <= 100)
		return (5);
	else if (main->lst_size <= 500)
		return (11);
	return (0);
}
