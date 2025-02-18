/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:08:44 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/18 17:54:20 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ft_atol(const char *str)
{
	int		i;
	long	number;
	int		flag;

	i = 0;
	number = 0;
	flag = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		(i)++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = (flag) * -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * flag);
}

static void	add_node(t_node **stack, long n)
{
	t_node	*new;
	t_node	*last;

	if (!stack)
		return ;
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = n;
	new->next = NULL;
	new->cheapest = 0;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
		return ;
	}
	else
	{
		last = find_last(*stack);
		last->next = new;
		new->prev = last;
	}
}

void	init_a(t_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
		{
			ft_printf("syntax error\n"); // debuging purposes
			free_stack(a);
			ft_error();
		}
		n = ft_atol(argv[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			ft_printf("overflow error\n"); // debuging purposes
			free_stack(a);
			ft_error();
		}
		if (check_dup(*a, n))
		{
			ft_printf("repetition error\n"); // debuging purposes
			free_stack(a);
			ft_error();
		}
		add_node(a, n);
		i++;
	}
}
