#include "../includes/push_swap.h"

stack	*_stack_init()
{
	stack	*stk;

	stk = _list_init();
	if (stk == NULL)
		exit(EXIT_FAILURE);
	return (stk);
}

void	_stack_clear(stack *stk)
{
	if (stk == NULL)
		return ;
	_list_clear(stk);
}

int		exists_in_stack_(stack stk, int value)
{
	t_node	*node;

	node = stk.first;
	while (node)
	{
		if (*(int *)node->content == value)
			return (1);
		node = node->next;
	}
	return (0);
}

int		stack_push_to_bottom_(stack *stk, void *content)
{
	t_node	*new_node;

	new_node = _list_new_node(content);
	if (new_node == NULL)
		return (-1);
	return (_list_add_at_end(stk, new_node));
}
