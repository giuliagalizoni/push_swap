/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:35:50 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/18 17:48:36 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_node **from, t_node **to)
{
	t_node	*pushed;

	if (!from || !*from)
		return ;
	pushed = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (!*to)
	{
		*to = pushed;
		pushed->next = NULL;
	}
	else
	{
		pushed->next = *to;
		pushed->next->prev = pushed;
		*to = pushed;
	}
}

void	pa(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
