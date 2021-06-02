/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:36:51 by atourret          #+#    #+#             */
/*   Updated: 2021/06/02 17:44:50 by atourret         ###   ########lyon.fr   */
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
		quit(&main, "", 1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		start = -1;
	}
	parsing(&main, av, start);
	solver(&main);
	quit(&main, "", 1);
	return (0);
}
