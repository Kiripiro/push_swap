/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:56:37 by atourret          #+#    #+#             */
/*   Updated: 2021/05/29 19:29:36 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_list(t_list_int *head)
{
	t_list_int	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

void	free_data(t_main *main)
{
	if (main->stack_a)
		free_list(main->stack_a);
	if (main->stack_b)
		free_list(main->stack_b);
}

void	quit(t_main *main, char *s, int success)
{
	if (success == 0)
	{
		ft_putstr_fd(s, 2);
		free_data(main);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd(s, 1);
		free_data(main);
		exit(EXIT_SUCCESS);
	}
}
