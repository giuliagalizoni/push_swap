#include "../inc/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		ft_error();// erro ou fazer nada?
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_a(&a, argv + 1);
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
	// Check if each in put is long int
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



