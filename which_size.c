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

static int	find_max(t_list *stack_b)
{
	int	max_index;

	max_index = -2147483648;
	while(stack_b)
	{
		if (stack_b->value > max_index)
			max_index = stack_b->value;
		stack_b = stack_b->next;
	}
	return (max_index);
}

static void	push_chunks(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	t_list	*a;
	int		i;

	i = 0;
	a = *stack_a;
	while(a)
	{
		if (a->index <= i)
			pb(stack_a, stack_b);
		else if (a->index <= i + chunk_size)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			a = a->next;
		i++;
	}
}

static void	push_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	while(b)
	{
		if (b->index == find_max(b))
		{
			if (b->index >= ft_lstsize(b) / 2)
			{
				while(b != *stack_b)
					rb(stack_b);
			}
			else
			{
				while(b != *stack_b)
					rrb(stack_b);
			}
			pa(stack_b, stack_a);
			b = *stack_b;
		}
		b = b->next;
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
