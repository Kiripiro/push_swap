/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:20:11 by atourret          #+#    #+#             */
/*   Updated: 2021/05/24 17:33:44 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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

int	nb_moves(t_main *main, int div)
{
	int	size;

	size = ft_lstsize_int(main->stack_a);
	return (size - (size / div + size % div));
}

int	find_content(t_list_int *stack, int pos)
{
	t_list_int *tmp;

	tmp = stack;
	if (pos == 1)
		return (tmp->content);
	while (--pos)
		tmp = tmp->next;
	return (tmp->content);
}

int	find_pivot(t_list_int *stack, int start, int end)
{
	int	mid;

	if (end < start)
		return (-1);
	if (end == start)
		return (start);
	mid = (start + end) / 2 + (start + end) % 2;
	dprintf(1, "mid: %d\n", mid);
	dprintf(1, "mid - 1: %d\n", find_content(stack, mid - 1));
	dprintf(1, "mid: %d\n", find_content(stack, mid));
	dprintf(1, "mid + 1:%d\n", find_content(stack, mid + 1));
	if ((mid < end)	&& find_content(stack, mid) > find_content(stack, mid + 1))
		return (mid);
	if ((mid > start) && find_content(stack, mid) < find_content(stack, mid - 1))
		return (mid - 1);
	if (find_content(stack, start) >= find_content(stack, mid))
		return find_pivot(stack, start, mid - 1);
	return find_pivot(stack, mid + 1, end);
}

void	sort1(t_main *main, int div)
{
	int	size;
	int	nb;
	int	pivot;

	size = ft_lstsize_int(main->stack_a);
	//dprintf(1, "size: %d\n", size);
	pivot = find_pivot(main->stack_a, 5, size);
	//dprintf(1, "half: %d\n", pivot);
	nb = nb_moves(main, div) - 1;
	//dprintf(1, "nb: %d\n", nb);
	while (nb)
	{
	//	dprintf(1, "dab: %d\n", ft_lstsize_int(main->stack_a) - nb);
	//	dprintf(1, "rank: %d | content: %d |\n", main->stack_a->rank, main->stack_a->content);
	//	dprintf(1, "half: %d\n", half);
		if (main->stack_a->content < pivot)
		{
			pb(&main->stack_a, &main->stack_b);
			nb--;
		//	print_list(main->stack_a);
		}
		if (main->stack_a->content >= pivot)
		{
			rotate(&main->stack_a, A);
			//sleep(100);
			print_list(main->stack_a);
		}
	}
}

void	sort(t_main *main, int div)
{
	int	nb;
	int	pivot;

	pivot = find_pivot(main->stack_a, 1, ft_lstsize_int(main->stack_a));
	dprintf(1, "pivot: %d\n", pivot);
	nb = nb_moves(main, div) - 1;
	dprintf(1, "nb: %d\n", nb);
	//dprintf(1, "%d\n", nb);
	//while (check_sorted(main->stack_a))
	//{
		while (nb)
		{
		//	dprintf(1, "dab: %d\n", ft_lstsize_int(main->stack_a) - nb);
		//	dprintf(1, "rank: %d | content: %d |\n", main->stack_a->rank, main->stack_a->content);
		//	dprintf(1, "half: %d\n", half);
			if (main->stack_a->content < pivot)
			{
				pb(&main->stack_a, &main->stack_b);
				nb--;
			//	print_list(main->stack_a);
			}
			if (main->stack_a->content >= pivot)
			{
				rotate(&main->stack_a, A);
				print_list(main->stack_a);
				//sleep(100);
			}
		}
		//pivot = find_pivot(main->stack_a, 5, 8);
		//dprintf(1, "pivot: %d\n", pivot);
		//sort1(main, div + 2);
		//solve_3(&main->stack_a, A);
		//while (main->stack_b)
		//	pa(&main->stack_a, &main->stack_b);
}

void	solver(t_main *main, int values)
{
	if (values == 2)
		if (main->stack_a->content > main->stack_a->next->content)
			swap(&main->stack_a, A);
	if (values == 3)
		solve_3(&main->stack_a, A);
	dprintf(1, "pivot: %d\n", find_pivot(main->stack_a, 1, 7));
	//sort(main, 2);
}
