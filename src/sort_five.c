/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:02:53 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/24 17:54:25 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_to_b(t_node **a, t_node **b, int len)
{
	t_node	*min;

	while (len-- > 3)
	{
		min = find_min(*a);
		while ((*a)->value != min->value)
		{
			if (min->above_median)
				ra(a);
			else
				rra(a);
		}
		pb(b, a);
	}
}

void	sort_five(t_node **a, t_node **b)
{
	int		len;
	t_node	*target;

	len = stack_len(*a);
	current_index(*a);
	push_to_b(a, b, len);
	small_sort(a);
	while (*b)
	{
		target = (*b)->target;
		if (target)
			set_top(a, target, 'a');
		pa(a, b);
	}
	final_sort(a);
}
