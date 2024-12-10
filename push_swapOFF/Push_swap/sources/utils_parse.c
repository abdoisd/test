#include "../includes/push_swap.h"

void	parse_to_a_(stack *a, stack *b, int argc, char **argv)
{
	int		arg_nbr;

	if (argc == 1) //no numbers
		exit_(a, b); //exit succes, free the stacks
	if (argc == 2) //./push_swap "1"  or  ./push_swap "1 2 3 4"
	{
		if (argv[1][0] == '\0')
			exit_(a, b);
		argv = _split_(argv[1]);
	}
	arg_nbr = 1;
	while (argv[arg_nbr])
		arg_nbr++;
	if (arg_nbr == 2)
		exit_(a, b);
	if (arg_nbr == 3)
		exit_(a, b);
	fill_a_(a , b, argv + 1);
}
