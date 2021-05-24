/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:22:30 by ldauga            #+#    #+#             */
/*   Updated: 2021/05/18 14:51:15 by atourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list_int 	*ft_lstlast_int(t_list_int *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list_int 	*ft_lstn(t_list_int *lst, int n)
{
	int	limit;

	limit = 1;
	if (!lst)
		return (NULL);
	while (limit++ < n && lst->next != NULL)
		lst = lst->next;
	return (lst);
}