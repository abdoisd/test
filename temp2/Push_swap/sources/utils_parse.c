#include "../includes/push_swap.h"

void	parse_to_a_(stack *a, stack *b, int argc, char **argv)
{
	int		arg_nbr;

	if (argc == 1) //no numbers
		exit_s_(a, b); //exit succes, free the stacks
	if (argc == 2) //one argument either "1" or "1 2 3..."
	{
		if (argv[1][0] == '\0') //if the second is ""
			exit_(a, b);
		argv = _split_(argv[1]);
	}
	arg_nbr = 1; //split make the first argv = NULL, a.out
	while (argv[arg_nbr])
		arg_nbr++;
	if (arg_nbr == 2) //a.out "1", if a.out "one" !!!
		exit_s_(a, b);
	if (arg_nbr == 3) //a.out "1 2"
	{
		printf("sort 2\n");
		exit_s_(a, b);
	}
	fill_a_(a , b, argv + 1);
}
