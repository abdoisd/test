#include "../includes/push_swap.h"

static void free_a_and_b_(stack *a, stack *b)
{
	_stack_clear(a);
	_stack_clear(b);
}

void	_list_print(t_list lst, char *sep, char *last)
{
	t_node	*node;

	node = lst.first;
	while (node)
	{
		printf("|%d|%s", *(int *)(node->content), sep);
		node = node->next;
	}
	printf("%s", last);
}

void	_stack_print(stack stk)
{
	printf("\t\t");
	_list_print(stk, "\n\t\t", "|_|");
}

void	*_stack_top(stack stk)
{
	return (stk.first->content);
}

void	*_stack_bottom(stack stk)
{
	return (stk.last->content);
}

size_t	_stack_size(stack stk)
{
	return (stk.size);
}

void	print_stack_info(stack stk, char *stack_name)
{
	printf(" ============== %s ============== \n", stack_name);
	_stack_print(stk);
	printf("\nthe top: %d\n", *(int *)(_stack_top(stk)));
	printf("the bottom: %d\n", *(int *)(_stack_bottom(stk)));
	printf("the size: %zu\n", _stack_size(stk));
	printf("==========================================\n\n");
}

void	print_stack_info_empty(stack stk, char *str)
{
	printf("%s\n", str);
	printf("the stack:\n");
	_stack_print(stk);
	printf("\nthe top: %s\n", (char *)stk.first);
	printf("the bottom: %s\n", (char *)stk.last);
	printf("the size: %zu\n\n", _stack_size(stk));
}

void	main(int argc, char **argv)
{
	stack *a;
	stack *b;

	a = _stack_init();
	b = _stack_init();
	parse_to_a_(a, b, argc, argv);
	quick_sort_into_b_(a, b);
	last_sort_into_a_(a, b);
	print_stack_info(*a, "the end");
	free_a_and_b_(a, b);
	exit(EXIT_SUCCESS);
}
