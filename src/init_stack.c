#include "../inc/push_swap.h"

long	ft_atol(const char *str)
{
	int	i;
	long number;
	int	flag;

	i = 0;
	number = 0;
	flag = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		(i)++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = (flag) * -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * flag);
}
void	init_a(t_node **a, char **argv)
{
	long n;
	int i;

	i = 0;
	while(argv[i])
	{
		// check syntax errors
		// call atol
		n = ft_atol(argv[i]);
		// check overflow
		// check repetition
		// add node
	}
}
