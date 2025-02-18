/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:57:26 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/18 14:03:07 by ggalizon         ###   ########.fr       */
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
	if (!print)
		ft_printf("rr\n");
}
