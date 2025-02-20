#include "../inc/push_swap.h"

void	current_index(t_node *stack)
{
	int		i;
	int		med;

	i = 0;
	if (!stack)
		return ;
	med = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < med)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*curr;
	t_node	*target;
	long	match;

	while(a)
	{
		match = LONG_MIN; // LONG_MIN check if I can use library
		curr = b;

		while (curr)
		{
			if (curr->value < a->value && curr->value > match)
			{
				match = curr->value;
				target = curr;
			}
			curr = curr->next;
		}
		if (match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;

		a = a->next;
	}
}

static void set_cost_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(a) //talvez haja uma diferença entre mac e linux aqui
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - (a->index);
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}
void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX; // LONG_MAX check if I can use library
	while(stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}

void	init_nodes_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}
