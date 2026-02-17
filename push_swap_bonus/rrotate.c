#include "push_swap_bonus.h"

static void	rrotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev;

	prev = *stack;
	while ((prev->next)->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	ft_lstadd_front(stack, last);
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
}
