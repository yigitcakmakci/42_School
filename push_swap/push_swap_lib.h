/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:01:21 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/20 11:59:54 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					*push_swap(int argc, char **argv);
int					check_argv(char **tmp);
t_stack				*stack_init(char **tmp);
int					*array_init(t_stack *stack);
int					stack_len(t_stack *stack);
void				free_split(char **trash);
void				ft_lstclear(t_stack *lst);
void				choose_stralegy(t_stack **a, t_stack **b);

char				**set_tmp(int argc, char **argv);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
long				ft_atoi_long(const char *str);
char				**ft_split(char const *s, char c);
void				sort_hard_coded(t_stack **a);
void				sort_chunk_based(t_stack **a, t_stack **b);
void				sort_selection(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				sa(t_stack **swap);
void				sb(t_stack **swap);

void				move_stack_b(int pos, int len, t_stack **b);
int					find_pos_b(t_stack *b, int max_index);

#endif