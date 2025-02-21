/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:44:33 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/21 13:46:02 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	small_sort(t_node **stack)
{
	t_node	*max;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	max = find_max(*stack);
	if (max == *stack)
		ra(stack, 0);
	else if ((*stack)->next == max)
		rra(stack, 0);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 0);
}

static void	move_a_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rev_rotate_both(a, b, cheapest);
	set_top(a, cheapest, 'a');
	set_top(b, cheapest->target, 'b');
	pb(b, a, 0);
}

static void	move_b_a(t_node **a, t_node **b)
{
	set_top(a, (*b)->target, 'a');
	pa(a, b, 0);
}

static void	final_sort(t_node **a)
{
	t_node	*min;

	min = find_min(*a);
	while ((*a)->value != min->value)
	{
		if (min->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	sort_stack(t_node **a, t_node **b)
{
	int		len;

	len = stack_len(*a);
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a, 0);
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a, 0);
	while (len-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_b(a, b);
	}
	small_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_a(a, b);
	}
	current_index(*a);
	final_sort(a);
}
