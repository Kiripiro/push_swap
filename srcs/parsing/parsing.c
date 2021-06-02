/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:39:37 by atourret          #+#    #+#             */
/*   Updated: 2021/05/29 18:40:24 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	*fill_tab(t_main *main)
{
	int			i;
	int			*tab;
	t_list_int	*tmp;

	i = -1;
	tmp = main->stack_a;
	tab = malloc(sizeof(int) * main->lst_size);
	if (!tab)
		quit(main, "Error\n", 0);
	while (++i < main->lst_size)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
	}
	return (tab);
}

int	rank_stack(t_main *main)
{
	int			i;
	int			*tab;
	t_list_int	*tmp;

	tmp = main->stack_a;
	main->lst_size = ft_lstsize_int(tmp);
	tab = fill_tab(main);
	tab = ft_sort_int_tab(tab, main->lst_size);
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->content != tab[i])
			i++;
		tmp->rank = i + 1;
		tmp = tmp->next;
	}
	free(tab);
	return (1);
}

int	check_seen(t_main *main, int nb)
{
	t_list_int	*tmp;

	tmp = NULL;
	if (main)
		tmp = main->stack_a;
	while (tmp != NULL)
	{
		if (tmp->content == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_av(t_main *main, char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_ischar("0123456789-", av[i]))
			quit(main, "Error\n", 0);
		if (av[i] == '-')
			i++;
		while (ft_isdigit(av[i]))
			i++;
		if (av[i] || (i == 1 && av[0] == '-'))
			quit(main, "Error\n", 0);
	}
	return (1);
}

void	parsing(t_main *main, char **av, int i)
{
	long int	nb;

	while (av[++i])
	{
		if (check_av(main, av[i]))
		{
			nb = ft_atoll(av[i]);
			if (nb < INT_MIN || nb > INT_MAX)
				quit(main, "Error\n", 0);
			if (check_seen(main, nb))
				ft_lstadd_back_int(&main->stack_a, nb);
			else
				quit(main, "Error\n", 0);
		}
	}
	rank_stack(main);
}
