#include "../includes/push_swap.h"

static int		stack_r_(stack *stk) /*** */
{
	void	*content;

	content = int_to_void_(*(int *)((*stk).first->content));
	if (_stack_pop(stk) == -1)
		return (-1);
	return (stack_push_to_bottom_(stk, content));
}

void	rb_(stack *b, int writen)
{
	if (!writen)
		write(1, "rb\n", 3);
	stack_r_(b);
}

void	ra_(stack *a, int writen)
{
	if (!writen)
		write(1, "ra\n", 3);
	if (stack_r_(a) == -1)
		{/*exit_();*/}
}

void	rr_(stack *a, stack *b)
{
	write(1, "rr\n", 3);
	ra_(a, 1);
	rb_(b, 1);
}
