#include "../includes/push_swap.h"

t_bm	bm_init_()
{
	t_bm	bm;

	bm.rb = 0;
	bm.ra = 0;
	bm.rr = 0;
	bm.rrb = 0;
	bm.rra = 0;
	bm.rrr = 0;
	bm.total = INT_MAX;
	return (bm);
}

size_t		index_in_a_(int value, stack a)
{
	t_node	*node;
	size_t	i;
	int		max;
	int 	min;
	
	node = a.first;
	i = 0;
	max = *(int *)(a.first->content);
	min = *(int *)(a.first->content);
	while (node)
	{
		i++;
		if (*(int *)node->content > max)
			max = *(int *)node->content;
		if (*(int *)node->content < min)
			min = *(int *)node->content;
		if (node->next)
		{
			if (value > *(int *)(node->content) && value < *(int *)node->next->content)
				return (i);
		}
		node = node->next;
	}
	node = a.first;
	i = 0;
	if (value > max)
	{
		while (node)
		{
			if (*(int *)node->content == max)
				return (i + 1);
			node = node->next;
			i++;
		}
	}
	if (value < min)
	{
		while (node)
		{
			if (*(int *)node->content == min)
				return (i);
			node = node->next;
			i++;
		}
	}
	if (value < *(int *)(a.first->content) && value > *(int *)(a.last->content))
		return (0);
	return (0); //just for the compiler, I don't thing it can reach this place
}

t_bm	calculate_duplicates_(t_bm temp)
{
	while (temp.rb && temp.ra)
	{
		temp.rr++;
		temp.rb--;
		temp.ra--;
	}
	while (temp.rrb && temp.rra)
	{
		temp.rrr++;
		temp.rrb--;
		temp.rra--;
	}
	return (temp);
}

int		calculate_the_total_of_moves_(t_bm temp)
{
	temp.total = temp.rb + temp.ra + temp.rr + temp.rrb + temp.rra + temp.rrr;
	return (temp.total);
}

t_bm	get_a_b_moves_(stack a, stack b, size_t i, int value)
{
	size_t	index_in_a;
	t_bm	temp;

	temp = bm_init_();
	if (i <= (b.size / 2))
		temp.rb = i;
	else
		temp.rrb = b.size - i;
	index_in_a = index_in_a_(value, a);
	if (index_in_a <= (a.size / 2))
		temp.ra	= index_in_a;
	else
		temp.rra = (a.size - index_in_a);
	temp = calculate_duplicates_(temp);
	temp.total = calculate_the_total_of_moves_(temp);
	return (temp);
}

//each move is like an insertion that finish with push to a
t_bm	get_best_move_(stack a, stack b)
{
	t_bm	temp;
	size_t	i;
	t_node	*node;
	t_bm	bm;
	
	bm = bm_init_();
	i = 0;
	node = b.first;
	while (i < b.size)
	{
		temp = get_a_b_moves_(a, b, i, *(int *)(node->content));
		if (temp.total < bm.total)
			bm = temp;
		i++;
	}
	return (bm);
}

void	apply_best_move_(t_bm bm, stack *a, stack *b)
{
	while (bm.rb--)
		rb_(b, 0);
	while (bm.rrb--)
		rrb_(b, 0);
	while (bm.ra--)
		ra_(a, 0);
	while (bm.rra--)
		rra_(a, 0);
	while (bm.rr--)
		rr_(a, b);
	while (bm.rrr)
		rrr_(a, b);
	pa_(a, b);
}

int		stack_is_sorted_(stack a)
{
	t_node	*node;

	node = a.first;
	while (node)
	{
		if (node->next)
		{
			if (*(int *)(node->content) > *(int *)(node->next->content))
				return (0);
		}
		node = node->next;
	}
	return (1);
}

int	stack_min_index_(stack a)
{
	int		i;
	t_node	*node;
	int		res;
	int		min;

	min = 2147483647;
	i = 0;
	node = a.first;
	min = 2147483647;
	while (node)
	{
		if (*(int *)(node->content) < min)
		{
			res = i;
			min = *(int *)(node->content);
		}
		node = node->next;
		i++;
	}
	return (res);
}

void	correct_a_postion_(stack *a)
{
	size_t	min_index;
	t_bm	bm;

	bm = bm_init_();
	if (!stack_is_sorted_(*a))
	{
		min_index = stack_min_index_(*a);
		if (min_index <= (*a).size)
			bm.ra = min_index;
		else
			bm.rra = (*a).size - min_index;
		while (bm.ra--)
			ra_(a, 0);
		while (bm.rra--)
			rra_(a, 0);
	}
}

void	last_sort_into_a_(stack *a, stack *b)
{
	t_bm	bm;

	while (b->size > 0)
	{
		bm = get_best_move_(*a, *b);
		apply_best_move_(bm, a, b);
	}
	correct_a_postion_(a);
}

//while (b is not empty)
//for each value in b, there is one single place to put it in a
//so while loop througn b
	//if index < b.size / 2: rb up, otherwise rrb down
	//find the best combination of moves
		//find the index where to put in a
			//if index < a.size / 2: ra up, otherwise rra down
	//after finding use rr and rrr: instead of the others

//apply the moves and push to a
