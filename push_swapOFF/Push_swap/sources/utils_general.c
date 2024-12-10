#include "../includes/push_swap.h"

void	exit_(stack *a, stack *b)
{
	_stack_clear(a);
	_stack_clear(b);
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	*int_to_void_(int i)
{
	int *ptr;

	ptr = malloc(4);
	*ptr = i;
	return (ptr);
}
