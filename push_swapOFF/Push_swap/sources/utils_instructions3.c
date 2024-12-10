#include "../includes/push_swap.h"

static int	stack_rr_(stack *stk)
{
	void	*content;

	content = int_to_void_(*(int *)(stk->last->content));
	if (stack_pop_from_bottom_(stk) == -1)
		return (-1);
	return (_stack_push(stk, content));
}

void	rrb_(stack *b, int writen)
{
	if (!writen)
		write(1, "rrb\n", 4);
	if (stack_rr_(b) == -1)
	{
		//exit_();
	}
}

void	rra_(stack *a, int writen)
{
	if (!writen)
		write(1, "rra\n", 4);
	if (stack_rr_(a) == -1)
	{
		//exit_();
	}
}

void	rrr_(stack *a, stack *b)
{
	write(1, "rrr\n", 4);
	rrb_(b, 1);
	rra_(a, 1);
}
