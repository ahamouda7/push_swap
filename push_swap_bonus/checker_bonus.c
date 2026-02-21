/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:46:24 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/21 17:47:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	apply_op(t_bs_list **stack_a, t_bs_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	read_and_execute(t_bs_list **stack_a, t_bs_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!apply_op(stack_a, stack_b, line))
		{
			free(line);
			write(2, "Error\n", 6);
			ft_lstclear(stack_a);
			ft_lstclear(stack_b);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static int	sorted_and_b_empty(t_bs_list *stack_a, t_bs_list *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a && stack_a->next)
	{
		if ((stack_a->next)->value < stack_a->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_bs_list	*stack_a;
	t_bs_list	*stack_b;
	char		**nbrs_strs;
	int			valid;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	nbrs_strs = isvalid(argv, &valid);
	if (!valid)
		return (free_2d(nbrs_strs), write(2, "Error\n", 6), 1);
	stack_a = create_stack_a(stack_a, nbrs_strs);
	nbrs_strs = NULL;
	if (isdup(stack_a))
		return (write(2, "Error\n", 6), ft_lstclear(&stack_a), 1);
	stack_b = NULL;
	if (!read_and_execute(&stack_a, &stack_b))
		return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 1);
	if (sorted(stack_a))
		return (write(1, "OK\n", 3), ft_lstclear(&stack_a), 0);
	if (sorted_and_b_empty(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
