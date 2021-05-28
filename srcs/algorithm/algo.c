/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:20:11 by atourret          #+#    #+#             */
/*   Updated: 2021/05/28 16:02:55 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	sorted(t_list_int *stack_a)
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

int	check_sorted(t_list_int *stack)
{
	t_list_int *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->next && (tmp->next->rank != tmp->rank + 1))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	solve_3(t_list_int **stack, int i)
{
	if ((*stack)->content > (*stack)->next->content)
	{
		if ((*stack)->content > (*stack)->next->next->content)
		{
			rotate(stack, i);
			if ((*stack)->content > (*stack)->next->content)
				swap(stack, i);
		}
		else
			swap(stack, i);
	}
	else
	{
		if (((*stack)->content < (*stack)->next->content) && \
		((*stack)->content > (*stack)->next->next->content))
			reverse_rotate(stack, i);
		if ((*stack)->next->content > (*stack)->next->next->content)
		{
			swap(stack, i);
			rotate(stack, i);
		}
	}
}

void	solve_4(t_main *main, int rank)
{
	while (main->stack_a->rank != rank)
	{
		if (check_move_chunk(main->stack_a, (main->lst_size / 2)))
			rotate(&main->stack_a, A);
		else
			reverse_rotate(&main->stack_a, A);
	}
	pb(&main->stack_a, &main->stack_b);
	solve_3(&main->stack_a, A);
	pa(&main->stack_a, &main->stack_b);
}

void	solve_5(t_main *main)
{
	while (main->stack_a->rank != 1)
	{
		if (check_move_chunk(main->stack_a, (main->lst_size / 2)))
			rotate(&main->stack_a, A);
		else
			reverse_rotate(&main->stack_a, A);
	}
	pb(&main->stack_a, &main->stack_b);
	solve_4(main, 2);
	pa(&main->stack_a, &main->stack_b);
}

int		nb_chunk(t_list_int *stack, int pivot)
{
	while (stack != NULL)
	{
		if (pivot > stack->rank)
			return (1);
		stack = stack->next;
	}
	return (0);
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

int		check_largest(t_list_int *list)
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

void	sort(t_main *main)
{
	int	chunk;
	int	div;
	int	test;

	div = get_div(main);
	chunk = 1;
	test = check_move_chunk(main->stack_a, (main->lst_size / div) * chunk);
	while (main->stack_a)
	{
		if (!nb_chunk(main->stack_a, (main->lst_size / div) * chunk))
		{
			chunk++;
			test = check_move_chunk(main->stack_a, (main->lst_size / div) * chunk);
		}
		if (main->stack_a->rank < (main->lst_size / div) * chunk)
			pb(&main->stack_a, &main->stack_b);
		else if (test)
			rotate(&main->stack_a, A);
		else
			reverse_rotate(&main->stack_a, A);
	}
	while (main->stack_b)
	{
		if (check_largest(main->stack_b) == main->stack_b->rank)
			pa(&main->stack_a, &main->stack_b);\
		else if (!main->stack_a)
		{
			if (check_move_sort(main->stack_b, main->lst_size))
				rotate(&main->stack_b, B);
			else
				reverse_rotate(&main->stack_b, B);
		}
		else if (check_move_sort(main->stack_b, main->stack_a->rank - 1))
			rotate(&main->stack_b, B);
		else
			reverse_rotate(&main->stack_b, B);
	}
}

void	solver(t_main *main)
{
	if (!sorted(main->stack_a))
	{
		if (main->lst_size == 2)
			if (main->stack_a->content > main->stack_a->next->content)
				swap(&main->stack_a, A);
		if (main->lst_size == 3)
			solve_3(&main->stack_a, A);
		if (main->lst_size == 4)
			solve_4(main, 1);
		if (main->lst_size == 5)
			solve_5(main);
		else
			sort(main);
	}
}
