#include "../includes/ll.h"

int		_list_add_at_front(t_list *lst, t_node *new_node)
{
	if (lst == NULL || new_node == NULL)
		return (-1);
	if ((*lst).first == NULL)
		(*lst).last = new_node;
	else
		(*lst).first->prev = new_node;
	new_node->next = (*lst).first;
	new_node->prev = NULL;
	(*lst).first = new_node;
	((*lst).size)++;
	return (0);
}
