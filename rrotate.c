#include "push_swap.h"

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