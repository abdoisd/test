#include "../includes/ll.h"

t_node	*_list_new_node(void *new_content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = new_content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
