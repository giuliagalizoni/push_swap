/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:08:25 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/20 22:54:13 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

// Debugging purposes
void	print_stack(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	while (curr)
	{
		ft_printf("%d - ", curr->value);
		ft_printf("index: %d - ", curr->index);
		ft_printf("above median: %s - ", curr->above_median ? "yes" : "no");
		ft_printf("cheapest: %s - ", curr->cheapest ? "yes" : "no");
		ft_printf("cost: %d - ", curr->cost);
		if (curr->target)
			ft_printf("target: %d", curr->target->value);
		curr = curr->next;
		ft_printf("\n");
	}
	ft_printf("stack printed\n");
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1); // erro ou fazer nada?
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
	is_sorted(a) ? print_stack(a) : ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
// Declare pointers to 2 lists - stack a and b
	// Set the pointers to NULL

// Handle input errors - argc >= 2, argv[1] != NULL or ""
	// If argc < 2, print error message and exit
	// If argv[1] == NULL, print error message and exit

// Handle input cases: one single string or multiple strings
	// If it's one string, call ft_split()

// Init stack a adding each input number as a node
	// Hanfle integer overflow, duplicate and sytax errors (invalid chars)
		// If erros, free stack a and return error
	// Check if eachin put is long int
		// If it's string, convert to long using ft_atol()
	// Create and append nodes to stack a
		// If malloc fails, free stack a and return error

// Check if stack a is sorted
	// If not, implement sorting algorithm
		// check if it's 2 numbers
			// if so, swap
		// check if it's 3 numbers
			// if so, implement small_sort()
		// check if it's 4 or more numbers
			// if so, implement algorithm

// Functions/files
	// handle errors
	// operations - sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
	// stack lenght and last node (libft?)
	// Min and Max nodes
