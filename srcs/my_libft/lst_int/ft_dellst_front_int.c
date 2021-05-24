#include "../libft.h"

void	ft_dellst_front_int(t_list_int **list)
{
	t_list_int 	*tmp;

	if (list == NULL)
		return ;
	tmp = (*list)->next;
	free(*list);
	*list = tmp;
}