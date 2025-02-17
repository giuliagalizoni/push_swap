#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> // checar depois
# include <stdio.h> // TIRAR
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				above_median;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;


void	ft_error(void);
void	init_a(t_node **a, char **argv);
int		check_syntax(char *str);
int		check_dup(t_node *stack, int value);
void	free_stack(t_node **stack);

#endif
