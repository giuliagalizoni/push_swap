/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:44:33 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/20 22:40:54 by giuliagaliz      ###   ########.fr       */
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

void	set_top(t_node **stack, t_node *cheapest, char name)
{
	while (*stack != cheapest)
	{
		if (name == 'a')
		{
			if (cheapest->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (name == 'b')
		{
			if (cheapest->above_median)
				rb(stack, 0);
			else
			{
				ft_printf("caiu no else\n");
				rrb(stack, 0);
				ft_printf("saiu do rrb\n");
			}
		}
	}
}

static void	move_a_b(t_node **a, t_node **b)
{
	t_node *cheapest;

	ft_printf("STACK B:\n");
	print_stack(*b);
	ft_printf("----------------------------------------\n");
	ft_printf("STACK A:\n");
	print_stack(*a);
	ft_printf("----------------------------------------\n");
	cheapest = get_cheapest(*a);
	ft_printf("cheapest->value: %d\n", cheapest->value);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		ft_printf("first if\n");
		rotate_both(a, b, cheapest);
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		ft_printf("second if\n");
		rev_rotate_both(a, b, cheapest);
	}
	set_top(a, cheapest, 'a');
	ft_printf("set top a\n");
	set_top(b, cheapest->target, 'b');
	ft_printf("set top b\n");
	pb(b, a, 0);
	ft_printf("finish move_a_b\n");
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
	// push the first two nodes if a is bigger than 3 and not sorted
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a, 0);
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a, 0);
	// if after pushing the first two nodes a is still bigger than 3 and not sorted, we push acoording to the target node
	while (len-- > 3 && !is_sorted(*a))
	{
		ft_printf("len: %d\n", len);
		// print_stack(*a);
		init_nodes_a(*a, *b);
		move_a_b(a, b);
	}
	small_sort(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_a(a, b);
	}
	current_index(*a);
	final_sort(a);
}
