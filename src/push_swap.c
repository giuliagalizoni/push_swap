/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:08:25 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/21 13:43:07 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_a(&a, argv + 1);
	if (!(is_sorted(a)))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			small_sort(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

// Debugging purposes
// void	print_stack(t_node *stack)
// {
// 	t_node	*curr;

// 	curr = stack;
// 	while (curr)
// 	{
// 		ft_printf("%d - ", curr->value);
// 		ft_printf("index: %d - ", curr->index);
// 		ft_printf("above median: %s - ", curr->above_median ? "yes" : "no");
// 		ft_printf("cheapest: %s - ", curr->cheapest ? "yes" : "no");
// 		ft_printf("cost: %d - ", curr->cost);
// 		if (curr->target)
// 			ft_printf("target: %d", curr->target->value);
// 		curr = curr->next;
// 		ft_printf("\n");
// 	}
// 	ft_printf("stack printed\n");
// }
