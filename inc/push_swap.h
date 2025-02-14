#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> // checar depois
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

#endif
