/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:02:58 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/29 14:28:12 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*tmp;

	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_stackadd_front(stack_dest, tmp);
	ft_set_index(*stack_dest);
	ft_set_index(*stack_src);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		ft_stackadd_back(&tmp, *stack);
		*stack = tmp;
		ft_set_index(*stack);
	}
}

void	ft_r_rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*stack)->next)
	{
		tmp1 = ft_stacklast(*stack);
		tmp2 = *stack;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		ft_stackadd_front(stack, tmp1);
		ft_set_index(*stack);
	}
}

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
		(*stack)->index = 0;
		(*stack)->next->index = 1;
	}
}
