#include "../includes/push_swap.h"

static int _is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	sm_is_not_digit_(char *str) //if -1
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1] == '\0')
		return (1);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!_is_digit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	_stoi_h(char *str, int *i, int *s)
{
	int		nine;
	int		res;

	res = 0;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			*s = -1;
			++*i;
		}
	}
	while (str[*i] && str[*i] == '0')
		(*i)++;
	nine = -1;
	while (str[*i] && _is_digit(str[*i]) && ++nine < 9)
		res = res * 10 + (str[(*i)++] - '0');
	return (res);
}

static int	_stoi(char *str)
{
	int	i;
	int	res;
	int	s;

	i = 0;
	s = 1;
	res = _stoi_h(str, &i, &s);
	if (str[i] && _is_digit(str[i]))
	{
		if (res > 214748364)
			return (-1);
		else
		{
			if (str[i + 1] && _is_digit(str[i + 1]))
				return (-1);
			if (s == 1 && res == 214748364 && str[i] > '7')
				return (-1);
			if (s == -1 && res == 214748364 && str[i] > '8')
				return (-1);
			res = res * 10 + (str[i] - '0');
		}
	}
	return (res * s);
}

//this function fill a from argv, and handle the error cheking
void	fill_a_(stack *a, stack *b, char **argv)
{
	int		i;
	int		stoi_res;
	
	i = 0;
	while (argv[i])
	{
		if (sm_is_not_digit_(argv[i]))
			exit_(a, b);
		stoi_res = _stoi(argv[i]);
		if (stoi_res == -1)
			exit_(a, b);
		if (exists_in_stack_(*a, stoi_res))
			exit_(a, b);
		if (stack_push_to_bottom_(a, int_to_void_(stoi_res)) == -1)
			exit_(a, b);
		i++;
	}
}
