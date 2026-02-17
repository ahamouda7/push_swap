#include "push_swap_bonus.h"

int	do_op(char *s, t_ps_list **a, t_ps_list **b)
{
	if (ft_strcmp(s, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(s, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(s, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(s, "pa\n") == 0)
		pa(b, a);
	else if (ft_strcmp(s, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(s, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(s, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(s, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(s, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	read_and_execute(t_ps_list **a, t_ps_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!do_op(line, a, b))
		{
			free(line);
			write(2, "Error\n", 6);
			cleanup(a, b);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	is_sorted_and_b_empty(t_ps_list *a, t_ps_list *b)
{
	if (b != NULL)
		return (0);
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_ps_list	*a;
	t_ps_list	*b;
	char		**split_args;

	if (ac < 2)
		return (0);
	split_args = check_args(ac, av);
	if (!split_args || !check_is_num(split_args))
		return (free_split(split_args), write(2, "Error\n", 6), 1);
	a = create_stack(split_args);
	if (!a)
		return (free_split(split_args), write(2, "Error\n", 6), 1);
	b = NULL;
	free_split(split_args);
	read_and_execute(&a, &b);
	if (is_sorted_and_b_empty(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
	free_list(&b);
	return (0);
}
