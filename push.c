#include "push_swap.h"

void	push(t_list **stack_1, t_list **stack_2)
{
    t_list  *first;

    first = *stack_1;
    *stack_1 = first->next;
    ft_lstadd_front(stack_2, first);
}