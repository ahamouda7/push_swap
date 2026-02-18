/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:47:31 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:47:31 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	*valid = 1;
	while (nbrs_strs[i])
	{
		ft_atoi(nbrs_strs[i], valid);
		if (!*valid)
			return (free_2d(nbrs_strs), *valid = 0, NULL);
		i++;
	}
	return (nbrs_strs);
}

t_bs_list	*create_stack_a(t_bs_list *stack_a, char **nbrs_strs)
{
	int			i;
	int			valid;
	t_bs_list	*new;

	i = 0;
	while (nbrs_strs[i])
	{
		valid = 1;
		new = ft_lstnew(ft_atoi(nbrs_strs[i], &valid));
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	free_2d(nbrs_strs);
	return (stack_a);
}
