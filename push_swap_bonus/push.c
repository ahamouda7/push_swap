#include "push_swap_bonus.h"

static void	push(t_bs_list **stack_1, t_bs_list **stack_2)
{
	t_bs_list	*first;

	first = *stack_1;
	*stack_1 = first->next;
	ft_lstadd_front(stack_2, first);
}

void	pa(t_bs_list **stack_b, t_bs_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_bs_list **stack_a, t_bs_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
