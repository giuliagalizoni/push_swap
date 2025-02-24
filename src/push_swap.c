/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:08:25 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/24 19:03:49 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
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
static int	check_initial_syntax(const char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-' || str[i] == '+'))
            return (1);
        i++;
    }
    return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		ft_error();
	if (argc == 2)
	{
		if (check_initial_syntax(argv[1]))
			ft_error();
		if (ft_strchr(argv[1], ' '))
			argv = ft_split(argv[1], ' ');
	}
	init_a(&a, argv + 1);
	if (!(is_sorted(a)))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			small_sort(&a);
		else if (stack_len(a) <= 5)
			sort_five(&a, &b);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
