#include "push_swap_bonus.h"

static void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*first;

	first = *stack_1;
	*stack_1 = first->next;
	ft_lstadd_front(stack_2, first);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
