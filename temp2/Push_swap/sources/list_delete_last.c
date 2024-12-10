#include "../includes/ll.h"

int		_list_delete_last(t_list *lst)
{
	t_node	*the_node;

	if (lst == NULL || (*lst).size == 0)
		return (-1);
	if ((*lst).size == 1)
	{
		free((*lst).last);
		(*lst).first = NULL;
		(*lst).last = NULL;
		(*lst).size = 0;
		return (0);
	}
	the_node = (*lst).last;
	(*lst).last = (*lst).last->prev;
	(*lst).last->next = NULL;
	if ((*lst)._del != NULL)
		((*lst)._del(the_node->content));
	free(the_node);
	((*lst).size)--;
	return (0);
}
