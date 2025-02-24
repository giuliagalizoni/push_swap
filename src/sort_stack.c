/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:44:33 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/24 17:52:23 by ggalizon         ###   ########.fr       */
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
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
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
	pb(b, a);
}

static void	move_b_a(t_node **a, t_node **b)
{
	set_top(a, (*b)->target, 'a');
	pa(a, b);
}

void	final_sort(t_node **a)
{
	t_node	*min;

	min = find_min(*a);
	while ((*a)->value != min->value)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_node **a, t_node **b)
{
	int		len;

	len = stack_len(*a);
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a);
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
