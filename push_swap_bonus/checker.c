#include "push_swap_bonus.h"

static int	apply_operation(t_bs_list **stack_a, t_bs_list **stack_b, char *line)
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
	while(line)
	{
		if (!apply_operation(stack_a, stack_b, line))
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

static void	push_swap(t_bs_list **stack_a, t_bs_list **stack_b)
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
	t_bs_list	*a;
	t_bs_list	*stack_a;
	t_bs_list	*stack_b;
	char		**nbrs_strs;
	int			valid;

	if (argc == 1)
		return (0);
	nbrs_strs = isvalid(argv, &valid);
	if (!valid)
		return (free_2d(nbrs_strs), write(2, "Error\n", 6), 0);
	stack_a = NULL;
	stack_a = create_stack_a(stack_a, nbrs_strs);
	a = stack_a;
	nbrs_strs = NULL;
	if (isdup(stack_a))
		return (write(2, "Error\n", 6), ft_lstclear(&stack_a), 0);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	if (!read_and_execute(&a, &stack_b))
		return (ft_lstclear(&a), ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
	if (sorted_and_b_empty(a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_lstclear(&a), ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}
