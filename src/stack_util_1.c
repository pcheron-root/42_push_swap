/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:02:51 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/26 01:11:40 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack   *ft_stacknew(int nbr)
{
    t_stack   *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->nbr = nbr;
    new->index = 0;
    new->next = NULL;
}

t_stack   *ft_stacklast(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void    ft_stackadd_back(t_stack **stack, t_stack *new)
{
    if (!(*stack))
        *stack = new;
    else
        ft_stacklast(*stack)->next = new;
}

void    ft_stackadd_front(t_stack **stack, t_stack *new)
{
    if (!new)
        return ;
    new->next = *stack;
    *stack = new;
    // if (!*stack)
    //     return ;
}

void    ft_stackclear(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

#include <stdio.h>
void	ft_putstack(t_stack *stack)
{
	printf("stack\n");
	while (stack)
	{
		printf("%d.%d\n", stack->nbr, stack->index);
		stack = stack->next;
	}
}
