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