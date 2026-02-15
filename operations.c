#include "push_swap.h"

static void	swap(t_list **stack)
{
    t_list	*first;
    t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

static void	push(t_list **stack_1, t_list **stack_2)
{
    t_list  *first;

    first = *stack_1;
    *stack_1 = first->next;
    ft_lstadd_front(stack_2, first);
}

static void	rotate(t_list **stack)
{
    t_list  *first;

    first = *stack;
    *stack = first->next;
    first->next = NULL;
    ft_lstadd_back(stack, first);
}

static void	rrotate(t_list **stack)
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

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
}