/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:44:33 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/18 17:29:36 by ggalizon         ###   ########.fr       */
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
