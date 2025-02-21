/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:08:57 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/21 13:56:09 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// TIRAR DEPOIS
void	print_stack(t_node *stack);

void	ft_error(void);
void	init_a(t_node **a, char **argv);
int		check_syntax(char *str);
int		check_dup(t_node *stack, int value);
void	free_stack(t_node **stack);

// handle stack
t_node	*find_last(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*get_cheapest(t_node *stack);
int		is_sorted(t_node *stack);
int		stack_len(t_node *stack);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);

// sort
void	small_sort(t_node **stack);
void	sort_stack(t_node **a, t_node **b);
void	init_nodes_a(t_node *a, t_node *b);
void	init_nodes_b(t_node *a, t_node *b);
void	current_index(t_node *stack);
void	set_top(t_node **stack, t_node *cheapest, char name);

void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);

#endif
