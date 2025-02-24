/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:28:18 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/24 13:28:19 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	set_target_b(t_node *b, t_node *a)
{
	t_node	*curr;
	t_node	*target;
	long	match;

	while (b)
	{
		match = LONG_MAX;
		curr = a;
		while (curr)
		{
			if (curr->value > b->value && curr->value < match)
			{
				match = curr->value;
				target = curr;
			}
			curr = curr->next;
		}
		if (match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_nodes_b(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(b, a);
}
