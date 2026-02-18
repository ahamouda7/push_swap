/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda.student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:48:16 by ahamouda          #+#    #+#             */
/*   Updated: 2026/02/17 23:48:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_bs_list
{
	int					value;
	struct s_bs_list	*next;
	int					index;
}	t_bs_list;

size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_atoi(char *str, int *valid);
char		*return_str(char *str, char **argv);
char		**isvalid(char **argv, int *valid);
t_bs_list	*create_stack_a(t_bs_list *stack_a, char **nbrs_strs);
char		**ft_split(char const *s);
t_bs_list	*ft_lstnew(int value);
void		ft_lstadd_back(t_bs_list **lst, t_bs_list *new);
void		ft_lstadd_front(t_bs_list **lst, t_bs_list *new);
int			ft_lstsize(t_bs_list *lst);
void		ft_lstclear(t_bs_list **lst);
void		set_index(t_bs_list *stack_a);
void		sa(t_bs_list **stack_a);
void		sb(t_bs_list **stack_b);
void		ss(t_bs_list **stack_a, t_bs_list **stack_b);
void		pa(t_bs_list **stack_b, t_bs_list **stack_a);
void		pb(t_bs_list **stack_a, t_bs_list **stack_b);
void		ra(t_bs_list **stack_a);
void		rb(t_bs_list **stack_b);
void		rr(t_bs_list **stack_a, t_bs_list **stack_b);
void		rra(t_bs_list **stack_a);
void		rrb(t_bs_list **stack_b);
void		rrr(t_bs_list **stack_a, t_bs_list **stack_b);
char		*remove_spaces(char *str);
int			isdup(t_bs_list *stack_a);
void		free_2d(char **arr);
int			ft_strcmp(const char *s1, const char *s2);
char		*get_next_line(int fd);

#endif