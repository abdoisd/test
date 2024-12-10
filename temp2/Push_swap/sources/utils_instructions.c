#include "../includes/push_swap.h"

static int		stack_push_to_other_(stack *stk1, stack *stk2)
{
	void	*content;

	content = int_to_void_(*(int *)(*stk1).first->content);
	if (_stack_pop(stk1) == -1)
		return (-1);
	return (_stack_push(stk2, content));
}

void	pb_(stack *a, stack *b)
{
	//exit if falure
	write(1, "pb\n", 3);
	stack_push_to_other_(a, b);
}

void	pa_(stack *a, stack *b)
{
	write(1, "pa\n", 3);
	stack_push_to_other_(b, a);
}
