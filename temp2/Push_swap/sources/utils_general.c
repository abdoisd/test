#include "../includes/push_swap.h"

void	exit_s_(stack *a, stack *b)
{
	_stack_clear(a);
	_stack_clear(b);
	exit(EXIT_SUCCESS);
}

void	exit_(stack *a, stack *b)
{
	_stack_clear(a);
	_stack_clear(b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	*int_to_void_(int i)
{
	int *ptr;

	ptr = malloc(4);
	*ptr = i;
	return (ptr);
}
