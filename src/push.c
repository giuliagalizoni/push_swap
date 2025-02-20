/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:35:50 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/20 22:53:53 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*pushed;

	if (!*src)
		return ;
	pushed = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = pushed;
		pushed->next = NULL;
	}
	else
	{
		pushed->next = *dst;
		pushed->next->prev = pushed;
		*dst = pushed;
	}
}

void	pa(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
