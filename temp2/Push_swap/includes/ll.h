#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_node
{
	void		*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_list
{
	t_node *first;
	t_node *last;
	size_t size;
	void (*_del)(void *);
}				t_list;

t_list	*_list_init();
void	_list_clear(t_list *lst);
t_node	*_list_new_node(void *new_content);
int		_list_add_at_end(t_list *lst, t_node *new_node);
int		_list_add_at_front(t_list *lst, t_node *new_node);
int		_list_delete_first(t_list *lst);
int		_list_delete_last(t_list *lst);

// int		_list_init_and_fill(t_list **lst, char *s1, char *s2, char *s3);
// int		_list_insert_at(t_list **lst, t_node *new_node, size_t position);
// //void	_list_print(t_list *lst, char *sep, char *last);
// t_node	*_list_element_at(t_list *lst, size_t position);
// int		_list_delete_last(t_list *lst);
// int		_list_delete_at(t_list **lst, size_t position);
// t_node	*_list_node_dup(t_node *the_node);
// int	_list_swap_nodes(t_list **lst, size_t index1, size_t index2);

#endif
