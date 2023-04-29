/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:51:00 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/27 20:15:42 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_best_elem(t_stack *stack_a, t_stack *stack_b)
{
	int	ind_elem;
	int	best_score;

	ind_elem = 0;
	best_score = ft_find_best_score(stack_a, stack_b, ft_find_big_brother(stack_a, ft_nbr_at_index(stack_b, stack_b->index)), stack_b->index);
	while (stack_b)
	{
		if (best_score >= ft_find_best_score(stack_a, stack_b, ft_find_big_brother(stack_a, ft_nbr_at_index(stack_b, stack_b->index)), stack_b->index))
		{
			best_score = ft_find_best_score(stack_a, stack_b, ft_find_big_brother(stack_a, ft_nbr_at_index(stack_b, stack_b->index)), stack_b->index);
			ind_elem = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	return (ind_elem);
}

void	ft_make_best_combo(t_stack **stack_a, t_stack **stack_b)
{
	int	ind_lil_bro;
	int	ind_big_bro;
	int	best_combo;

	ind_lil_bro = ft_find_best_elem(*stack_a, *stack_b);
	ind_big_bro = ft_find_big_brother(*stack_a, ft_nbr_at_index(*stack_b, ind_lil_bro));
	best_combo = ft_find_best_combo(ind_big_bro, ind_lil_bro, *stack_a, *stack_b);
	if (best_combo == RARB)
		ft_combo_rarb(ind_big_bro, ind_lil_bro, stack_a, stack_b);
	else if (best_combo == RRARRB)
		ft_combo_rrarrb(ind_big_bro, ind_lil_bro, stack_a, stack_b);
	else if (best_combo == RRARB)
		ft_combo_rrarb(ind_big_bro, ind_lil_bro, stack_a, stack_b);
	else
		ft_combo_rarrb(ind_big_bro, ind_lil_bro, stack_a, stack_b);
}

void	ft_pablo_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_stacklast(*stack_a)->index;
	// printf("je passe par la\n");
	if (!ft_is_sorted(*stack_a))
	{
		while (i > 2)
		{
			write(1, "pb\n", 3);
			ft_push(stack_a, stack_b);
			i--;
		}
		if (!ft_is_sorted(*stack_a))
		{
			write(1, "sa\n", 3);
			ft_swap(stack_a);
		}
		if (*stack_b)
		{
			i = ft_stacklast(*stack_b)->index;
			while (i >= 0)
			{
				ft_make_best_combo(stack_a, stack_b);
				i--;
			}
		}
	}
	ft_make_order(stack_a);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *new;
	int	nbr;
	int i;

	i = 0;
	nbr = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (argv[++i])
	{
		if (!ft_atoi(&nbr, argv[i]))
			return (1); // free error
		new = ft_stacknew(nbr);
		if (!new || ft_is_duplicate(stack_a, nbr))
			return (1); //
		ft_stackadd_back(&stack_a, new);
	}
	ft_set_index(stack_a);
	// ft_putstack(stack_a);
	ft_pablo_sort(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	return (0);
}
