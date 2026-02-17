#include "push_swap_bonus.h"

void	ft_lstadd_back(t_bs_list **lst, t_bs_list *new)
{
	t_bs_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
