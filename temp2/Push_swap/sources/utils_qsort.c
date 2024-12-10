#include "../includes/push_swap.h"

static int		get_avrg_value_(stack a)
{
	t_node		*node;
	int			avrg_value;
	long long	ll;
	size_t		i;

	ll = 0;
	node = a.first;
	i = 0;
	while (i < (a.size - 2))
	{
		ll += *(int *)(node->content);
		node = node->next;
		i++;
	}
	avrg_value = ll / (a.size - 2);
	return (avrg_value);
}
//factorial 2147483647 = 2305843008139952128
//LLONG_MAX = 			 9223372036854775807

static int		q_sort_(stack *a, stack *b, int avrg_value)
{
	size_t		i;
	size_t		a_size;

	i = 0;
	a_size = a->size;
	while (i < a_size - 2)
	{
		if (*(int *)((*a).first->content) > avrg_value)
		{
			pb_(a, b);
			rb_(b, 0);
		}
		else
		{
			pb_(a, b);
		}
		i++;
	}
	return (0);
}
//the maximum number of numbers we can have in the stack is:
//4,294,967,296: from 1 to 2147483647, from -1 to -2147483647 and 0

void	quick_sort_into_b_(stack *a, stack *b)
{
	int		avrg_value;

	avrg_value = get_avrg_value_(*a); //I will try both, *a and a
	printf("avg: %d\n", avrg_value);
	if (q_sort_(a, b, avrg_value) == -1)
		exit_(a, b);
}
