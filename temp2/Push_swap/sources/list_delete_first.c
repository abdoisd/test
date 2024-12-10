#include "../includes/ll.h"

int		_list_delete_first(t_list *lst)
{
	t_node	*the_node;

	if (lst == NULL || (*lst).size == 0)
		return (-1);
	if ((lst)->size == 1)
	{
		free((*lst).first);
		(*lst).first = NULL;
		(*lst).last = NULL;
		(*lst).size = 0;
		return (0);
	}
	the_node = (*lst).first;
	(*lst).first = (*lst).first->next;
	if ((*lst)._del != NULL)
		(*lst)._del(the_node->content);
	free(the_node);
	(*lst).first->prev = NULL;
	((*lst).size)--;
	return (0);
}
