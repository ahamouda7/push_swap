#include "push_swap_bonus.h"

static void	push_chunks(t_bs_list **stack_a, t_bs_list **stack_b, int chunk_size)
{
	int		i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
			pb(stack_a, stack_b);
		else if ((*stack_a)->index <= i + chunk_size)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			ra(stack_a);
		i++;
	}
}

static int	find_max(t_bs_list *stack_b)
{
	int	max_index;

	max_index = stack_b->index;
	while (stack_b)
	{
		if (stack_b->index > max_index)
			max_index = stack_b->index;
		stack_b = stack_b->next;
	}
	return (max_index);
}

static int	order(t_bs_list *stack_b, t_bs_list *max)
{
	int	order;

	order = 0;
	while (stack_b)
	{
		if (max == stack_b)
			return (order);
		order++;
		stack_b = stack_b->next;
	}
	return (-1);
}

static void	push_back(t_bs_list **stack_a, t_bs_list **stack_b)
{
	t_bs_list	*may_max;

	set_index(*stack_b);
	may_max = *stack_b;
	while (*stack_b)
	{
		if (may_max->index == find_max(*stack_b))
		{
			if (order(*stack_b, may_max) < ft_lstsize(*stack_b) / 2)
			{
				while (may_max != *stack_b)
					rb(stack_b);
			}
			else
			{
				while (may_max != *stack_b)
					rrb(stack_b);
			}
			pa(stack_b, stack_a);
			set_index(*stack_b);
			may_max = *stack_b;
		}
		else
			may_max = may_max->next;
	}
}

void	other_size(t_bs_list **stack_a, t_bs_list **stack_b)
{
	int	chunk_size;

	if (ft_lstsize(*stack_a) <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(stack_a, stack_b, chunk_size);
	push_back(stack_a, stack_b);
}
