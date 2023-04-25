/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:43:18 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/26 00:20:50 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_find_min(t_stack *stack)
{
    t_stack *min;

    min = stack;
    while (stack)
    {
        if (stack->nbr < min->nbr)
            min = stack;
        stack = stack->next;
    }
    return (min);
}

t_stack	*ft_find_max(t_stack *stack)
{
    t_stack *max;

    max = stack;
    while (stack)
    {
        if (stack->nbr > max->nbr)
            max = stack;
        stack = stack->next;
    }
    return (max);
}

int ft_find_big_brother(t_stack *stack, int nbr)
{
    int big_bro;
    int index;
    
    if (nbr > ft_find_max(stack)->nbr)
        return (ft_find_min(stack)->index);
    big_bro = INT_MAX;
    index = 0;
    while (stack)
    {
        if (stack->nbr > nbr && stack->nbr <= INT_MAX)
        {
            index = stack->index;
            big_bro = stack->nbr; 
        }
        stack = stack->next;
    }
    return (index);
}

int ft_find_best_score(t_stack *stack_a, t_stack *stack_b, int ind_big_bro, int ind_lil_bro)
{
    int rarb;
    int rrarrb;
    int rarrb;
    int rrarb;
    
    rarb = ft_max(ind_big_bro, ind_lil_bro);
    rrarrb = ft_max(ft_stacklast(stack_a)->index - ind_big_bro, ft_find_max(stack_b)->index - ind_lil_bro) + 1;
    rarrb = ind_big_bro + ft_stacklast(stack_b)->index - ind_lil_bro + 1;
    rrarb = ind_lil_bro + ft_stacklast(stack_a)->index - ind_big_bro + 1;
	return (ft_min(ft_min(rarb, rrarrb), ft_min(rarrb, rrarb)));
}

int ft_find_best_combo(int ind_big_bro, int ind_lil_bro, t_stack *stack_a, t_stack *stack_b)
{
    int rarb;
    int rrarrb;
    int rarrb;
    int rrarb;
    
    rarb = ft_max(ind_big_bro, ind_lil_bro);
    rrarrb = ft_max(ft_stacklast(stack_a)->index - ind_big_bro, ft_find_max(stack_b)->index - ind_lil_bro) + 1;
    rarrb = ind_big_bro + ft_stacklast(stack_b)->index - ind_lil_bro + 1;
    rrarb = ind_lil_bro + ft_stacklast(stack_a)->index - ind_big_bro + 1;
    if (rarb <= rrarb && rarb <= rrarrb && rarb <= rarrb)
        return (RARB);
    if (rrarrb <= rarb && rrarrb <= rrarb && rrarrb <= rarrb)
        return (RRARRB);
    if (rarrb <= rarb && rarrb <= rrarrb && rarrb <= rrarb)
        return (RARRB);
    return (RRARB);
}
