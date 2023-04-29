/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:06:29 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/29 14:36:32 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# define RARB 1
# define RRARB 2
# define RARRB 3
# define RRARRB 4

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}	t_stack;

// stack utils 1/2
t_stack		*ft_stacknew(int nbr);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);

// stack utils 2/2
void		ft_set_index(t_stack *stack);
bool		ft_is_duplicate(t_stack *stack, int nbr);
bool		ft_is_sorted(t_stack *stack);
void		ft_make_order(t_stack **stack);
void		ft_putstack(t_stack *stack);

// moves
void		ft_push(t_stack **stack_src, t_stack **stack_dest);
void		ft_rotate(t_stack **stack);
void		ft_r_rotate(t_stack **stack);
void		ft_swap(t_stack **stack);

// combos
void		ft_combo_rarb(int ind_a, int ind_b, t_stack **stack_a,
				t_stack **stack_b);
void		ft_combo_rrarb(int ind_a, int ind_b, t_stack **stack_a,
				t_stack **stack_b);
void		ft_combo_rarrb(int ind_a, int ind_b, t_stack **stack_a,
				t_stack **stack_b);
void		ft_combo_rrarrb(int ind_a, int ind_b, t_stack **stack_a,
				t_stack **stack_b);

// find things
t_stack		*ft_find_min(t_stack *stack);
t_stack		*ft_find_max(t_stack *stack);
int			ft_find_big_brother(t_stack *stack, int nbr);
int			ft_find_best_score(t_stack *stack_a, t_stack *stack_b,
				int ind_big_bro, int ind_lil_bro);
int			ft_find_best_combo(int ind_big_bro, int ind_lil_bro,
				t_stack *stack_a, t_stack *stack_b);

// libft and some basics functions
int			ft_min(int x, int y);
int			ft_max(int x, int y);
void		ft_free(void **ptr);
bool		ft_atoi(int *result, char *str);

#endif