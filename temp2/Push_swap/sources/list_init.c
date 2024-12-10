#include "../includes/ll.h"

t_list	*_list_init()
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	(*lst).first = NULL;
	(*lst).last = NULL;
	(*lst).size = 0;
	(*lst)._del = NULL;
	return (lst);
}
