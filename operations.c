#include "push_swap.h"

void	swap(t_list **stack)
{
    t_list	*first;
    t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_list **stack_1, t_list **stack_2)
{
    t_list  *first;

    first = *stack_1;
    *stack_1 = first->next;
    ft_lstadd_front(stack_2, first);
}

void	rotate(t_list **stack)
{
    t_list  *first;

    first = *stack;
    *stack = first->next;
    first->next = NULL;
    ft_lstadd_back(stack, first);
}

void	rrotate(t_list **stack)
{
    t_list  *last;
    t_list  *prev;

    prev = *stack;
    while((prev->next)->next)
        prev = prev->next;
    last = prev->next;
    prev->next = NULL;
    ft_lstadd_front(stack, last);
}
