#include "push_swap_bonus.h"

static void	rrotate(t_bs_list **stack)
{
	t_bs_list	*last;
	t_bs_list	*prev;

	prev = *stack;
	while ((prev->next)->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	ft_lstadd_front(stack, last);
}

void	rra(t_bs_list **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_bs_list **stack_b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_bs_list **stack_a, t_bs_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
}
