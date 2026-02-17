#include "push_swap_bonus.h"

void	ft_lstadd_front(t_bs_list **lst, t_bs_list *new)
{
	new->next = *lst;
	*lst = new;
}
