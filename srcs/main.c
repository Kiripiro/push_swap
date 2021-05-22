/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:36:51 by atourret          #+#    #+#             */
/*   Updated: 2021/05/22 15:38:40 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_main	main;
	int		start;

	start = 0;
	ft_bzero(&main, sizeof(t_main));
	if (ac == 1)
		quit(&main, "Error.\nMissing arguments.\n", 0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		start = -1;
	}
	parsing(&main, av, start);
	solver(&main, ac - 1);
	dprintf(1, "\n-----A----\n");
	print_list(main.stack_a);
	dprintf(1, "\n-----B----\n");
	print_list(main.stack_b);
	quit(&main, "", 1);
	return (0);
}