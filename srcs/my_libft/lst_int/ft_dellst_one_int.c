#include "../libft.h"

void	ft_dellst_one_int(t_list_int **list, int i)
{
	t_list_int 	*tmp;
	t_list_int 	*ptmp;
    int     limit;

    limit = 1;
	if (*list == NULL)
		return ;
	if (ft_lstsize_int(*list) < i)
		return ;
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = *list;
	ptmp = *list;
	while (limit != i && tmp->next != NULL)
	{
		ptmp = tmp;
		tmp = tmp->next;
		limit++;
	}
	ptmp->next = tmp->next;
	if (tmp->next == NULL)
		ptmp->next = NULL;
	free(tmp);
}