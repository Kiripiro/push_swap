#include "../libft.h"

void	ft_lstaff_int(t_list_int *list)
{
	t_list_int *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("rank: %d, value:%d\n", tmp->rank, tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void	ft_lstaff_color_int(t_list_int *list, char *color)
{
	t_list_int *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%s%d\033[0m->", color, tmp->content);
		tmp = tmp->next;
	}
	printf("\033[31mNULL\033[0m\n");
}