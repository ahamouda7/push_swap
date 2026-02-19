/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:47 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:49:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	int				index;
}	t_list;

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char *str, int *valid);
char	*return_str(char *str, char **argv);
char	**isvalid(char **argv, int *valid);
void	create_stack_a(t_list **stack_a, char **nbrs_strs);
char	**ft_split(char const *s);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	set_index(t_list *stack_a);
int		sorted(t_list *stack_a);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	size_2(t_list **stack_a);
void	size_3(t_list **stack_a);
void	size_4(t_list **stack_a, t_list **stack_b);
void	size_5(t_list **stack_a, t_list **stack_b);
void	other_size(t_list **stack_a, t_list **stack_b);
char	*remove_spaces(char *str);
int		isdup(t_list *stack_a);
void	free_2d(char **arr);

#endif