/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:07:01 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/20 22:52:15 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_node **node)
{
	t_node	*last;
	t_node *second_last;

	if (!*node || !(*node)->next)
	return ;

	last = find_last(*node);
	second_last = last->prev;
	ft_printf("last->value: %d\n", last->value);
	if (last->prev)
        ft_printf("last->prev->value: %d\n", last->prev->value);
    else
        ft_printf("last->prev is NULL\n");
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *node;
	(*node)->prev = last;
	*node = last;

}

void	rra(t_node **a, int print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, int print)
{
	ft_printf("entrou no rrb\n");
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
		ft_printf("STACK B AFTER rrb:\n");
		print_stack(*b);
		ft_printf("----------------------------------------\n");
}

void	rrr(t_node **a, t_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, 0);
	current_index(*a);
	current_index(*b);
}
