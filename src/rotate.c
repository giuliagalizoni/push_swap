/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:57:26 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/20 21:53:37 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_node **node)
{
	t_node	*last;

	if (!(node || !(*node)->next))
		return ;
	last = find_last(*node);
	last->next = *node;
	(*node)->prev = last;
	*node = (*node)->next;
	(*node)->prev->next = NULL;
	(*node)->prev = NULL;
}

void	ra(t_node **a, int print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node **b, int print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	ft_printf("called with a->value %d and b->value %d\n", (*a)->value, (*b)->value);
	if (!print)
		ft_printf("rr\n");
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	ft_printf("b: %d cheapest->target: %d\n", (*b)->value, cheapest->target->value);
	ft_printf("a: %d cheapest: %d\n", (*a)->value, cheapest->value);
	while(*b != cheapest->target && *a != cheapest)
		rr(a, b, 0);
	current_index(*a);
	current_index(*b);
}
