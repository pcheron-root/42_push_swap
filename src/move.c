/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:02:58 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/25 01:32:53 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_set_index(t_stack *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        stack->index = i;
        stack = stack->next;
        i++;
    }
}

void    ft_push(t_stack **stack_src, t_stack **stack_dest)
{
    t_stack   *tmp;

    tmp = *stack_src;
    *stack_src = (*stack_src)->next;
    tmp->next = *stack_dest;
    *stack_dest = tmp;
    ft_set_index(stack_dest);
    ft_set_index(stack_src);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		ft_lstadd_back(&tmp, *stack);
		*stack = tmp;
		// (*stack)->previous = NULL;
		// (*stack)->next->previous = *stack;
		ft_set_index(*stack);
	}
}

void	ft_r_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next)
	{
		tmp = ft_lstlast(*stack);
		// tmp->previous->next = NULL;
		ft_lstadd_front(stack, tmp)
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
