#include "../includes/ll.h"

void	_list_clear(t_list *lst)
{
	t_node	*node;
	t_node	*temp;

	if (lst == NULL)
		return ;
	node = (*lst).first;
	while (node)
	{
		temp = node;
		node = node->next;
		if (((*lst)._del) != NULL)
			((*lst)._del)(temp->content);
		free(temp);
		temp = NULL;
	}
	free(lst);
	lst = NULL;
}
