#include "push_swap.h"

void    size_2(t_list **stack_a)
{
    t_list  *a;

    a = *stack_a;
    if (a->index == 1)
        swap(stack_a);
}

void    size_3(t_list **stack_a)
{
    t_list  *a;

    a = *stack_a;
    if (a->index == 2)
        rotate(stack_a);
    else if ((a->next)->index == 2)
        rrotate(stack_a);
    size_2(stack_a);
}

static void min_in_3(t_list **stack_a, t_list **stack_b)
{
    t_list  *a;
    t_list  *b;

    a = *stack_a;
    b = a->next;
    if (a->index == 0)
        push(stack_a, stack_b);
    else if (b->index == 0)
    {
        rotate(stack_a);
        push(stack_a, stack_b);
    }
    else if ((b->next)->index == 0)
    {
        rotate(stack_a);
        rotate(stack_a);
        push(stack_a, stack_b);
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
        rrotate(stack_a);
        push(stack_a, stack_b);
    }
    set_index(*stack_a);
    size_3(stack_a);
    push(stack_b, stack_a);
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
        rrotate(stack_a);
        rrotate(stack_a);
        push(stack_a, stack_b);
    }
    else
    {
        rrotate(stack_a);
        push(stack_a, stack_b);
    }
    set_index(*stack_a);
    size_4(stack_a, stack_b);
    push(stack_b, stack_a);
}

// void    other_size(t_list **stack_a, t_list **stack_b)
// {

// }
