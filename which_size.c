#include "push_swap.h"

void    size_2(t_list **stack_a)
{
    t_list  *a;

    a = *stack_a;
    if (a->index == 1)
        sa(stack_a);
}

void    size_3(t_list **stack_a)
{
    t_list  *a;

    a = *stack_a;
    if (a->index == 2)
        ra(stack_a);
    else if ((a->next)->index == 2)
        rra(stack_a);
    size_2(stack_a);
}

static void min_in_3(t_list **stack_a, t_list **stack_b)
{
    t_list  *a;
    t_list  *b;

    a = *stack_a;
    b = a->next;
    if (a->index == 0)
        pb(stack_a, stack_b);
    else if (b->index == 0)
    {
        ra(stack_a);
        pb(stack_a, stack_b);
    }
    else if ((b->next)->index == 0)
    {
        ra(stack_a);
        ra(stack_a);
        pb(stack_a, stack_b);
    }
}

void    size_4(t_list **stack_a, t_list **stack_b)
{
    t_list  *a;
    t_list  *b;

    a = *stack_a;
    b = a->next;
    if (a->index == 0 || b->index == 0 || (b->next)->index == 0)
        min_in_3(stack_a, stack_b);
    else
    {
        rra(stack_a);
        pb(stack_a, stack_b);
    }
    set_index(*stack_a);
    size_3(stack_a);
    pa(stack_b, stack_a);
}

void    size_5(t_list **stack_a, t_list **stack_b)
{
    t_list  *a;
    t_list  *b;
    t_list  *c;

    a = *stack_a;
    b = a->next;
    c = b->next;
    if (a->index == 0 || b->index == 0 || c->index == 0)
        min_in_3(stack_a, stack_b);
    else if ((c->next)->index == 0)
    {
        rra(stack_a);
        rra(stack_a);
        pb(stack_a, stack_b);
    }
    else
    {
        rra(stack_a);
        pb(stack_a, stack_b);
    }
    set_index(*stack_a);
    size_4(stack_a, stack_b);
    pa(stack_b, stack_a);
}

static void	push_chunks(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int		i;

	i = 0;
	while(*stack_a)
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

static int	find_max(t_list *stack_b)
{
	int	max_index;

	max_index = stack_b->index;
	while(stack_b)
	{
		if (stack_b->index > max_index)
			max_index = stack_b->index;
		stack_b = stack_b->next;
	}
	return (max_index);
}

static int	order(t_list *stack_b, t_list *max)
{
	int	order;

	order = 0;
	while(stack_b)
	{
		if (max == stack_b)
			return (order);
		order++;
		stack_b = stack_b->next;
	}
	return (-1);
}

static void	push_back(t_list **stack_a, t_list **stack_b)
{
    t_list  *may_max;

    set_index(*stack_b);
	may_max = *stack_b;
	while(*stack_b)
	{
		if (may_max->index == find_max(*stack_b))
		{
			if (order(*stack_b, may_max) < ft_lstsize(*stack_b) / 2)
			{
				while(may_max != *stack_b)
					rb(stack_b);
			}
			else
			{
				while(may_max != *stack_b)
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

void    other_size(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;

	if (ft_lstsize(*stack_a) <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(stack_a, stack_b, chunk_size);
	push_back(stack_a, stack_b);
}
