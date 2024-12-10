#include "../includes/ll.h"

int		_list_add_at_end(t_list *lst, t_node *new_node)
{
	if (lst == NULL || new_node == NULL)
		return (-1);
	if ((*lst).last == NULL)
		(*lst).first = new_node;
	else
		(*lst).last->next = new_node;
	new_node->prev = (*lst).last;
	new_node->next = NULL;
	((*lst).last) = new_node;
	((*lst).size)++;
	return (0);
}
