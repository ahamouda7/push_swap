/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:45 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/20 10:03:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*return_str(char *str, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		argv[i] = remove_spaces(argv[i]);
		if (!*argv[i]
			|| ((*argv[i] == '-' || *argv[i] == '+') && !argv[i][1]))
			return (free(str), NULL);
		str = ft_strjoin(str, argv[i]);
		if (argv[i + 1])
			str = ft_strjoin(str, " ");
		i++;
	}
	return (str);
}

char	**isvalid(char **argv, int *valid)
{
	char	*str;
	char	**nbrs_strs;
	int		i;

	str = NULL;
	str = return_str(str, argv);
	if (!str)
		return (*valid = 0, NULL);
	nbrs_strs = ft_split(str);
	free(str);
	i = 0;
	while (nbrs_strs[i])
	{
		ft_atoi(nbrs_strs[i], valid);
		if (!*valid)
			return (free_2d(nbrs_strs), NULL);
		i++;
	}
	return (nbrs_strs);
}

void	create_stack_a(t_list **stack_a, char **nbrs_strs)
{
	int		i;
	t_list	*new;

	i = 0;
	while (nbrs_strs[i])
	{
		new = ft_lstnew(ft_atoi(nbrs_strs[i], &i));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	free_2d(nbrs_strs);
}

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		size_2(stack_a);
	else if (size == 3)
		size_3(stack_a);
	else if (size == 4)
		size_4(stack_a, stack_b);
	else if (size == 5)
		size_5(stack_a, stack_b);
	else
		other_size(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**nbrs_strs;
	t_list	*stack_a;
	t_list	*stack_b;
	int		valid;

	if (argc == 1)
		return (0);
	valid = 1;
	stack_a = NULL;
	nbrs_strs = isvalid(argv, &valid);
	if (!valid)
		return (write(2, "Error\n", 6), free_2d(nbrs_strs), 1);
	create_stack_a(&stack_a, nbrs_strs);
	nbrs_strs = NULL;
	if (isdup(stack_a))
		return (write(2, "Error\n", 6), ft_lstclear(&stack_a), 1);
	if (sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
	stack_b = NULL;
	set_index(stack_a);
	push_swap(&stack_a, &stack_b);
	return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
