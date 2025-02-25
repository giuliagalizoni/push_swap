/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:08:25 by ggalizon          #+#    #+#             */
/*   Updated: 2025/02/25 15:43:43 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	*merge_arguments(char **args)
{
	char	*merged;
	char	*temp;
	int		i;

	merged = ft_strdup("");
	if (!merged)
		return (NULL);
	i = 0;
	while (args[i])
	{
		temp = ft_strjoin(merged, args[i]);
		free(merged);
		if (!temp)
			return (NULL);
		merged = ft_strjoin(temp, " ");
		free(temp);
		if (!merged)
			return (NULL);
		i++;
	}
	return (merged);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static char	**parse_args(char **argv)
{
	char	*merged_args;
	char	**split_args;

	merged_args = merge_arguments(argv);
	if (!merged_args || check_initial_syntax(merged_args))
	{
		free(merged_args);
		ft_error();
	}
	split_args = ft_split(merged_args, ' ');
	free(merged_args);
	if (!split_args)
		ft_error();
	return (split_args);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split_args;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && (!argv[1][0] || argv[1][0] == ' ')))
		ft_error();
	split_args = parse_args(argv + 1);
	init_a(&a, split_args);
	free_split(split_args);
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
