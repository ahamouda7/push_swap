#include "push_swap.h"

void	rotate(t_list **stack)
{
    t_list  *first;

    first = *stack;
    *stack = first->next;
    first->next = NULL;
    ft_lstadd_back(stack, first);
}