#include "../inc/push_swap.h"

int	check_syntax(char *str)
{
	if (!(*str == '+' || *str == '-'|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int check_dup(t_node *stack, int value)
{
	t_node *curr;

	curr = stack;
	while (curr)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void free_stack(t_node **stack)
{
	t_node *temp;
	t_node *curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		curr->value = 0;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}
