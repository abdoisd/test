#include "../includes/push_swap.h"

int		_stack_push(stack *stk, void *content)
{
	t_node	*new_node;

	new_node = _list_new_node(content);
	if (new_node == NULL)
		return (-1);
	return (_list_add_at_front(stk, new_node));
}

int		_stack_pop(stack *stk)
{
	if (stk == NULL)
		return (-1);
	return (_list_delete_first(stk));
}

int		stack_pop_from_bottom_(stack *stk)
{
	return (_list_delete_last(stk));
}
