#include "Push_swap/includes/push_swap.h"

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

char	*_strdup(const char *str)
{
	int		strlen;
	char	*res;
	int		i;

	strlen = 0;
	while (str[strlen])
		strlen++;
	res = malloc(strlen + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

//2 spaces between numbers
//case "1 2 3"0
void	main(int argc, char **argv)
{
	stack *a;
	stack *b;

	// argc = 4;
	// argv = malloc((argc + 1) * sizeof(char *));
	// argv[0] = _strdup("a.out");
	// argv[1] = _strdup("1");
	// argv[2] = _strdup("2");
	// argv[3] = _strdup("-");
	// argv[4] = NULL;

	a = _stack_init();
	b = _stack_init();
	parse_to_a_(a, b, argc, argv);
	quick_sort_into_b_(a, b);
	last_sort_into_a_(a, b);
	free_a_and_b_(a, b);
	exit(EXIT_SUCCESS);
}
