#ifndef HEADER_H
# define HEADER_H

# include "ll.h"

typedef t_list stack;

# include <limits.h>

typedef struct	s_best_moves
{
	int		rb;
	int		rrb;
	int		ra;
	int		rra;
	int		rr;
	int		rrr;
	int		total;
}				t_bm;

// ======== The Program ========
void	push_swap(int argc, char **argv);


// ======== Parsing ========
void	parse_to_a_(stack *a, stack *b, int argc, char **argv);
char	**_split_(char *str);
void	fill_a_(stack *a, stack *b, char **argv);


// ======== Stack ========
stack	*_stack_init();
void	_stack_clear(stack *stk);
int		exists_in_stack_(stack stk, int value);
int		stack_push_to_bottom_(stack *stk, void *content);
int		_stack_push(stack *stk, void *content);
int		_stack_pop(stack *stk);
int		stack_pop_from_bottom_(stack *stk);


// ======== Exit ========
void	exit_s_(stack *a, stack *b);
void	exit_(stack *a, stack *b);


// ======== QUICK SORT ========
void	quick_sort_into_b_(stack *a, stack *b);
void	last_sort_into_a_(stack *a, stack *b);


// ======== INSTRUCTIONS ========
void	pb_(stack *a, stack *b);
void	rb_(stack *b, int writen);
void	pa_(stack *a, stack *b);
void	ra_(stack *a, int writen);
void	rr_(stack *a, stack *b);
void	rrb_(stack *b, int writen);
void	rra_(stack *a, int writen);
void	rrr_(stack *a, stack *b);


// ======== GENERAL FUNCTIONS ========
void	*int_to_void_(int i);


// ======== To Delete ========
void	print_stack_info(stack stk, char *stack_name);

#endif
