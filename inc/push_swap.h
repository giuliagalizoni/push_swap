/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:08:57 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/25 15:31:08 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
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
int		check_initial_syntax(const char *str);
int		check_dup(t_node *stack, int value);
void	free_stack(t_node **stack);
void	free_split(char **split);
t_node	*find_last(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*get_cheapest(t_node *stack);
int		is_sorted(t_node *stack);
int		stack_len(t_node *stack);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	small_sort(t_node **stack);
void	sort_stack(t_node **a, t_node **b);
void	init_nodes_a(t_node *a, t_node *b);
void	init_nodes_b(t_node *a, t_node *b);
void	current_index(t_node *stack);
void	set_top(t_node **stack, t_node *cheapest, char name);
void	final_sort(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

#endif
